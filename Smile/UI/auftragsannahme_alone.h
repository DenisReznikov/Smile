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
<<<<<<< HEAD
  explicit Auftragsannahme_Alone(QString login,QVector<QString> values,QWidget *parent = nullptr);
  ~Auftragsannahme_Alone();


private:
  Ui::Auftragsannahme_Alone *ui;
  QString login;

=======
  explicit Auftragsannahme_Alone(QWidget *parent = nullptr);
  ~Auftragsannahme_Alone();

private:
  Ui::Auftragsannahme_Alone *ui;
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
};

#endif // AUFTRAGSANNAHME_ALONE_H
