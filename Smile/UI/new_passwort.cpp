#include "new_passwort.h"
#include "ui_new_passwort.h"
#include <QDebug>
New_Passwort::New_Passwort(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::New_Passwort)
{
  ui->setupUi(this);
}

New_Passwort::~New_Passwort()
{
  delete ui;
}

void New_Passwort::on_button_Abbrechen_clicked()
{
  this->close();
}

void New_Passwort::on_Login_clicked()
{
  if(ui->lineLogin->text()==""||ui->linePasswordS->text()==""||ui->linePasswordF->text()=="")
  {
    QMessageBox m;
    m.setWindowTitle("Create login and password");
    m.setText("You have not filled in the required fields.");
    QTimer::singleShot(5000, &m, SLOT(close()));
    m.exec();
  }
  else if (ui->linePasswordF->text()!=ui->linePasswordS->text())
  {
    QMessageBox m;
    m.setWindowTitle("Create login and password");
    m.setText("Passwords do not match.");
    QTimer::singleShot(5000, &m, SLOT(close()));
    m.exec();
  }
  else if (ui->linePasswordF->text()==ui->linePasswordS->text())
  {
    static toolsForDB db =  toolsForDB();
    QVector<QString> vec;
    QMap<QString,QString> map;
    map.insert("login",ui->lineLogin->text());
    map.insert("pass",ui->linePasswordF->text());
    vec.push_back(ui->lineLogin->text());
    vec.push_back(ui->linePasswordF->text());
    QSqlQuery q = db.returnTable("auth",map);
    qDebug()<<q.last();
    if(q.last())
    {
      QMessageBox m;
      m.setWindowTitle("Create login and password");
      m.setText("There is already a user with this name and password.");
      QTimer::singleShot(5000, &m, SLOT(close()));
      m.exec();
    }
    else
    {
      db.addInTable("auth",vec);
      this->close();
    }
  }
}
