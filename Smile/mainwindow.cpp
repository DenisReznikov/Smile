#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
<<<<<<< HEAD
=======


>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
  ui->Name_person->setText(login);
  this->login=login;
}

MainWindow::~MainWindow()
{
  delete ui;
}

<<<<<<< HEAD

void MainWindow::on_Auftragsauswahl_clicked()
{

      auto Auf = new Auftragsannahme_TelAs(this->login);
      Auf->show();
=======
void MainWindow::on_Auftragsauswahl_clicked()
{
  Auf = new Auftragsannahme_TelAs(this->login);
  Auf->show();
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
}

void MainWindow::on_Dispositionsmodul_clicked()
{
<<<<<<< HEAD
   Auswahl = new Auswahl_Dispo_Center(this->login);
   Auswahl->show();

=======
  Auswahl = new Auswahl_Dispo_Center(this->login);
  Auswahl->show();
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
}
