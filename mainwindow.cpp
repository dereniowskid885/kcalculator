#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "profiles.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Exit_clicked()
{
    QApplication::quit(); // wylaczenie aplikacji
}

void MainWindow::on_About_clicked()
{
    QMessageBox::about(this,"O programie","Program napisany w ramach projektu aplikacji na przedmiot Programowanie 2."); // wyswietlenie wiadomosci
}


void MainWindow::on_Start_clicked()
{
    hide(); // schowanie aktualnego okna i otworzenie nowego
    Profiles profiles;
    profiles.setModal(true);
    profiles.exec();
}