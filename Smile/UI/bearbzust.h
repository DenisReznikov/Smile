#ifndef BEARBZUST_H
#define BEARBZUST_H
#include <QSqlQueryModel>
#include <QDialog>
#include <Smile/UI/msqlquerymodel.h>
#include <Smile/Server/toolsfordb.h>
namespace Ui {
  class BearbZust;
}

class BearbZust : public QDialog
{
  Q_OBJECT

public:
  explicit BearbZust(QWidget *parent = nullptr);
  ~BearbZust();
  QString ret;
private slots:
  void on_button_OK_clicked();

  void on_button_Abbrechen_clicked();

  void on_tableView_doubleClicked(const QModelIndex );

private:
  Ui::BearbZust *ui;
  MSqlQueryModel *model;
  void createTable();
};

#endif // BEARBZUST_H
