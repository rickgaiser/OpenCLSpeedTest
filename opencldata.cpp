#include "opencldata.h"


#define SUCCESS 0
#define FAILURE 1


//---------------------------------------------------------------------------
#define CL_STATUS(status,function) \
  if(status != CL_SUCCESS) \
  { \
    return FAILURE; \
  }


//---------------------------------------------------------------------------
OpenCLData::OpenCLData(QObject *parent)
 : QObject(parent)
{
  initDeviceList();
}

//---------------------------------------------------------------------------
OpenCLData::~OpenCLData()
{
}

//---------------------------------------------------------------------------
void
OpenCLData::setDeviceList(const QStringList &list)
{
  if(list != m_deviceList)
  {
    m_deviceList = list;
    emit deviceListChanged();
  }
}

//---------------------------------------------------------------------------
const QStringList &
OpenCLData::deviceList()
{
  return m_deviceList;
}

//---------------------------------------------------------------------------
void
OpenCLData::setDeviceData(const QString &data)
{
  if(m_deviceData != data)
  {
    m_deviceData = data;
    emit deviceDataChanged();
  }
}

//---------------------------------------------------------------------------
const QString &
OpenCLData::deviceData()
{
  return m_deviceData;
}

//---------------------------------------------------------------------------
void
OpenCLData::deviceIndexChanged(int index)
{
  QString sDeviceData("");

  sDeviceData += "Vendor: " + m_deviceInfo[index].vendor + "\r\n";
  sDeviceData += "Name: " + m_deviceInfo[index].name + "\r\n";
  sDeviceData += "CU's: " + QString::number(m_deviceInfo[index].computeUnits) + "\r\n";

  setDeviceData(sDeviceData);
}

//---------------------------------------------------------------------------
void
OpenCLData::startTest()
{
  //setDeviceData("Testing...");
  emit globalReadSpeedChanged();
  emit globalWriteSpeedChanged();
  emit localReadSpeedChanged();
  emit localWriteSpeedChanged();
}

//---------------------------------------------------------------------------
int
OpenCLData::initDeviceList()
{
  cl_uint numPlatforms;
  cl_uint numDevices;
  cl_int status;
  char sTemp[128];

  // Get platform count
  status = clGetPlatformIDs(0, NULL, &numPlatforms);
  CL_STATUS(status, "clGetPlatformIDs");
  if(numPlatforms <= 0)
    return FAILURE;

  // Get platform IDs
  cl_platform_id * platforms = new cl_platform_id[numPlatforms];
  status = clGetPlatformIDs(numPlatforms, platforms, NULL);
  CL_STATUS(status, "clGetPlatformIDs");

  for(cl_uint i = 0; i < numPlatforms; i++)
  {

    // Get device count
    status = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices);
    CL_STATUS(status, "clGetDeviceIDs");
    if(numDevices <= 0)
      continue;

    // Get device IDs
    cl_device_id * devices = new cl_device_id[numDevices];
    status = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, numDevices, devices, NULL);
    CL_STATUS(status, "clGetDeviceIDs");

    for(cl_uint j = 0; j < numDevices; j++)
    {
      SDeviceInfo info;

      status  = clGetDeviceInfo(devices[j], CL_DEVICE_TYPE,                     sizeof(cl_device_type), &info.deviceType, NULL);
      status |= clGetDeviceInfo(devices[j], CL_DEVICE_VENDOR,                   128,                    sTemp, NULL); info.vendor = sTemp;
      status |= clGetDeviceInfo(devices[j], CL_DEVICE_NAME,                     128,                    sTemp, NULL); info.name = sTemp;
      status |= clGetDeviceInfo(devices[j], CL_DEVICE_MAX_COMPUTE_UNITS,        sizeof(cl_uint),        &info.computeUnits, NULL);
      status |= clGetDeviceInfo(devices[j], CL_DEVICE_MAX_WORK_GROUP_SIZE,      sizeof(size_t),         (void*)&info.maxWorkGroupSize, NULL);
      status |= clGetDeviceInfo(devices[j], CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(cl_uint),        (void*)&info.maxDims, NULL);
      status |= clGetDeviceInfo(devices[j], CL_DEVICE_MAX_WORK_ITEM_SIZES,      sizeof(size_t)*3,       (void*)info.maxWorkItemSizes, NULL);
      status |= clGetDeviceInfo(devices[j], CL_DEVICE_MAX_CLOCK_FREQUENCY,      sizeof(cl_uint),        &info.maxClockFreq, NULL);
      CL_STATUS(status, "clGetDeviceInfo");

      m_deviceInfo.append(info);
      m_deviceList.append(info.name);
    }
    delete[] devices;
  }
  delete[] platforms;

  return SUCCESS;
}
