#ifndef AUFTRAGSANNAHME_MANY_H
#define AUFTRAGSANNAHME_MANY_H
#include <base_window_with_table.h>
#include <QMainWindow>

namespace Ui {
  class Auftragsannahme_Many;
}

class Auftragsannahme_Many : public QMainWindow,public BaseWindowWithTable
{
  Q_OBJECT

public:
  explicit Auftragsannahme_Many(QWidget *parent = nullptr);
  ~Auftragsannahme_Many();

private slots:

  void on_lupeButton_clicked();

private:
  Ui::Auftragsannahme_Many *ui;
};

#endif // AUFTRAGSANNAHME_MANY_H
