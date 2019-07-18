#include "toolsfordb.h"

toolsForDB::toolsForDB(QString parent)
{
  db = new QSqlDatabase;
  db->addDatabase(parent);
}

toolsForDB::~toolsForDB()
{

}
