#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);


  ui->Name_person->setText(login);
  this->login=login;
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_Auftragsauswahl_clicked()
{
  Auf = new Auftragsannahme_TelAs(this->login);
  Auf->show();
}

void MainWindow::on_Dispositionsmodul_clicked()
{
  Auswahl = new Auswahl_Dispo_Center(this->login);
  Auswahl->show();
}
