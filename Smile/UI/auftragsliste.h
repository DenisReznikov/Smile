#ifndef AUFTRAGSLISTE_H
#define AUFTRAGSLISTE_H
#include <QDebug>
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
namespace Ui {
  class Auftragsliste;
}

class Auftragsliste : public QMainWindow
{
  Q_OBJECT

public:
  explicit Auftragsliste(QString login,QString sql_str,QWidget *parent = nullptr);
  ~Auftragsliste();
  QString login,sql_string;

private:
  Ui::Auftragsliste *ui;
  QSqlQueryModel *model;
  QSqlDatabase db;
};

#endif // AUFTRAGSLISTE_H
