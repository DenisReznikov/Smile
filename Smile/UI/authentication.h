#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
<<<<<<< HEAD
#include "passwort_anderung.h"
=======
#include <mainwindow.h>
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
#include <QWidget>

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
<<<<<<< HEAD
  void on_newPasswort_clicked();

=======
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
  void on_login_clicked();

private:
  MainWindow *mainWind;
  Ui::Authentication *ui;
  Passwort_Anderung *passwortAnderung;
};

#endif // AUTHENTICATION_H
