#ifndef PASSWORT_ANDERUNG_H
#define PASSWORT_ANDERUNG_H

#include <QWidget>

namespace Ui {
  class Passwort_Anderung;
}

class Passwort_Anderung : public QWidget
{
  Q_OBJECT

public:
  explicit Passwort_Anderung(QWidget *parent = nullptr);
  ~Passwort_Anderung();

private:
  Ui::Passwort_Anderung *ui;
};

#endif // PASSWORT_ANDERUNG_H
