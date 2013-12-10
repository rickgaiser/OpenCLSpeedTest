#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>

#include "opencldata.h"


int
main(int argc, char *argv[])
{
  OpenCLData opencl;

  QGuiApplication app(argc, argv);
  app.setApplicationDisplayName("OpenCL Speed Tester");

  QQuickView view;
  view.engine()->rootContext()->setContextProperty("opencl", &opencl);
  view.setSource(QUrl("qrc:/qml/main.qml"));
  view.show();

  return app.exec();
}
