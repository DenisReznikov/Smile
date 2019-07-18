#include "authentication.h"
#include "abstract_windows.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Authentication auth;
  auth.show();

  return a.exec();
}
