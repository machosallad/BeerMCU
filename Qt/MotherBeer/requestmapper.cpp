/**
  @file
  @author Stefan Frings
*/

#include <QCoreApplication>
#include "requestmapper.h"

RequestMapper::RequestMapper(DbManager *dbManager, QObject* parent)
    :HttpRequestHandler(parent)
{
    qDebug("RequestMapper: created");
    m_dbhandle = dbManager;
}


RequestMapper::~RequestMapper()
{
    qDebug("RequestMapper: deleted");
}


void RequestMapper::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    if(path.startsWith("/api"))
    {
    // Set a response header
    response.setHeader("Content-Type", "application/json; charset=ISO-8859-1");

    // Return a simple HTML document
    response.write(m_dbhandle->SQLQuery("Select * from Drinkstamps").toLocal8Bit(),true);


    }
    qDebug("RequestMapper: finished request");

}
