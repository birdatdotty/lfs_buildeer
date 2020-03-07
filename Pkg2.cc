#include "Pkg2.h"

QHash<int, QByteArray> Pkg2::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[HrefRole] = "href";
    roles[VersionRole] = "version";
    return roles;
}

// name:
void Pkg2::setName(QString newName) {name = newName; sigName(newName);}
QString Pkg2::getName() const {return name;}

// href:
void Pkg2::setHref(QString newHref) {href = newHref; sigHref(newHref);}
QString Pkg2::getHref() const {return href;}

// file:
void Pkg2::setFile(QString newFile) {file = newFile; sigFile(newFile);}
QString Pkg2::getFile() const {return file;}

// version:
void Pkg2::setVersion(QString newVersion) {version = newVersion; sigVersion(newVersion);}
QString Pkg2::getVersion() const {return version;}

// suffix:
void Pkg2::setSuffix(QString newSuffix) {suffix = newSuffix; sigSuffix(newSuffix);}
QString Pkg2::getSuffix() const {return suffix;}

// dir:
QString Pkg2::getDir() const {return dir;}
void Pkg2::setDir(QString newDir) {dir = newDir; sigDir(newDir);}

// color:
QString Pkg2::getColor() const {return color;}
void Pkg2::setColor(QString newColor) {color = newColor; sigColor(newColor);}

// deps:
void Pkg2::setDeps(QStringList newDeps) {deps = newDeps;}
QStringList Pkg2::getDeps() const {return deps;}

// info:
void Pkg2::setInfo(QStringList newInfo) {info = newInfo;}
QStringList Pkg2::getInfo() const {return info;}

QObject *Pkg2::MyPkgInit(QQmlEngine *engine, QJSEngine *scriptEngine)
{
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  Pkg2* pkg2 = new Pkg2();
  pkg2->setDir("23 sdsd");
  pkg2->setName("MyPkgInit");

  return pkg2;
}

QVariant Pkg2::data(int role) const {
  switch (role) {
    case Pkg2::NameRole: return name;
    case Pkg2::HrefRole: return href;
    case Pkg2::VersionRole: return version;
    case Pkg2::SuffixRole: return suffix;
  }

  return QVariant();
}
