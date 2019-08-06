#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
MainWindow::MainWindow(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  Auf=0;
  Auswahl=0;
  ui->Name_person->setText(login);
  this->login=login;
  QDesktopWidget widget;
  QRect mainScreenSize = widget.screenGeometry(this);
  qDebug()<<mainScreenSize.height();
  this->setGeometry(mainScreenSize.width()*0.2/2,mainScreenSize.height()*0.2/2,(int)(mainScreenSize.width()*0.8),mainScreenSize.height()*0.8);

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_Auftragsauswahl_clicked()
{
  if(Auf==0||!Auf->isVisible())
  {
    Auf = new Auftragsannahme_TelAs(this->login);
    Auf->show();
  }
}

void MainWindow::on_Dispositionsmodul_clicked()
{
  if(Auswahl==0||!Auswahl->isVisible())
  {
    Auswahl = new Auswahl_Dispo_Center(this->login);
    Auswahl->show();
  }
}
