#include "authentication.h"
#include "ui_authentication.h"
#include "Server/toolsfordb.h"
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
void Authentication::checkLogAndPassInBase()
{

  QString login =ui->lineUserName->text();
  QString password=ui->lineUserPassword->text();
  if (!checkMissing(login,password))
    {
      return ;
    }
  static toolsForDB db =  toolsForDB();
  QMap<QString,QString> map;
  map.insert("login",login);
  map.insert("pass",password);
  if( db.checkInTable("auth",map))
    {
      mainWind = new MainWindow(login);
      mainWind->show();
      this->close();
    }
  else
    {
      ui->lineUserName->setStyleSheet("background-color: red");
      ui->lineUserPassword->setStyleSheet("background-color: red");
      QMessageBox::warning(this,"Авторизации","Неправильный логин или пароль");
    }
}
void Authentication::on_login_clicked()
{
  this->checkLogAndPassInBase();
}

void Authentication::on_lineUserPassword_returnPressed()
{
  this->checkLogAndPassInBase();
}
