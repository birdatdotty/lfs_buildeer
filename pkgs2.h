#ifndef PKGS2_H
#define PKGS2_H

#include <QAbstractItemModel>
#include <QQmlListProperty>
#include <QJSEngine>
//#include <QDebug>

class Pkg2;

class Pkgs2 : public QAbstractListModel
{
    Q_OBJECT
    enum PkgRoles {
        NameRole = Qt::UserRole + 1,
        HrefRole, FileRole, VersionRole,
        SuffixRole, DirRole, ColorRole
    };
    QHash<int, QByteArray> roleNames() const;

    // Добавим возможность добавления элементов (QML)
    Q_PROPERTY(QQmlListProperty<Pkg2> pkgList READ pkgList)
    Q_CLASSINFO("DefaultProperty", "pkgList")

public:
    explicit Pkgs2(QObject *parent = nullptr);
    static QObject *MyPkgsInit(QQmlEngine *engine, QJSEngine *scriptEngine);

    QQmlListProperty<Pkg2> pkgList();
    void appendPkg(Pkg2 *value);
    int pkgCount() const;
    Pkg2 *pkg(int index) const;
    void clearPkg();


private:
    static void appendPkg(QQmlListProperty<Pkg2> *list, Pkg2 *value);
    static int pkgCount(QQmlListProperty<Pkg2> *list);
    static Pkg2 *pkg(QQmlListProperty<Pkg2> *list, int index);
    static void clearPkg(QQmlListProperty<Pkg2> *list);

    QList<Pkg2*> pkgs;

    //////////////////////// abstract: ////////////////////////
public:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &/*parent*/) const;

};

#endif // PKGS2_H
