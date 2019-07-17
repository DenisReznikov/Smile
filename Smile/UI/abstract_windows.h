#ifndef ABSTRACT_WINDOWS_H
#define ABSTRACT_WINDOWS_H

#include <QMainWindow>

class abstract_windows : public QMainWindow
{
  Q_OBJECT

public:
  abstract_windows(QWidget *parent = 0);
  ~abstract_windows();
};

#endif // ABSTRACT_WINDOWS_H
