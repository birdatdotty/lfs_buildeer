#include "InstallPkg.h"

#include "Step2.h"
#include "pkgs2.h"
#include "Install.h"
#include <QFileDevice>
#include <QFile>
#include <QDir>

InstallPkg::InstallPkg(QObject *parent): QObject(parent) {
    connect(&process, &QProcess::readyReadStandardOutput,
            this, &InstallPkg::outProc);
    connect(&process, &QProcess::readyReadStandardError,
            this, &InstallPkg::errProc);
    connect(&process,
            QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this,
            &InstallPkg::onInstallFinished,
            Qt::DirectConnection);
}

void InstallPkg::setWget(QStringList newWget) {
    wget = newWget.at(0);
    for(int i = 1; i < newWget.size(); i++)
        wgetOther << newWget[i];
}

void InstallPkg::setWgetOut(QString neWgetOut) {
    wget_out = neWgetOut;
}

void InstallPkg::setTar(QStringList newTar)
{
    tar = newTar.at(0);
    for (int i = 1; i < newTar.size(); i++)
        tarOther << newTar[i];
}

void InstallPkg::setSources(QString newSources)
{
    sourcesDir = newSources;
}

void InstallPkg::setBuildDir(QString newBuildDir) {
    buildDir = newBuildDir;
}

void InstallPkg::install(const Pkg2 *curPkg, Step2* curStep, const Install* curInstall, int n)
{
    savePkg = curPkg;
    saveStep = curStep;
    saveInstall = curInstall;
    index = n;
    const QString pkgName = curStep->getPkg();
    msg("Установка " + curStep->getName() + "\n\n");
    needsSteps.append( curStep->getSteps() );

    setStatus(Step2::INPROCESS, index);
    switchCurInstallStep();
}

void InstallPkg::onInstallFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if (exitStatus == QProcess::CrashExit) {/* Надо выйти, громко хлопнув за собой двеью */}
    if (exitCode != 0) {installFinished(exitCode); return;}


    startCurInstallStep();
}

void InstallPkg::startCurInstallStep() {
    if (installStepList.isEmpty()) {
        installStep++;
        switchCurInstallStep();

        return;
    }
    InstallCmd cmd = installStepList.dequeue();
    InstallPkg::cmd(cmd.cmd, cmd.opts);

}

void InstallPkg::switchCurInstallStep() {
  if (installStepList.isEmpty()) {
    if (needsSteps.size() > 0) {
      qDebug() << __LINE__ << needsSteps;
      installStep = needsSteps.dequeue();
      qDebug() << __LINE__  << needsSteps;
    }
    else
    {
        installFinished();
        return;
    }

  }

  switch (installStep) {
    case 1: install1(); return;
    case 2: install2(); return;
    case 3: install3(); return;
    case 4: install4(); return;
    case 5: install5(); return;
    default: installFinished();
  }
}

void InstallPkg::install1() {
    QStringList depsPkg = savePkg->getDeps();
    msg("Скачивание...");

    // download curPkg & depsPkg
    download(savePkg);
    for (QString depName: savePkg->getDeps()) {
        download(saveInstall->getPkgByName(depName));
    }
    installStep = 1;
    startCurInstallStep();
}

void InstallPkg::install2()
{
    qDebug() << "void InstallPkg::install2()";
    QStringList depsPkg = savePkg->getDeps();
    msg("Распаковка...");

    QDir::setCurrent(buildDir);

    extract(savePkg);
    for (QString pkgName: depsPkg)
        extract(saveInstall->getPkgByName(pkgName));

    installStep = 2;
    startCurInstallStep();

}

