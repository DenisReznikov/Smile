#ifndef AUFTRAGSLISTE_H
#define AUFTRAGSLISTE_H
#include <QDebug>
#include <QMainWindow>
#include "base_window_with_table.h"

namespace Ui {
  class Auftragsliste;
}

class Auftragsliste : public QMainWindow,public BaseWindowWithTable
{
  Q_OBJECT

public:
  explicit Auftragsliste(QString login,QString sql_str,QWidget *parent = nullptr);
  ~Auftragsliste();
  QString login,sql_string;

private slots:


  void on_lupeButton_clicked();

private:
  Ui::Auftragsliste *ui;

};

#endif // AUFTRAGSLISTE_H
