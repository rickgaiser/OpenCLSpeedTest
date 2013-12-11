#ifndef OPENCLDATA_H
#define OPENCLDATA_H


#include <QObject>
#include <QStringList>
#include <QList>

#include <inttypes.h>
#include <CL/cl.h>


struct SDeviceInfo
{
  QString vendor;
  QString name;
  cl_device_type deviceType;
  size_t maxWorkGroupSize;
  cl_uint maxDims;
  size_t maxWorkItemSizes[3];
  cl_uint computeUnits;
  cl_uint maxClockFreq;
};


class OpenCLData
 : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QStringList deviceList       READ deviceList       WRITE setDeviceList NOTIFY deviceListChanged)
  Q_PROPERTY(QString     deviceData       READ deviceData       WRITE setDeviceData NOTIFY deviceDataChanged)
  Q_PROPERTY(double      globalReadSpeed  READ globalReadSpeed                      NOTIFY globalReadSpeedChanged)
  Q_PROPERTY(double      globalWriteSpeed READ globalWriteSpeed                     NOTIFY globalWriteSpeedChanged)
  Q_PROPERTY(double      localReadSpeed   READ localReadSpeed                       NOTIFY localReadSpeedChanged)
  Q_PROPERTY(double      localWriteSpeed  READ localWriteSpeed                      NOTIFY localWriteSpeedChanged)

public:
  OpenCLData(QObject *parent = 0);
  ~OpenCLData();

  void setDeviceList(const QStringList& list);
  const QStringList& deviceList();

  void setDeviceData(const QString& data);
  const QString& deviceData();

  double globalReadSpeed()  {return 12.3;}
  double globalWriteSpeed() {return 23.45;}
  double localReadSpeed()   {return 34.567;}
  double localWriteSpeed()  {return 45.6789;}

  // Means that QML can use this as a function. Gets called when you change between devices in the device dropdown.
  Q_INVOKABLE void deviceIndexChanged(int index);
  Q_INVOKABLE void startTest();

private:
  int initDeviceList();

signals:
  void deviceListChanged();
  void deviceDataChanged();
  void globalReadSpeedChanged();
  void globalWriteSpeedChanged();
  void localReadSpeedChanged();
  void localWriteSpeedChanged();

private:
  QStringList m_deviceList;
  QString m_deviceData;
  QList<SDeviceInfo> m_deviceInfo;
};


#endif // OPENCLDATA_H
