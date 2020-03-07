#include "Status.h"

#include <QFile>
#include <QTextStream>

#define installed "INST"
#define failed    "FAIL"


void Status::add(QString name, Status::STATUS st) {
    if ( !list.contains(name) ) {
        list[name] = st;
        return;
    }

    if ( st == INSTALLED ) {
        list[name] = INSTALLED;
        return;
    }

}

int Status::size() const {
    return list.size();
}

void Status::load(QString file) {
    QString line;
    QString strStatus, name;
    STATUS status;

    QFile fd(file);
    if (fd.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&fd);
        QStringList st;
        while (!in.atEnd()) {
            line = in.readLine();
            st = line.split('\t');

            if (st.size() != 2) continue;
            strStatus = st.at(0);
            name = st.at(1);

            status = strToSTATUS(strStatus);
            if (status != NONE) add(name, status);
        }
    }
    fd.close();
}

bool Status::save(QString file)
{
    QString line;
    QString strStatus, name;
    STATUS status;

    QFile fd(file);
    if (fd.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&fd);
        QMap<QString,STATUS>::iterator i;

        for (i = list.begin(); i != list.end(); ++i)
        {
            status = i.value();
            i.key();
            if (status == INSTALLED) {out << installed "\t" << i.key() << "\n";}
            else if (status == FAILED) {out << failed "\t" << i.key() << "\n";}
        }
    } else return false;
    fd.close();
    return true;
}

Status::STATUS Status::get(QString name) const {
    if (!list.contains(name))
        return NONE;
    return list.value(name);
}

Status::STATUS Status::strToSTATUS(const QString strStatus) {
    if (strStatus == installed) return INSTALLED;
    if (strStatus == failed) return FAILED;
    return NONE;
}
