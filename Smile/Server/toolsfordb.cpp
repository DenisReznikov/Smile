#include "toolsfordb.h"
#include <QDebug>
toolsForDB::toolsForDB(QString parent)
{

  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(parent);
  db.open();
  if(!db.open())
  qDebug()<<db.lastError().text();
  qDebug()<<db.tables();
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
  sqlQuery->exec(sqlAsk);
  qDebug()<<sqlAsk;
  return *sqlQuery;
}

