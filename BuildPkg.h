#ifndef BUILDPKG_H
#define BUILDPKG_H

#include <QObject>
#include <QProcess>

#include "pkgs2.h"

class BuildPkg : public QObject
{
    Q_OBJECT
public:
    explicit BuildPkg(QObject *parent = nullptr);
    void extract(Pkg2 *pkg);
    void make(Pkg2 *pkg);
    void cmd(QString cmd, QStringList opts);

signals:

private:
    QProcess process;

};

#endif // BUILDPKG_H
