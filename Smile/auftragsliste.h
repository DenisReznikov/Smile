#ifndef AUFTRAGSLISTE_H
#define AUFTRAGSLISTE_H
#include <QDebug>
#include <QMainWindow>
<<<<<<< HEAD
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
=======
#include <base_window_with_table.h>

>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
namespace Ui {
  class Auftragsliste;
}

<<<<<<< HEAD
class Auftragsliste : public QMainWindow
=======
class Auftragsliste : public QMainWindow,public BaseWindowWithTable
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
{
  Q_OBJECT

public:
  explicit Auftragsliste(QString login,QString sql_str,QWidget *parent = nullptr);
  ~Auftragsliste();
  QString login,sql_string;

<<<<<<< HEAD
private:
  Ui::Auftragsliste *ui;
  QSqlQueryModel *model;
  QSqlDatabase db;
=======
private slots:


  void on_lupeButton_clicked();

private:
  Ui::Auftragsliste *ui;

>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
};

#endif // AUFTRAGSLISTE_H
