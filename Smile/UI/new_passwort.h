#ifndef NEW_PASSWORT_H
#define NEW_PASSWORT_H

#include <QWidget>
namespace Ui {
  class New_Passwort;
}

class New_Passwort : public QWidget
{
  Q_OBJECT

public:
  explicit New_Passwort(QWidget *parent = 0);
  ~New_Passwort();

private:
  Ui::New_Passwort *ui;
};

#endif // NEW_PASSWORT_H
