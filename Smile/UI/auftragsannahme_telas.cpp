#include "auftragsannahme_telas.h"
#include "ui_auftragsannahme_telas.h"
#include <QTimer>
#include <QDesktopWidget>
Auftragsannahme_TelAs::Auftragsannahme_TelAs(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_TelAs)
{
  ui->setupUi(this);
  ui->data_grobeZust_Zeitbereich->setDate(QDate::currentDate());
  ui->Name_person->setText(login);
  this->login=login;
  QDesktopWidget widget;
  QRect mainScreenSize = widget.screenGeometry(this);
  qDebug()<<mainScreenSize.height();
  this->setGeometry(mainScreenSize.width()*0.2/2,mainScreenSize.height()*0.2/2,(int)(mainScreenSize.width()*0.8),mainScreenSize.height()*0.8);
}
void Auftragsannahme_TelAs::search(QMap<QString,QString> map)
{
  static toolsForDB db =  toolsForDB();
  QSqlQuery qSqlQuery = db.returnTable("Auftragsannahme_TelAs",map);
  qSqlQuery.last();
  if(qSqlQuery.at()+1 == 1)
  {
    AUF_Alone = new Auftragsannahme_Alone(this->login,qSqlQuery,this);
    AUF_Alone->show();
  }
  else if(qSqlQuery.at()+1>1)
  {
    AUF_many = new Auftragsannahme_Many(this->login,qSqlQuery,this);
    AUF_many->show();
  }
  else
  {
    QMessageBox::warning(this,"Name","no matching records found");
  }
}
Auftragsannahme_TelAs::~Auftragsannahme_TelAs()
{
  delete AUF_Alone;
  delete AUF_many;
  delete ui;
}


void Auftragsannahme_TelAs::on_OK_clicked()
{
  QMap<QString,QString> map;
  if(ui->radio_SE->isChecked())
  {
    map.insert("AKI","SE");
  }
  else if (ui->radio_SL->isChecked())
  {
    map.insert("AKI","SL");
  }
  else if (ui->radio_MI->isChecked())
  {
    map.insert("AKI","MI");
  }
  else
  {
    map.insert("AKI","MX");
  }
  switch(ui->tabWidget->currentIndex())
  {
    case 0:
      {
        break;
      }
    case 1:
      {
        if(ui->line_LtgBez_ONKzA->text()=="")
        {
          ui->line_LtgBez_ONKzA->setStyleSheet("background-color: red");
          QMessageBox m;
          m.setWindowTitle("Search");
          m.setText( "You have not filled 'ONKzA' !");
          QTimer::singleShot(5000, &m, SLOT(close()));
          m.exec();
        }
        else
        {
          map.insert("ONKzA",ui->line_LtgBez_ONKzA->text());
          this->search(map);
        }
        break;
      }
    case 2:
      {
        break;
      }
    case 3:
      {
        if(ui->line_Name_Name->text()=="")
        {
          ui->line_Name_Name->setStyleSheet("background-color: red");
          QMessageBox m;
          m.setWindowTitle("Search");
          m.setText( "You have not filled 'Name' !");
          QTimer::singleShot(5000, &m, SLOT(close()));
          m.exec();
        }
        else
        {
          map.insert("Name",ui->line_Name_Name->text());
          this->search(map);
        }
        break;
      }
    case 6:
      {
        if(ui->line_AuftragsNr_AuftragsNr->text()=="")
        {
          ui->line_AuftragsNr_AuftragsNr->setStyleSheet("background-color: red");
          QMessageBox m;
          m.setWindowTitle("Search");
          m.setText( "You have not filled 'AuftragsNr' !");
          QTimer::singleShot(5000, &m, SLOT(close()));
          m.exec();
        }
        else
        {
          map.insert("AuftragsNr",ui->line_AuftragsNr_AuftragsNr->text());
          this->search(map);
        }
        break;
      }
  }
}


void Auftragsannahme_TelAs::on_radio_Volhistorie_clicked(bool checked)
{
  this->ui->tabWidget->setTabEnabled(10,!checked);
}

void Auftragsannahme_TelAs::on_radio_L_Volhistorie_clicked(bool checked)
{
  this->ui->tabWidget->setTabEnabled(10,!checked);
}

void Auftragsannahme_TelAs::on_radio_laufendeAufrage_clicked(bool checked)
{
  this->ui->tabWidget->setTabEnabled(10,checked);
}

void Auftragsannahme_TelAs::on_button_Abbrech_clicked()
{
  this->close();
}

void Auftragsannahme_TelAs::on_tabWidget_tabBarClicked(int index)
{
  if(index==10)
  {
    ui->radio_L_Volhistorie->setEnabled(false);
    ui->radio_Volhistorie->setEnabled(false);
  }
  else
  {
    ui->radio_L_Volhistorie->setEnabled(true);
    ui->radio_Volhistorie->setEnabled(true);
  }
}
