#ifndef TOOLSFORDB_H
#define TOOLSFORDB_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>

class toolsForDB
{
public:
  
  toolsForDB(QString nameDB="test.db");
  ~toolsForDB();
  QSqlQuery returnTable(QString tableName, QMap<QString,QString> map);
  void addInTable(QString tableName, QVector<QString> vector);
private:

  void selectTable(QString str);
  QSqlQueryModel sqlAsk(QString sqlQuest);
  static inline QSqlDatabase db;
  QSqlQuery *sqlQuery;
};

#endif // DB_TOOL_H
