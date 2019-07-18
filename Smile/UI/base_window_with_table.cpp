#include "base_window_with_table.h"

BaseWindowWithTable::BaseWindowWithTable()
{

}
void BaseWindowWithTable::Lupe(QWidget *obj)
{
  obj->setVisible(!obj->isVisible());
}
