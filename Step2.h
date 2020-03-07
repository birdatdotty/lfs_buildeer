#ifndef STEP2_H
#define STEP2_H

#include <QObject>

class Step2 : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QString name READ getName WRITE setName NOTIFY sigName)
  Q_PROPERTY(QString pkg READ getPkg WRITE setPkg NOTIFY sigPkg)
  Q_PROPERTY(QString script READ getScript WRITE setScript NOTIFY sigScript)
  Q_PROPERTY(QString statusColor WRITE setColor READ getColor NOTIFY sigColor)
  Q_PROPERTY(Status status WRITE setStatus READ getStatus NOTIFY sigStatus)
  Q_PROPERTY(QList<int> steps READ getSteps WRITE setSteps NOTIFY sigSteps)
  Q_PROPERTY(QString sbu WRITE setSBU READ getSBU NOTIFY sigSBU)

  Q_ENUMS(Status)

  public:
    explicit Step2(QObject *parent = nullptr);
    enum Status{NONE, INSTALLED, FAILED, INPROCESS};

    Q_INVOKABLE void setName(QString newName);
    Q_INVOKABLE QString getName() const;

    Q_INVOKABLE void setPkg(QString newPkg);
    Q_INVOKABLE QString getPkg() const;

    Q_INVOKABLE void setScript(QString newScript);
    Q_INVOKABLE QString getScript() const;

    Q_INVOKABLE void setColor(QString newColor);
    Q_INVOKABLE QString getColor();

    Q_INVOKABLE void setStatus(Status st);
    Q_INVOKABLE Status getStatus();

    Q_INVOKABLE void setSteps(QList<int> newSteps);
    Q_INVOKABLE QList<int> getSteps() const;

    Q_INVOKABLE void setSBU(QString newSBU);
    Q_INVOKABLE QString getSBU() const;

  signals:
    void sigName(QString name);
    void sigPkg(QString pkg);
    void sigScript(QString script);
    void sigColor(QString color);
    void sigStatus(Status status);
    void sigSteps(QList<int> steps);
    void sigSBU(QString SBU);

  private:
    QString name, pkg, script, color, SBU;
    QList<int> steps;
    Status status;
};

#endif // STEP2_H
