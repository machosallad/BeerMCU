TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    udpannouncer.cpp \
    mytcpserver.cpp \
    backend.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    udpannouncer.h \
    mytcpserver.h \
    backend.h
