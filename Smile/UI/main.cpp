#include "abstract_windows.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  abstract_windows w;
  w.show();

  return a.exec();
}
