#include "msqlquerymodel.h"
#include <QSqlRecord>
#include <QColor>
#include <QDebug>

QVariant MSqlQueryModel::data(const QModelIndex &index, int role) const {
  QVariant value = QSqlQueryModel::data(index, role);
  if (role == Qt::BackgroundColorRole && index.column() == 0)
  {
    QString d = this->record(index.row()).value(index.column()).toString();
    if(d =="+A"||d =="+T")
    {
      return QVariant::fromValue(QColor(Qt::red));
    }
  }
  return value;
}
