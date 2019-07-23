#ifndef AUFTRAGSANNAHME_MANY_H
#define AUFTRAGSANNAHME_MANY_H
#include "base_window_with_table.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
//#include <UI/auftragsannahme_alone.h>
#include <QDebug>
#include <QSqlError>
#include "auftragsannahme_alone.h"
namespace Ui {
  class Auftragsannahme_Many;
}

class Auftragsannahme_Many : public QMainWindow,public BaseWindowWithTable
{
  Q_OBJECT

public:
  explicit Auftragsannahme_Many(QString login,QSqlQuery qSqlQuery,QWidget *parent = nullptr);
  ~Auftragsannahme_Many();

private slots:

  void on_tableView_clicked(const QModelIndex &index);
  void  on_tableView_doubleClicked(const QModelIndex &index);
  void on_lupeButton_clicked();

private:

  void resizeEvent(QResizeEvent *event);
  QSqlQueryModel *model;
  QSqlDatabase db;
  QString login;
  Auftragsannahme_Alone *auAlone;
  Ui::Auftragsannahme_Many *ui;
};

#endif // AUFTRAGSANNAHME_MANY_H
