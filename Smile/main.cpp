#include "UI/authentication.h"
#include <QApplication>
#include <QMap>
int main(int argc, char *argv[])
{
  QMap<QString,QString> dd;


  QApplication a(argc, argv);
  Authentication auth;
  auth.show();

  return a.exec();
}
