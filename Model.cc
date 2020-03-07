#include "Model.h"

#include <QDebug>

Model::Model(QQuickItem *parent)
    : QQuickItem(parent)
{

}

QString Model::getSelected() {
    return selected;
}

void Model::setSelected(QString selected) {
    this->selected = selected; selectedChanged(selected);
}

QObject *Model::MyApiInit(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Model *example = new Model();
    return example;
}


void Model::click()
{
    qInfo() << "1111";
    msg("sasdfdsf\n");

    qInfo() << "2222";
}
