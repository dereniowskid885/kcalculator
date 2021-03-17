#include "browseprofiles.h"
#include "ui_browseprofiles.h"
#include "profiles.h"
#include "app.h"
#include "file.h"
#include <QDir>
#include <QMessageBox>

browseprofiles::browseprofiles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::browseprofiles)
{
    ui->setupUi(this);
    QDir profiles(QDir::currentPath()+"/Profiles"); // definiowanie sciezki
    profiles.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks); //wyswietlanie jedynie plikow w sciezce
    foreach( const QFileInfo& var, profiles.entryInfoList( QStringList() << "*.txt", QDir::Files | QDir::Hidden | QDir::NoSymLinks ) )
    {
        ui->profilesListWidget->addItem(var.baseName()); //wpisanie nazwy plikow .txt z profilami do QListWidget
    }
}

browseprofiles::~browseprofiles()
{
    delete ui;
}

void browseprofiles::on_exitButton_clicked()
{
    QApplication::quit();
}

void browseprofiles::on_backButton_clicked()
{
    hide();
    Profiles profiles;
    profiles.setModal(true);
    profiles.exec();
}

void browseprofiles::on_OKButton_clicked()
{
    if(ui->profilesListWidget->selectedItems().size() == 0) // jesli nie został wybrany żaden profil, wtedy wyświetli się komunikat
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Najpierw wybierz profil...");
    }
    else
    {
        const QString& name = ui->profilesListWidget->currentItem()->text(); // przesłanie nazwy wybranego profilu do zmiennej
        hide();
        app application(nullptr,name); //przesłanie nazwy do drugiego okna z aplikacją
        application.setModal(true);
        application.exec();
    }
}

void browseprofiles::on_deleteButton_clicked()
{
    QList<QListWidgetItem*> items = ui->profilesListWidget->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        const QString& name = ui->profilesListWidget->currentItem()->text(); // przesłanie nazwy wybranego profilu do zmiennej
        delete ui->profilesListWidget->takeItem(ui->profilesListWidget->row(item)); // usunięcie wybranej pozycji w QListWidget
        QFile::remove(QDir::currentPath()+"/Profiles/"+name+".txt"); // usunięcie pliku profilu o danej nazwie
    }
}