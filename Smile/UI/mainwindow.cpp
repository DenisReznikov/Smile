#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
MainWindow::MainWindow(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  Auf(nullptr),
  Auswahl(nullptr)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  QDesktopWidget widget;
  QRect mainScreenSize = widget.screenGeometry(this);
  this->setGeometry(mainScreenSize.width()*0.2/2,mainScreenSize.height()*0.2/2,(int)(mainScreenSize.width()*0.8),mainScreenSize.height()*0.8);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_Auftragsauswahl_clicked()
{
  if(Auf==nullptr||!Auf->isVisible())
  {
    Auf = new Auftragsannahme_TelAs(ui->Name_person->text());
    Auf->show();
  }
}
void MainWindow::closeEvent(QCloseEvent *event)
{
  event->ignore();
  if((Auf==nullptr||!Auf->isVisible())&&(Auswahl==nullptr||!Auswahl->isVisible()))
  {
    event->accept();
  }
}
void MainWindow::on_Dispositionsmodul_clicked()
{
  if(Auswahl==nullptr||!Auswahl->isVisible())
  {
    Auswahl = new Auswahl_Dispo_Center(ui->Name_person->text());
    Auswahl->show();
  }
}
