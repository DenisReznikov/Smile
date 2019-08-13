#ifndef MSQLQUERYMODEL_H
#define MSQLQUERYMODEL_H
#include <QSqlQueryModel>

class MSqlQueryModel : public QSqlQueryModel {
  QVariant data(const QModelIndex &idx, int role) const;
};

#endif // MSQLQUERYMODEL_H
