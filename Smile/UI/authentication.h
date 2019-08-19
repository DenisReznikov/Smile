#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "mainwindow.h"
#include <QWidget>
#include <QSqlQuery>
#include <QTimer>
#include "../Smile/Server/toolsfordb.h"
#include "Smile/UI/new_passwort.h"
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
  MainWindow *mainWind;
  New_Passwort *newPasswort;

private slots:
  void on_login_clicked();
  void on_lineUserPassword_returnPressed();
  void on_cancelButton_clicked();
  void on_newPasswort_clicked();

private:

};

#endif // AUTHENTICATION_H
