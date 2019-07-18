#ifndef AUFTRAGSANNAHME_ALONE_H
#define AUFTRAGSANNAHME_ALONE_H

#include <QMainWindow>

namespace Ui {
  class Auftragsannahme_Alone;
}

class Auftragsannahme_Alone : public QMainWindow
{
  Q_OBJECT

public:
  explicit Auftragsannahme_Alone(QString login,QVector<QString> values,QWidget *parent = nullptr);
  ~Auftragsannahme_Alone();


private:
  Ui::Auftragsannahme_Alone *ui;
  QString login;

};

#endif // AUFTRAGSANNAHME_ALONE_H
