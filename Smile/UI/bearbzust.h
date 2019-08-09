#ifndef BEARBZUST_H
#define BEARBZUST_H

#include <QDialog>

namespace Ui {
  class BearbZust;
}

class BearbZust : public QDialog
{
  Q_OBJECT

public:
  explicit BearbZust(QWidget *parent = nullptr);
  ~BearbZust();

private slots:
  void on_buttonBox_accepted();

private:
  Ui::BearbZust *ui;
};

#endif // BEARBZUST_H
