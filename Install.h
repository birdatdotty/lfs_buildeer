#ifndef INSTALL_H
#define INSTALL_H

#include <QObject>
#include <QProcess>
#include <QQmlListProperty>

#include "Step2.h"
#include "pkgs2.h"
#include <QDebug>
#include <QDir>
#include <QAbstractListModel>

class Status;


class Install : public QAbstractListModel/*QObject*/
{
    Q_OBJECT

    // Добавим возможность добавления элементов (QML)
    Q_PROPERTY(QQmlListProperty<Step2> stepList READ stepList)
    Q_CLASSINFO("DefaultProperty", "stepList")

    Q_PROPERTY(QStringList wget WRITE setWget)
    Q_PROPERTY(QStringList bash WRITE setBash)
    Q_PROPERTY(QString wget_out WRITE setWgetOut)
    Q_PROPERTY(QStringList tar WRITE setTar)
    Q_PROPERTY(QString sourcesDir WRITE setSources)
    Q_PROPERTY(QString buildDir WRITE setBuildDir)
    Q_PROPERTY(QString scriptsDir WRITE setScriptsDir READ getScriptsDir NOTIFY sigScriptsDir)
    Q_PROPERTY(QString tgt WRITE setTgt READ getTgt NOTIFY sigTgt)
    Q_PROPERTY(QString lfs WRITE setLfs READ getLfs NOTIFY sigLfs)
    Q_PROPERTY(Pkgs2* pkgs WRITE setPkgs)
    Q_PROPERTY(bool doInstall READ getDoInstall NOTIFY sigDoInstall)
    Q_PROPERTY(QString selected READ getSelected NOTIFY selectedChanged)
    Q_PROPERTY(QString buildRoot READ getBuildRoot WRITE setBuildRoot NOTIFY sigBuildRoot)
    QString getSelected() {return selectedPkgName;}


public:
    explicit Install(QObject *parent = nullptr);

    enum Roles {
        NameRole = Qt::UserRole + 1,
        PkgRole, ScriptRole, StatusColor,
        SetStatusColor
    };
    void setScriptsDir(QString newScriptsDir);
    QString getScriptsDir() const;

public:
    QQmlListProperty<Step2> stepList();

    void appendStep(Step2* step);
    int stepCount() const;
    Step2* step(int i) const;
    void clearSteps();

private:
    static void appendStep(QQmlListProperty<Step2>*, Step2*);
    static int stepCount(QQmlListProperty<Step2>*);
    static Step2* step(QQmlListProperty<Step2>*, int);
    static void clearSteps(QQmlListProperty<Step2>*);


signals:
    void sigScriptsDir(QString scriptsDir);
    void msg(QString txt);
    void sigDoInstall(bool);
    void selectedChanged(QString selectedPkgName);
    void sigBuildRoot(QString buildRoot);
    void sigTgt(QString tgt);
    void sigLfs(QString tgt);

private:
    QList<Step2*> steps;
    QString scriptsDir;
    Pkgs2 *pkgs;
    int n = 0;
    QStringList wget, tar;
    bool doInstall;
    QString sourcesDir;

    Status *status;
    QString pkgListFile;


public:
    void setWget(QStringList newWget);
    void setWgetOut(QString neWgetOut);
    void setBash(QStringList newBash);
    void setTar(QStringList newTar);
    void setSources(QString newSources);
    virtual int rowCount(const QModelIndex &/*parent*/) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;
    Q_INVOKABLE void setN(int N);
    Q_INVOKABLE void install();
    Q_INVOKABLE void setPkgs(Pkgs2* pkgs);

    Q_INVOKABLE Pkg2 *getPkgByName(QString pkgName) const;
    Q_INVOKABLE QString getBuildDir() const;

    Q_INVOKABLE QString getBashHash(QString pkgName) const;
    Q_INVOKABLE QString getBash() const;

    Q_INVOKABLE void setDoInstall(bool newDoInstall );
    Q_INVOKABLE bool getDoInstall();

    Q_INVOKABLE void setTgt(QString newTgt ) { tgt = newTgt; sigTgt(newTgt); }
    Q_INVOKABLE QString getTgt() const { return tgt; }

    Q_INVOKABLE void setLfs(QString newLfs ) { lfs = newLfs; sigLfs(newLfs); }
    Q_INVOKABLE QString getLfs() const { return lfs; }

    Q_INVOKABLE void setBuildRoot(QString newBuildRoot) {buildRoot = newBuildRoot;sigBuildRoot(newBuildRoot);}
    Q_INVOKABLE QString getBuildRoot() {return buildRoot;}


  private:
    std::map<QString,Pkg2*> allPkgs;
    QString buildDir,
            wget_out,
            bash,
            buildRoot,
            lfs,
            tgt;

    QProcess process;
    QString selectedPkgName;

    bool pkgExist, buildDirExist;

    void setBuildDir(QString newBuildDir);
    void setStatusFromFile();


private slots:
    void msgFromInstallPkg(QString txt);
    void setStatus(Step2::Status status, int curIndex);

public slots:
    void finished(bool status);
};

#endif // INSTALL_H
