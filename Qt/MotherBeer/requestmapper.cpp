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
    QByteArray start = request.getParameter("start");
    QByteArray end = request.getParameter("end");
    qDebug("RequestMapper: path=%s",path.data());
    qDebug("RequestMapper: start=%s",start.data());
    qDebug("RequestMapper: end=%s",end.data());

    if(path.startsWith("/api"))
    {
        if(path.startsWith("/api/drinks"))
        {
            // Set a response header
            response.setHeader("Content-Type", "application/json; charset=ISO-8859-1");

            // Return a simple HTML document
//            yyyy-MM-dd
            QString q;
            if(start.length() > 0 && end.length() > 0)
                q = "SELECT * FROM Drinkstamps WHERE time BETWEEN '"+ start +"' AND '"+end + "' GROUP by user";
            else
            {
//                q = "SELECT * FROM Drinkstamps";
                q = "SELECT user, group_concat(time) AS [timestamps] FROM Drinkstamps GROUP BY user";
            }

            response.write(m_dbhandle->SQLQuery(q).toLocal8Bit(),true);
        }
    }
    qDebug("RequestMapper: finished request");

}
