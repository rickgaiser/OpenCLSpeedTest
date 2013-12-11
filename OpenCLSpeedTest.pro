TEMPLATE += app
QT += qml quick

SOURCES += \
    main.cpp \
    opencldata.cpp

OTHER_FILES += \
    qml/main.qml \
    qml/TextInputCustom.qml

RESOURCES += \
    resources.qrc

HEADERS += \
    opencldata.h

INCLUDEPATH += \
    /opt/AMDAPP/include \
    /usr/local/cuda/include

LIBS += \
    -lOpenCL

CONFIG += c++11
