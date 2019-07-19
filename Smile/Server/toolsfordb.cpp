#include "toolsfordb.h"

toolsForDB::toolsForDB(QString parent)
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

toolsForDB::~toolsForDB()
{

}

bool toolsForDB::checkInTable(QString tableName, QMap<QString, QString> map)
{
  QString sqlAsk="select * from "+tableName+" where ";
  sqlQuery = new QSqlQuery(db);
  foreach(QString nameTable,map.keys())
    {
      sqlAsk=sqlAsk+" "+nameTable+" = '"+map[nameTable]+"' and";
    }
  sqlAsk.resize(sqlAsk.size()-4);
  sqlQuery->exec(sqlAsk+"limit 1");
  return sqlQuery->first();
}

