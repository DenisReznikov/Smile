#ifndef BEARBZUST_H
#define BEARBZUST_H

#include <QWidget>

namespace Ui {
  class BearbZust;
}

class BearbZust : public QWidget
{
  Q_OBJECT

public:
  explicit BearbZust(QWidget *parent = nullptr);
  ~BearbZust();

private:
  Ui::BearbZust *ui;
};

#endif // BEARBZUST_H
