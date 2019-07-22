#include "base_window_with_table.h"
#include <QHeaderView>
#include <QDebug>
BaseWindowWithTable::BaseWindowWithTable()
{
  qDebug()<<"HIIIIIIIIIIIIII";
}
void BaseWindowWithTable::lupe(QWidget *obj)
{
  obj->setVisible(!obj->isVisible());
}

void BaseWindowWithTable::updateTable(QTableView *obj)
{
  QList<QTableView *> box=obj->findChildren<QTableView*>();
  int b = 0;
  for (auto iter = box.begin(); iter != box.end(); iter++)
    {

      (*iter)->horizontalHeader()->setSectionResizeMode(b, QHeaderView::ResizeToContents);
      b++;
    }
  obj->horizontalHeader()->setSectionResizeMode(box.size(), QHeaderView::Stretch);


}
