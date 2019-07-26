#include "toolsfordb.h"

toolsForDB::toolsForDB(QString parent)
{
  if(!db.open())
  {
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(parent);
    //db.setUserName("test");
    //db.setPassword("test");
    if(!db.open())
    {
      qDebug() << db.lastError().text();
    }
    else
    {
      qDebug() <<"yes";
    }
    qDebug() <<db.tables();
  }
}

toolsForDB::~toolsForDB()
{

}

QSqlQuery toolsForDB::checkInTable(QString tableName, QMap<QString, QString> map)
{
  QString sqlAsk="select * from "+tableName+" where ";
  sqlQuery = new QSqlQuery(db);
  foreach(QString nameTable,map.keys())
  {
    sqlAsk=sqlAsk+" "+nameTable+" = '"+map[nameTable]+"' and";
  }
  if(!map.empty())
  {
    sqlAsk.resize(sqlAsk.size()-4);
  }
  else
  {
    sqlAsk.resize(sqlAsk.size()-7);
  }
  qDebug()<<sqlAsk;
  sqlQuery->exec(sqlAsk);
  return *sqlQuery;
}

