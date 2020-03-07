#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Model.h"
#include "pkgs2.h"

#include "Install.h"
#include "Step2.h"

#include <QThread>
#include "InstallPkg.h"


InstallPkg *installPkg = new InstallPkg();



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QThread *thread = new QThread();

    installPkg->moveToThread(thread);
    thread->start();


    qmlRegisterType<Pkg2>("Pkgs", 1,0, "Pkg");
    qmlRegisterType<Pkgs2>("Pkgs", 1,0, "Pkgs");

    qmlRegisterType<Install>("InstallList", 1,0, "Install");
    qmlRegisterType<Step2>("InstallList", 1,0, "Step");

    qmlRegisterSingletonType(QUrl("qrc:/Pkgs2.qml"), "Util", 1,0, "Pkgs2");
    qmlRegisterSingletonType(QUrl("qrc:/Model2.qml"), "Step2", 1,0, "Step2");



    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl) {
                QCoreApplication::exit(-1);
            }
        }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
