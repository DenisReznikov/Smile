#ifndef AUFTRAGSANNAHME_MANY_H
#define AUFTRAGSANNAHME_MANY_H
#include "base_window_with_table.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include "Smile/UI/msqlquerymodel.h"
#include <Smile/UI/auftragsannahme_alone.h>
#include <QSqlError>
#include "auftragsannahme_alone.h"
namespace Ui {
  class Auftragsannahme_Many;
}

class Auftragsannahme_Many : public QMainWindow,public BaseWindowWithTable
{
  Q_OBJECT

public:
  explicit Auftragsannahme_Many(QString login,QSqlQuery qSqlQuery,QWidget *parent = 0);
  ~Auftragsannahme_Many();

private slots:
  void on_tableView_clicked(const QModelIndex &index);
  void  on_tableView_doubleClicked(const QModelIndex &index);
  void on_lupeButton_clicked();
  void on_button_Abbrechen_clicked();

  void on_tableView_activated(const QModelIndex &index);

  void on_tableView_pressed(const QModelIndex &index);

private:
  void createTable();
  MSqlQueryModel *model;
  QSqlDatabase db;
  QString login;
  QSqlQuery qSqlQuery;
  Auftragsannahme_Alone *auAlone;
  Ui::Auftragsannahme_Many *ui;
};

#endif // AUFTRAGSANNAHME_MANY_H
