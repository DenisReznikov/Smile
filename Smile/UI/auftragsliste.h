#ifndef AUFTRAGSLISTE_H
#define AUFTRAGSLISTE_H
#include <QDebug>
#include <QMainWindow>
#include "base_window_with_table.h"
#include <QSqlQueryModel>
namespace Ui {
  class Auftragsliste;
}

class Auftragsliste : public QMainWindow,public BaseWindowWithTable
{
  Q_OBJECT

public:
  explicit Auftragsliste(QString login,QSqlQuery qSqlQuery,QWidget *parent = 0);
  ~Auftragsliste();
  QString login,sql_string;
  void resizeEvent(QResizeEvent *event);

private slots:


  void on_lupeButton_clicked();

private:
  Ui::Auftragsliste *ui;
  QSqlQueryModel *model;
};

#endif // AUFTRAGSLISTE_H
