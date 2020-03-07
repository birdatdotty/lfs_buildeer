#ifndef MODEL_H
#define MODEL_H

#include <QAbstractItemModel>
#include <QObject>
#include <QQuickItem>

class Model : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString selected READ getSelected WRITE setSelected NOTIFY selectedChanged)

public:
    explicit Model(QQuickItem *parent = nullptr);
    Q_INVOKABLE QString getSelected();
    Q_INVOKABLE void setSelected(QString selected);

    static QObject *MyApiInit(QQmlEngine *engine, QJSEngine *scriptEngine);


signals:
    void msg(QString txt);
    void selectedChanged(QString selected);
    void selectedKgs();

public slots:
    Q_INVOKABLE void click();

private:
    QString selected;
};

#endif // MODEL_H
