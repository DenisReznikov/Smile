#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
<<<<<<< HEAD
<<<<<<< HEAD
#include "passwort_anderung.h"
=======
#include <mainwindow.h>
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
=======

>>>>>>> parent of a9619b1... complete ui
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

<<<<<<< HEAD
private slots:
<<<<<<< HEAD
  void on_newPasswort_clicked();

=======
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
  void on_login_clicked();

=======
>>>>>>> parent of a9619b1... complete ui
private:
  MainWindow *mainWind;
  Ui::Authentication *ui;
};

#endif // AUTHENTICATION_H
