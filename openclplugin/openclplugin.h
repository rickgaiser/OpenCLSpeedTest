#ifndef OPENCLPLUGIN_H
#define OPENCLPLUGIN_H

#include <QQmlExtensionPlugin>

class OpenCLPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // OPENCLPLUGIN_H

