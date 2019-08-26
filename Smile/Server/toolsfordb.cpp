#include "toolsfordb.h"
#include <QDebug>
toolsForDB::toolsForDB(QString parent)
{

  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(parent);
  if(!db.isOpen())
  {
    db.open();
  }

}

toolsForDB::~toolsForDB()
{

}

QSqlQuery toolsForDB::returnTable(QString tableName, QMap<QString, QString> map)
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

void toolsForDB::addInTable(QString tableName, QVector<QString> vector)
{
  QString sqlAsk="INSERT INTO "+tableName+" VALUES (";
  foreach(QString values,vector)
  {
    sqlAsk=sqlAsk + "'"+values +"'"+ ",";
  }
  sqlAsk = sqlAsk.left(sqlAsk.size()-1);
  sqlAsk=sqlAsk+")";
  sqlQuery->exec(sqlAsk);
}
