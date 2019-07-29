#include "base_window_with_table.h"
#include <QHeaderView>
#include <QDebug>
BaseWindowWithTable::BaseWindowWithTable()
{
}
void BaseWindowWithTable::lupe(QWidget *obj)
{
  obj->setVisible(!obj->isVisible());
}


