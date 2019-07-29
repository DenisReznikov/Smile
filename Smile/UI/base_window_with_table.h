#ifndef BASEWINDOW_H
#define BASEWINDOW_H
#include <QWidget>
#include <QSqlQuery>
#include <QTableView>
class BaseWindowWithTable
{
public:
  BaseWindowWithTable();
protected:
  void lupe(QWidget *obj);
};

#endif // BASEWINDOW_H
