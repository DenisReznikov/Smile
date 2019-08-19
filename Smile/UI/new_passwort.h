#ifndef NEW_PASSWORT_H
#define NEW_PASSWORT_H
#include <QMessageBox>
#include <QWidget>
#include <QTimer>
#include <Smile/Server/toolsfordb.h>
namespace Ui {
  class New_Passwort;
}

class New_Passwort : public QWidget
{
  Q_OBJECT

public:
  explicit New_Passwort(QWidget *parent = nullptr);
  ~New_Passwort();

private slots:
  void on_button_Abbrechen_clicked();
  void on_Login_clicked();

private:
  Ui::New_Passwort *ui;
};

#endif // NEW_PASSWORT_H
