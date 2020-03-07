#include "Step2.h"
#include "config.h"


Step2::Step2(QObject *parent)
  : QObject(parent),
    color(NONE_COLOR),
    steps({1,2,3,4,5})
{

}

// name:
void Step2::setName(QString newName) {
    name = newName;
    sigName(name);
}
QString Step2::getName() const {
    return name;
}

// pkg:
void Step2::setPkg(QString newPkg) {
    pkg = newPkg;
    sigPkg(pkg);
}
QString Step2::getPkg() const {
    return pkg;
}

// script:
void Step2::setScript(QString newScript) {
    script = newScript;
    sigScript(script);
}
QString Step2::getScript() const {
    return script;
}

// clolor:
void Step2::setColor(QString newColor) {
    color = newColor;
    sigColor(newColor);
}
QString Step2::getColor() {
    return color;
}

// status:
void Step2::setStatus(Step2::Status st) {
    switch (st) {
      case NONE: setColor(NONE_COLOR); break;
      case INSTALLED: setColor(INSTALLED_COLOR); break;
      case FAILED: setColor(FAILED_COLOR); break;
      case INPROCESS: setColor(INPROCESS_COLOR); break;
    }

    status = st;
    sigStatus(st);
}
Step2::Status Step2::getStatus() {
    return status;
}

// steps:
void Step2::setSteps(QList<int> newSteps) {
    steps = newSteps;
}
QList<int> Step2::getSteps() const {
    return steps;
}

void Step2::setSBU(QString newSBU)
{
    SBU = newSBU;
    sigSBU(SBU);
}
QString Step2::getSBU() const
{
    return SBU;
}
