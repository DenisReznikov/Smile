#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "mainwindow.h"
#include <QWidget>
#include <QSqlQuery>
#include <QTimer>
namespace Ui {
  class Authentication;
}

class Authentication : public QWidget
{
  Q_OBJECT

public:
  explicit Authentication(QWidget *parent = 0);
  ~Authentication();
  bool checkMissing(QString log, QString pass);
  bool checkLogAndPassInBase(QString log,QString pass);
  Ui::Authentication *ui;
  MainWindow *mainWind;

private slots:
  void on_login_clicked();
  void on_lineUserPassword_returnPressed();


  void on_cancelButton_clicked();

private:


};

#endif // AUTHENTICATION_H