void InstallPkg::install3()
{
    qDebug() << "void InstallPkg::install3()";
    msg("install3: " + saveInstall->getScriptsDir() + QDir::separator() + saveStep->getScript());

    msg(saveInstall->getBashHash(savePkg->getName()));
    QStringList deps = savePkg->getDeps();
    QStringList info = savePkg->getInfo();

    QFile oldFile(saveInstall->getScriptsDir() + QDir::separator() + saveStep->getScript());
    QString bodyOldFile;
    if ( oldFile.open(QIODevice::ReadOnly | QIODevice::Text) )
        while (!oldFile.atEnd()) {
            QByteArray line = oldFile.readLine();
            bodyOldFile += line;
        }
    oldFile.close();

    QFile newFile( saveInstall->getBuildDir() + QDir::separator() + saveStep->getScript() );
    if ( newFile.open(QIODevice::WriteOnly | QIODevice::Text) )
      {
        QTextStream out(&newFile);
        out << saveInstall->getBash() << "\n";
        out << saveInstall->getBashHash(savePkg->getName()) << "\n";
        for (QString dep: deps)
            out << saveInstall->getBashHash(dep) << "\n";
        for (QString pkgInfo: info)
            out << saveInstall->getBashHash(pkgInfo) << "\n";

        out << bodyOldFile << "\n";
      }

    newFile.close();
    newFile.setPermissions(QFile::ReadOwner|
                           QFile::WriteOwner|
                           QFile::ExeOwner|
                           QFile::ReadGroup|
                           QFile::ExeGroup|
                           QFile::ReadOther|
                           QFile::ExeOther);

    startCurInstallStep();
}

void InstallPkg::install4()
{
    qDebug() << "void InstallPkg::install4()";
    QDir dir;
    QString tmpDir = savePkg->getName()+"-build";
    dir.setPath(buildDir);
    dir.mkdir(buildDir);
    dir.mkdir(savePkg->getName()+"-build");
    dir.cd(tmpDir);
    dir.setCurrent(dir.path());
    installStepList.enqueue({"/bin/sh", QStringList() << "../" + saveStep->getScript()});

    startCurInstallStep();
}

void InstallPkg::install5() {
    QDir().setCurrent(buildDir);
    qDebug() << "void InstallPkg::install5()";
    qDebug() << "QDir().currentPath():" << QDir().currentPath();
    QDir(savePkg->getName()+"-build")
        .removeRecursively();

    QDir(savePkg->getDir())
        .removeRecursively();

    startCurInstallStep();
}

void InstallPkg::installFinished(int exitCode)
{
    needsSteps.clear();
    QDir::setCurrent(buildDir);

    if (exitCode == 0) {
        setStatus(Step2::INSTALLED, index);
        doInstall(false);
    }
    else
    {
        setStatus(Step2::FAILED, index);
        doInstall(false);
    }

}

void InstallPkg::cmd(QString cmd, QStringList opts)
{
    process.start(cmd, opts);
}

void InstallPkg::download(const Pkg2 *pkg)
{
    installStepList.enqueue({wget,
                             QStringList() << wgetOther << pkg->getHref()
                                           << wget_out << sourcesDir + QDir::separator() + pkg->getFile()});
}

void InstallPkg::extract(const Pkg2 *pkg)
{
    QDir dir = QDir::root();

    dir.setCurrent(buildDir);
    QString extractDit = buildDir + QDir::separator() + pkg->getDir();
    if (QDir(extractDit).exists())
        QDir(extractDit).removeRecursively();

    installStepList.enqueue({
        tar,
        QStringList() << tarOther
                      << sourcesDir + QDir::separator() + pkg->getFile()
    });
}

void InstallPkg::outProc()
{
  QString str = process.readAllStandardOutput();
  if (str.size() > 0)
    msg(str);
}

void InstallPkg::errProc()
{
    QString out = process.readAllStandardError();

    error(out);
}

void InstallPkg::error(QString cmd)
{
    error(QStringList(cmd));
}

void InstallPkg::error(QStringList list)
{
  for (QString str: list)
    msg(str);
}

void InstallPkg::info(QString cmd)
{
  info(QStringList(cmd));
}

void InstallPkg::info(QStringList list)
{
  for (QString str: list)
    {
      QStringList lines = str.split('\n');
      for (QString line: lines)
        msg(str);
    }
}
