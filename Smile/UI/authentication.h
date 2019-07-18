#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <mainwindow.h>
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
  void on_login_clicked();

private:
  MainWindow *mainWind;
  Ui::Authentication *ui;
};

#endif // AUTHENTICATION_H
