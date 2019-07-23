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
  bool checkMissing(QString log, QString pass);
  bool checkLogAndPassInBase(QString log,QString pass);
  Ui::Authentication *ui;
private slots:
  void on_login_clicked();
  void on_lineUserPassword_returnPressed();

private:

  MainWindow *mainWind;

};

#endif // AUTHENTICATION_H
