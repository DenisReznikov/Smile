#ifndef TOOLSFORDB_H
#define TOOLSFORDB_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMainWindow>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>

class toolsForDB
{
public:
  // chekcInTable(Названия таблицы,<Название колонки где искать,что искать в данной колонке>)

  toolsForDB(QString nameDB="C:/Users/drezniko/Documents/Smile/Smile/Server/test.db");
  ~toolsForDB();
  QSqlQuery checkInTable(QString tableName,QMap<QString,QString> map=(QMap<QString,QString>()));
private:
  //выбераем таблицу
  void selectTable(QString str);


  QSqlQueryModel sqlAsk(QString sqlQuest);
  QSqlQueryModel *tableModel;
  QSqlDatabase db;
  QSqlQuery *sqlQuery;
};

#endif // DB_TOOL_H
