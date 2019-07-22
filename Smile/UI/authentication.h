#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "mainwindow.h"
#include <QWidget>
#include <QSqlQuery>
namespace Ui {
  class Authentication;
}

class Authentication : public QWidget
{
  Q_OBJECT

public:
  explicit Authentication(QWidget *parent = nullptr);
  ~Authentication();

private slots:
  void on_login_clicked();
  void on_lineUserPassword_returnPressed();


private:
  bool checkMissing(QString log, QString pass);
  void checkLogAndPassInBase();
  MainWindow *mainWind;
  Ui::Authentication *ui;
};

#endif // AUTHENTICATION_H
