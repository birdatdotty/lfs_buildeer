#include "BuildPkg.h"

#include <QDir>

BuildPkg::BuildPkg(QObject *parent) : QObject(parent)
{

}

void BuildPkg::extract(Pkg2 *pkg)
{
//    qInfo() << __LINE__;
//    QString url = QString::fromStdString(pkg->getHref());
//    QString file = QString::fromStdString(pkg->getFile());

//    cmd("wget", QStringList() << "-c" << url << wget_opts(file));
//    cmd("tar", QStringList() << "-xf" << wget_dir + QDir::separator() + file);
}

void BuildPkg::make(Pkg2 *pkg)
{

}

void BuildPkg::cmd(QString cmd, QStringList opts)
{

}
