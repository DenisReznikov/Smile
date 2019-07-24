#include "auftragsannahme_telas.h"
#include "ui_auftragsannahme_telas.h"

Auftragsannahme_TelAs::Auftragsannahme_TelAs(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_TelAs)
{
  ui->setupUi(this);
  ui->dateEdit->setDate(QDate::currentDate());
  ui->Name_person->setText(login);
  this->login=login;
}

Auftragsannahme_TelAs::~Auftragsannahme_TelAs()
{
  delete AUF_Alone;
  delete AUF_many;
  delete ui;
}

bool Auftragsannahme_TelAs::checkWidjets()
{
  QList<QLineEdit *> box=ui->Name->findChildren<QLineEdit*>();
  for (auto iter = box.begin(); iter != box.end(); iter++)
    {
      if((*iter)->text().isEmpty())
        {
          (*iter)->setStyleSheet("background-color:yellow");
          return false;
        }
    }
  return true;
}

void Auftragsannahme_TelAs::on_OK_clicked()
{
  if(!checkWidjets())
    {
      QMessageBox::warning(this,"Внимание ","Вы не заполнили обязательные поля ");
      return;
    }
  QVector<QString> values;
  QMap<QString,QString> *map=new QMap<QString,QString>;
  map->insert("name",ui->nameForSql->text());
  static toolsForDB db =  toolsForDB();
  QSqlQuery qSqlQuery = db.checkInTable("Auftragsannahme_TelAs",*map);
  qSqlQuery.last();
  qDebug()<<qSqlQuery.at();

  if(qSqlQuery.at()+1 == 1)
    {
      int i = 0;
      while(i<qSqlQuery.record().count())
        {
          values.push_back(qSqlQuery.value(i).toString());
          i++;
        }
      AUF_Alone = new Auftragsannahme_Alone(this->login,values);
      AUF_Alone->show();
    }

  else if(qSqlQuery.at()+1>1)
    {
      AUF_many = new Auftragsannahme_Many(this->login,qSqlQuery,this);
      AUF_many->show();
    }

  else
    {
      QMessageBox::warning(this,"Name","jordan или не nejordan");
    }
}
