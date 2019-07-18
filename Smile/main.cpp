#include "authentication.h"
#include <QApplication>

QString Abstract_Windows::name_Person="You can't see me";

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Authentication auth;
  auth.show();

  return a.exec();
}
