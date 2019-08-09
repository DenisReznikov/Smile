#ifndef AUFTRAGSLISTE_H
#define AUFTRAGSLISTE_H
#include <QMainWindow>
#include "base_window_with_table.h"
#include <QSqlQueryModel>
#include "Smile/UI/dispositionsdater_for_hvt_schaltauftrag.h"
namespace Ui {
  class Auftragsliste;
}

class Auftragsliste : public QMainWindow,public BaseWindowWithTable
{
  Q_OBJECT

public:
  explicit Auftragsliste(QString login,QString dispo,QSqlQuery qSqlQuery,QWidget *parent = 0);
  ~Auftragsliste();
  QString login,sql_string;

private slots:
  void on_lupeButton_clicked();

  void on_button_Abbrechen_clicked();

  void on_tableView_clicked(const QModelIndex &index);

  void on_tableView_doubleClicked(const QModelIndex &index);

private:
  void createTable();
  Ui::Auftragsliste *ui;
  QSqlQueryModel *model;
  Dispositionsdater_for_HVt_Schaltauftrag *DispoHvt;
  QSqlQuery qSqlQuery;
};

#endif // AUFTRAGSLISTE_H
