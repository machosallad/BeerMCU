TEMPLATE = app

QT += qml quick widgets sql

SOURCES += main.cpp \
    udpannouncer.cpp \
    mytcpserver.cpp \
    backend.cpp \
    dbmanager.cpp \
    user.cpp \
    userhandler.cpp \
    requestmapper.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    udpannouncer.h \
    mytcpserver.h \
    backend.h \
    dbmanager.h \
    user.h \
    userhandler.h \
    requestmapper.h

#---------------------------------------------------------------------------------------
# The following lines include the sources of the QtWebAppLib library
#---------------------------------------------------------------------------------------

include(../QtWebApp/logging/logging.pri)
include(../QtWebApp/httpserver/httpserver.pri)
include(../QtWebApp/templateengine/templateengine.pri)
# Not used: include(../QtWebApp/qtservice/qtservice.pri)
