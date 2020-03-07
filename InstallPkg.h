#ifndef INSTALLPKG_H
#define INSTALLPKG_H

#include "Step2.h"
#include "pkgs2.h"
#include "Pkg2.h"

#include <QObject>
#include <QProcess>

#include <queue>
#include <QQueue>

class Install;

class InstallPkg: public QObject
{
    Q_OBJECT
    struct InstallCmd {
        QString cmd;
        QStringList opts;
    };

public:
    InstallPkg(QObject *parent = nullptr);

    void setWget(QStringList newWget);
    void setWgetOut(QString neWgetOut);
    void setTar(QStringList newTar);
    void setSources(QString newSources);
    void setBuildDir(QString newBuildDir);

signals:
    void msg(QString txt);
    void doInstall(bool fin);
    void setStatus(Step2::Status status, int index);

private:
    QProcess process;
    int installNumber;
    QString buildDir,
        wget,
        wget_out,
        tar,
        tar_out,
        sourcesDir,
        scriptsDir;
    int index;
    QStringList tarOther, wgetOther;

    void cmd(QString cmd, QStringList opts);
    void download(const Pkg2 *pkg);
    void extract(const Pkg2 *pkg);
    void outProc();
    void errProc();
    void error(QString cmd);
    void error(QStringList list);
    void info(QString cmd);
    void info(QStringList list);

  public slots:
    void install(const Pkg2* curPkg, Step2* curStep, const Install* curInstall, int n);
    void install1();
    void install2();
    void install3();
    void install4();
    void install5();
    void installFinished(int exitCode = 0);



  private:
    void startCurInstallStep();
    void switchCurInstallStep();

  private slots:
    void onInstallFinished(int exitCode, QProcess::ExitStatus exitStatus);

  // save vars for install:
  private:
    const Pkg2* savePkg;
    const Step2* saveStep;
    const Install* saveInstall;

    int installStep;
    QQueue<InstallCmd> installStepList;
    QQueue<int> needsSteps;
};


extern InstallPkg *installPkg;

#endif // INSTALLPKG_H
