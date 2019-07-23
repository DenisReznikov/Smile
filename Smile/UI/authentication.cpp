#include "authentication.h"
#include "ui_authentication.h"
#include "../Smile/Server/toolsfordb.h"

Authentication::Authentication(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Authentication)
{
  ui->setupUi(this);
}

Authentication::~Authentication()
{
  delete ui;
}

bool Authentication::checkMissing(QString log, QString pass)
{
  if(log.isEmpty() && pass.isEmpty())
    {
      ui->lineUserName->setStyleSheet("background-color: red");
      ui->lineUserPassword->setStyleSheet("background-color: red");
      QMessageBox::warning(this,"Авторизации","Сначала надо ввести логин и пароль!");
      return false;
    }
  else if (log.isEmpty()||pass.isEmpty())
    {
      ui->lineUserName->setStyleSheet("background-color: red");
      ui->lineUserPassword->setStyleSheet("background-color: red");
      QMessageBox::warning(this,"Авторизации",(log.isEmpty()) ? "Вы забыли ввести логин!" : "Вы забыли ввести пароль!");
      return false;
    }
  return true;
}
bool Authentication::checkLogAndPassInBase(QString login,QString password)
{
  if (!checkMissing(login,password))
    {
      return false;
    }
  static toolsForDB db =  toolsForDB();
  QMap<QString,QString> map;
  map.insert("login",login);
  map.insert("pass",password);
  QSqlQuery q = db.checkInTable("auth",map);
  if(q.last())
    {
      return true;
    }
  else
    {
      ui->lineUserName->setStyleSheet("background-color: red");
      ui->lineUserPassword->setStyleSheet("background-color: red");
      QMessageBox::warning(this,"Авторизации","Неправильный логин или пароль");
      return false;
    }
}
void Authentication::on_login_clicked()
{
  this->checkLogAndPassInBase(ui->lineUserName->text(),ui->lineUserPassword->text());
}

void Authentication::on_lineUserPassword_returnPressed()
{
  this->checkLogAndPassInBase(ui->lineUserName->text(),ui->lineUserPassword->text());
}

