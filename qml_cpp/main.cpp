#include <QApplication>
#include <QQmlApplicationEngine>
#include <receiver.h>
#include <QQmlContext>
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QQmlApplicationEngine *engine;
    engine=new QQmlApplicationEngine(qApp);
    QQmlContext * context=engine->rootContext();
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    Receiver receiver;
    engine->load(url);
    engine->rootContext()->setContextProperty("receiver",&receiver);

    return app.exec();
}
