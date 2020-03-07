#include "pkgs2.h"
#include "Pkg2.h"

QHash<int, QByteArray> Pkgs2::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[HrefRole] = "href";
    roles[VersionRole] = "version";
    roles[SuffixRole] = "suffix";

    return roles;
}

Pkgs2::Pkgs2(QObject *parent)
    : QAbstractListModel(parent)
{
}

QObject *Pkgs2::MyPkgsInit(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Pkgs2* pkg2 = new Pkgs2();

    return pkg2;
}


QQmlListProperty<Pkg2> Pkgs2::pkgList()
{
    return QQmlListProperty<Pkg2>(this, this,
                                  &Pkgs2::appendPkg,
                                  &Pkgs2::pkgCount,
                                  &Pkgs2::pkg,
                                  &Pkgs2::clearPkg);
}

void Pkgs2::appendPkg(Pkg2 *pkg)
{
    pkgs.append(pkg);
}

int Pkgs2::pkgCount() const
{
    return pkgs.size();
}

Pkg2 *Pkgs2::pkg(int i) const
{
    return pkgs.at(i);
}

void Pkgs2::clearPkg()
{
    pkgs.clear();
}

void Pkgs2::appendPkg(QQmlListProperty<Pkg2> *list, Pkg2 *el)
{
    reinterpret_cast< Pkgs2* >(list->data)->appendPkg(el);
}

int Pkgs2::pkgCount(QQmlListProperty<Pkg2> *list)
{
    return reinterpret_cast< Pkgs2* >(list->data)->pkgCount();
}

Pkg2 *Pkgs2::pkg(QQmlListProperty<Pkg2> *list, int i)
{
    return reinterpret_cast< Pkgs2* >(list->data)->pkg(i);
}

void Pkgs2::clearPkg(QQmlListProperty<Pkg2> *list)
{
    return reinterpret_cast< Pkgs2* >(list->data)->clearPkg();
}

QVariant Pkgs2::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) return QVariant::fromValue(pkgs.at(index.row()));
    if (role > Qt::DisplayRole) {
        Pkg2* tmp = pkgs.at(index.row());
        return tmp->data(role);
    }

    return QVariant();
}

int Pkgs2::rowCount(const QModelIndex &) const {return pkgCount();}

