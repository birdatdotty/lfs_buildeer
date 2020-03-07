#ifndef STATUS_H
#define STATUS_H

#include <QObject>
#include <QMap>

class Status {
public:
    enum STATUS {INSTALLED, FAILED, NONE};
    explicit Status (){};
    void add(QString name, STATUS st);

    int size() const;
    STATUS get(QString name) const;

    void load(QString file);
    bool save(QString file);

private:
    QMap<QString,STATUS> list;
    QString file;

    STATUS strToSTATUS(const QString strStatus);
};

#endif // STATUS_H
