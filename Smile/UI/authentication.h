#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "passwort_anderung.h"
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
  void on_newPasswort_clicked();

  void on_login_clicked();

private:
  Ui::Authentication *ui;
  Passwort_Anderung *passwortAnderung;
};

#endif // AUTHENTICATION_H
