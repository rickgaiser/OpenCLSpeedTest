#include "opencldata.h"

OpenCLData::OpenCLData(QObject *parent)
    : QObject(parent)
    , m_deviceList(QStringList() << "AMD Radeon HD 5770" << "NVIDIA 670" << "Intel 3770")
    , m_deviceData("Regel 1\r\nRegel 2\r\nRegel 3")
{
    // Use this as your main function.
}

OpenCLData::~OpenCLData()
{
}

void OpenCLData::setDeviceList(const QStringList &list)
{
    if(list != m_deviceList) {
        m_deviceList = list;
        emit deviceListChanged();
    }
}

const QStringList &OpenCLData::deviceList()
{
    return m_deviceList;
}

void OpenCLData::setDeviceData(const QString &data)
{
    if(m_deviceData != data) {
        m_deviceData = data;
        emit deviceDataChanged();
    }
}

const QString &OpenCLData::deviceData()
{
    return m_deviceData;
}

void OpenCLData::deviceIndexChanged(int index)
{
    setDeviceData("Device data for index:" + QString::number(index) + " from device name: " + m_deviceList.at(index) + "\r\nRegel 2\r\nRegel 3");
}
