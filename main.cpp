#include <QGuiApplication>
#include <QQmlApplicationEngine>
//EDIT: include the header
#include <QTranslator>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    //EDIT: create, load and install translator
    QTranslator translator;
    translator.load(":/translations/CS.qm");
    app.installTranslator(&translator);
    engine.retranslate();

    engine.load(url);
    return app.exec();
}
