#include "openclplugin.h"
#include "opencldata.h"

#include <QtQml>

void OpenCLPlugin::registerTypes(const char *uri)
{
    // @uri OpenCLSpeedTest
    Q_ASSERT(uri == QLatin1String("OpenCLSpeedTest"));
    qmlRegisterType<OpenCLData>(uri, 1, 0, "OpenCLData");
}


