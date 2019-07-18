#ifndef TOOLSFORDB_H
#define TOOLSFORDB_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMainWindow>
#include <QDebug>

#include <QSqlRelationalTableModel>

class toolsForDB
{
public:

  //нестандартная база данных
  toolsForDB(QString nameDB="C:/D_B/test.db");
  ~toolsForDB();
private:
  //выбераем таблицу
  void selectTable(QString str);
  // chekcInTable(Названия таблицы,<Название колонки где искать,что искать в данной колонке>)
  bool checkInTable(QString tableName,QMap<QString,QString> map);

  QSqlQueryModel sqlAsk(QString sqlQuest);
  QSqlQueryModel *tableModel;
  QSqlDatabase *db;

};

#endif // DB_TOOL_H
