#ifndef PKG2_H
#define PKG2_H

#include <QObject>
#include <QJSEngine>
#include <QQmlEngine>


class Pkg2: public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY sigName)
    Q_PROPERTY(QString href READ getHref WRITE setHref NOTIFY sigHref)
    Q_PROPERTY(QString file READ getFile WRITE setFile NOTIFY sigFile)
    Q_PROPERTY(QString version READ getVersion WRITE setVersion NOTIFY sigVersion)
    Q_PROPERTY(QString suffix READ getSuffix WRITE setSuffix NOTIFY sigSuffix)
    Q_PROPERTY(QString dir READ getDir WRITE setDir NOTIFY sigDir)
    Q_PROPERTY(QString color READ getColor WRITE setColor NOTIFY sigColor)
    Q_PROPERTY(QStringList deps READ getDeps WRITE setDeps)
    Q_PROPERTY(QStringList info READ getInfo WRITE setInfo)


    enum PkgRoles {
        NameRole = Qt::UserRole + 1,
        HrefRole, FileRole, VersionRole,
        SuffixRole, DirRole, ColorRole
    };

    QHash<int, QByteArray> roleNames() const;

public:
    Q_INVOKABLE void setName(QString newName);
    Q_INVOKABLE QString getName() const;

    Q_INVOKABLE void setHref(QString newHref);
    Q_INVOKABLE QString getHref() const;

    Q_INVOKABLE void setFile(QString newFile);
    Q_INVOKABLE QString getFile() const;

    Q_INVOKABLE void setVersion(QString newVersion);
    Q_INVOKABLE QString getVersion() const;

    Q_INVOKABLE void setSuffix(QString newSuffix);
    Q_INVOKABLE QString getSuffix() const;

    Q_INVOKABLE void setDir(QString newDir);
    Q_INVOKABLE QString getDir() const;

    Q_INVOKABLE void setColor(QString newColor);
    Q_INVOKABLE QString getColor() const;

    Q_INVOKABLE void setDeps(QStringList newDeps);
    Q_INVOKABLE QStringList getDeps() const;

    Q_INVOKABLE QStringList getInfo() const;
    Q_INVOKABLE void setInfo(QStringList newInfo);

    static QObject *MyPkgInit(QQmlEngine *engine, QJSEngine *scriptEngine);

    QVariant data(int role) const;

signals:
    void sigName(QString newName);
    void sigHref(QString newHref);
    void sigFile(QString newFile);
    void sigVersion(QString newVersion);
    void sigSuffix(QString newSuffix);
    void sigDir(QString newDir);
    void sigColor(QString newColor);

private:
    QString name, href, file, version, suffix, dir, color;
    QStringList deps, info;
};


#endif // PKG2_H
