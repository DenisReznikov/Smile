#include "abstract_windows.h"


Abstract_Windows::Abstract_Windows(QString name_Person,QWidget *parent)
  : QMainWindow(parent)
{

  this->name_Person = name_Person;
}

Abstract_Windows::~Abstract_Windows()
{

}
