#ifndef AUFTRAGSANNAHME_ALONE_H
#define AUFTRAGSANNAHME_ALONE_H
#include <QMainWindow>
#include <QSqlQuery>
namespace Ui {
  class Auftragsannahme_Alone;
}

class Auftragsannahme_Alone : public QMainWindow
{
  Q_OBJECT
public:
  explicit Auftragsannahme_Alone(QString login,QSqlQuery qSqlQuery,QWidget *parent = 0);
  ~Auftragsannahme_Alone();

private slots:

  void on_button_Abbrechen_clicked();

private:
  void addLine(QSqlQuery qSqlQuery) const;
  Ui::Auftragsannahme_Alone *ui;
};

#endif // AUFTRAGSANNAHME_ALONE_H
