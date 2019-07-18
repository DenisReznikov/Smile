#ifndef AUFTRAGSANNAHME_MANY_H
#define AUFTRAGSANNAHME_MANY_H
<<<<<<< HEAD
#include "auftragsannahme_alone.h"
#include <QMainWindow>
#include <QSqlTableModel>
=======
#include <base_window_with_table.h>
#include <QMainWindow>

>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
namespace Ui {
  class Auftragsannahme_Many;
}

<<<<<<< HEAD
class Auftragsannahme_Many : public QMainWindow
=======
class Auftragsannahme_Many : public QMainWindow,public BaseWindowWithTable
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
{
  Q_OBJECT

public:
<<<<<<< HEAD
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
=======
  explicit Auftragsannahme_Many(QWidget *parent = nullptr);
  ~Auftragsannahme_Many();

private slots:

  void on_lupeButton_clicked();

private:
  Ui::Auftragsannahme_Many *ui;
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
};

#endif // AUFTRAGSANNAHME_MANY_H
