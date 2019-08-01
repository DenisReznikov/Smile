#include "authentication.h"
#include "ui_authentication.h"
#include "../Smile/Server/toolsfordb.h"
#include <QDir>
#include <QDebug>
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
    QMessageBox m;
    m.setWindowTitle("Авторизации");
    m.setText("Сначала надо ввести логин и пароль!");
    QTimer::singleShot(5000, &m, SLOT(close()));
    m.exec();
    return false;
  }
  else if (log.isEmpty()||pass.isEmpty())
  {
    ui->lineUserName->setStyleSheet("background-color: red");
    ui->lineUserPassword->setStyleSheet("background-color: red");
    QMessageBox m;
    m.setWindowTitle("Авторизации");
    m.setText((log.isEmpty()) ? "Вы забыли ввести логин!" : "Вы забыли ввести пароль!");
    QTimer::singleShot(5000, &m, SLOT(close()));
    m.exec();
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
  QSqlQuery q = db.returnTable("auth",map);
  QDir::currentPath();
  if(q.last())
  {
    return true;
  }
  else
  {
    ui->lineUserName->setStyleSheet("background-color: red");
    ui->lineUserPassword->setStyleSheet("background-color: red");
    QMessageBox m;
    m.setWindowTitle("Авторизации");
    m.setText("Неправильный логин или пароль");
    QTimer::singleShot(5000, &m, SLOT(close()));
    m.exec();
    return false;
  }
}
void Authentication::on_login_clicked()
{

  if(this->checkLogAndPassInBase(ui->lineUserName->text(),ui->lineUserPassword->text()))
  {
    mainWind = new MainWindow(ui->lineUserName->text());
    mainWind->show();
    this->close();
  }
}

void Authentication::on_lineUserPassword_returnPressed()
{
  if(this->checkLogAndPassInBase(ui->lineUserName->text(),ui->lineUserPassword->text()))
  {
    mainWind = new MainWindow(ui->lineUserName->text());
    mainWind->show();
    this->close();
  }
}

