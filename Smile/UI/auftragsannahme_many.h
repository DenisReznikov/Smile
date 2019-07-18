#ifndef AUFTRAGSANNAHME_MANY_H
#define AUFTRAGSANNAHME_MANY_H
#include "auftragsannahme_alone.h"
#include <QMainWindow>
#include <QSqlTableModel>
namespace Ui {
  class Auftragsannahme_Many;
}

class Auftragsannahme_Many : public QMainWindow
{
  Q_OBJECT

public:
  explicit Auftragsannahme_Many(QString login,QString str,QWidget *parent = nullptr);
  ~Auftragsannahme_Many();

private slots:
  void on_tableView_clicked(const QModelIndex &index);
  void on_tableView_doubleClicked(const QModelIndex &index);
  void resizeEvent(QResizeEvent *event);

private:
  void update_table();
  Ui::Auftragsannahme_Many *ui;
  QString login;
  QSqlQueryModel* model;
  QSqlDatabase db;
  Auftragsannahme_Alone* au_alone;
};

#endif // AUFTRAGSANNAHME_MANY_H
