#include "Install.h"
#include "InstallPkg.h"

#include "Status.h"

Install::Install(QObject *parent)
  : QAbstractListModel(parent),
    doInstall(false),
    status(new Status),
    pkgExist(false), buildDirExist(false)

{
    connect(installPkg, &InstallPkg::msg,
            this, &Install::msgFromInstallPkg);

    connect(installPkg, &InstallPkg::doInstall,
            this, &Install::setDoInstall);
    connect(installPkg, &InstallPkg::setStatus,
            this, &Install::setStatus);
}

void Install::setScriptsDir(QString newScriptsDir) {
    scriptsDir = newScriptsDir;
    sigScriptsDir(scriptsDir);
}
QString Install::getScriptsDir() const {
    return scriptsDir;
}


QQmlListProperty<Step2> Install::stepList()
{
    return QQmlListProperty<Step2>(this, this,
                                   &Install::appendStep,
                                   &Install::stepCount,
                                   &Install::step,
                                   &Install::clearSteps);
}

void Install::appendStep(Step2 *step)
{
    steps.append(step);
}

int Install::stepCount() const
{
    return steps.size();
}

Step2 *Install::step(int i) const
{
    return steps.at(i);
}

void Install::clearSteps()
{
    steps.clear();
}

void Install::appendStep(QQmlListProperty<Step2> *list, Step2 *el)
{
    reinterpret_cast< Install* >(list->data)->appendStep(el);
}

int Install::stepCount(QQmlListProperty<Step2> *list)
{
    return reinterpret_cast< Install* >(list->data)->stepCount();
}

Step2* Install::step(QQmlListProperty<Step2> *list, int i)
{
    return reinterpret_cast< Install* >(list->data)->step(i);
}

void Install::clearSteps(QQmlListProperty<Step2> *list)
{
    return reinterpret_cast< Install* >(list->data)->clearSteps();
}

void Install::setWget(QStringList newWget) {
    wget = newWget;
    installPkg->setWget(newWget);
}
void Install::setWgetOut(QString newWgetOut) {
    wget_out = newWgetOut;
    installPkg->setWgetOut(newWgetOut);
}
void Install::setBash(QStringList newBash) {
    bash = newBash.join("\n");
}
void Install::setTar(QStringList newTar) {
    tar = newTar;
    installPkg->setTar(newTar);
}

void Install::setSources(QString newSources) {
    sourcesDir = newSources;
    installPkg->setSources(newSources);
}

int Install::rowCount(const QModelIndex &) const {return stepCount();}

QVariant Install::data(const QModelIndex &index, int role) const {
    if (role == NameRole) return steps.at(index.row())->getName();
    if (role == ScriptRole) return steps.at(index.row())->getScript();
    if (role == PkgRole) return steps.at(index.row())->getPkg();
    if (role == StatusColor) return steps.at(index.row())->getColor();
    return QVariant();
}

QHash<int, QByteArray> Install::roleNames() const {
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[NameRole] = "name";
    roles[ScriptRole] = "script";
    roles[PkgRole] = "pkg";
    roles[StatusColor] = "statusColor";

    return roles;
}

void Install::setN(int N) {
    n = N;
    selectedPkgName = steps.at(n)->getName();

    selectedChanged(selectedPkgName);
}

void Install::install() {
    setDoInstall(true);
    Step2* cur = steps.at(n);
    const QString pkgName = cur->getPkg();
    const Pkg2* curPkg = allPkgs[pkgName];

    dataChanged(index(n),index(n));
    dataChanged(QModelIndex(),QModelIndex());

    emit installPkg->install(curPkg, cur, this, n);
}

void Install::setPkgs(Pkgs2 *pkgs) {
    this->pkgs = pkgs;
    int pkgs_size = pkgs->rowCount(QModelIndex());
    for (int i = 0; i < pkgs_size; i++)
    {
        Pkg2* pkg = qvariant_cast<Pkg2*>(pkgs->index(i).data());
        const QString name = pkg->getName();
        allPkgs[name] = pkg;
    }
    setN(0);
    pkgExist = true;
    setStatusFromFile();
}

Pkg2 *Install::getPkgByName(QString pkgName) const
{
    return allPkgs.at(pkgName);
}

QString Install::getBuildDir() const {
    return buildDir;
}

QString Install::getBashHash(QString pkgName) const
{
    QString tpl = "declare -A %1=( [\"name\"]=\"%1\" [\"dir\"]=\"%2\" [\"version\"]=\"%3\" )";
    const Pkg2 *pkg = allPkgs.at(pkgName);

    return tpl.arg(pkg->getName(), pkg->getDir(), pkg->getVersion());
}

QString Install::getBashHashAsPkg(QString pkgName) const
{
    QString tpl = "declare -A pkg=( [\"name\"]=\"%1\" [\"dir\"]=\"%2\" [\"version\"]=\"%3\" )";
    const Pkg2 *pkg = allPkgs.at(pkgName);

    return tpl.arg(pkg->getName(), pkg->getDir(), pkg->getVersion());
}

QString Install::getBash() const {
    return bash;
}

bool Install::getDoInstall() {
    return doInstall;
}

void Install::setDoInstall(bool newDoInstall) {
    doInstall = newDoInstall; sigDoInstall(newDoInstall);
}

void Install::setBuildDir(QString newBuildDir) {
    buildDir = newBuildDir;
    installPkg->setBuildDir(newBuildDir);
    buildDirExist = true;

    setStatusFromFile();
}

void Install::setStatusFromFile()
{
    qInfo() << "void Install::setStatusFromFile()";
    if (pkgExist && buildDirExist)
    {
        pkgListFile = buildRoot + QDir::separator() + "pkg.list";
        status->load(pkgListFile);

        int size = steps.count();
        for (int i = 0; i < size; i++) {
//            qInfo() << __LINE__ << steps.at(i)->getName();
            QString name = steps.at(i)->getName();
            Status::STATUS st = status->get(name);
            if (st != Status::NONE) {
                qInfo() << name << st;
                if (st == Status::INSTALLED)
                    setStatus(Step2::INSTALLED, i);
                else
                if (st == Status::FAILED)
                    setStatus(Step2::FAILED, i);
            }
        }
    }
}

void Install::msgFromInstallPkg(QString txt)
{
    msg(txt);
}

void Install::setStatus(Step2::Status stepStatus, int curIndex) {
    // 0 success
    // 1 error

    const QString name = steps.at(curIndex)->getName();
    if (stepStatus == Step2::INSTALLED) {
        status->add(name, Status::INSTALLED);
        status->save(pkgListFile);
    }
    else
    if (stepStatus == Step2::FAILED) {
        status->add(name, Status::FAILED);
        status->save(pkgListFile);
    }

    steps[curIndex]->setStatus(stepStatus);
    dataChanged(index(curIndex),index(curIndex));
}

void Install::finished(bool status) {setDoInstall(!status);}
