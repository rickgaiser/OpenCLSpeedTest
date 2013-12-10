#ifndef OPENCLDATA_H
#define OPENCLDATA_H

#include <QObject>
#include <QStringList>

class OpenCLData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList deviceList READ deviceList WRITE setDeviceList NOTIFY deviceListChanged)
    Q_PROPERTY(QString deviceData READ deviceData WRITE setDeviceData NOTIFY deviceDataChanged)

public:
    OpenCLData(QObject *parent = 0);
    ~OpenCLData();

    void setDeviceList(const QStringList& list);
    const QStringList& deviceList();

    void setDeviceData(const QString& data);
    const QString& deviceData();

    // Means that QML can use this as a function. Gets called when you change between devices in the device dropdown.
    Q_INVOKABLE void deviceIndexChanged(int index);

signals:
    void deviceListChanged();
    void deviceDataChanged();

private:
    QStringList m_deviceList;
    QString m_deviceData;
};

#endif // OPENCLDATA_H

