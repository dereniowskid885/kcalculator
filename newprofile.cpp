#include "newprofile.h"
#include "ui_newprofile.h"
#include <QMessageBox>
#include "profiles.h"
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QDir>

NewProfile::NewProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProfile)
{
    ui->setupUi(this);
}

NewProfile::~NewProfile()
{
    delete ui;
}

void NewProfile::on_exitButton_clicked()
{
    QApplication::quit(); // po kliknieciu w przycisk "Exit" aplikacja zostanie wylaczona
}

void NewProfile::on_tipButton_clicked()
{
    QMessageBox::about(this, "Wskazówka", "Dostosuj swój wskaźnik poziomu aktywności fizycznej: \n \n 1,0 - 1,1 - bardzo niska aktywność np. leżenie w łóżku z powodu choroby \n 1,2 - 1,3 - siedzący tryb życia, lekkie treningi 1-2 razy w tygodniu \n 1,4 - praca siedząca, treningi 2-3 razy w tygodniu \n 1,5 - praca z umiarkowaną aktywnością, treningi 2-4 razy w tygodniu \n 1,6 - praca fizyczna połączona z ciężkimi treningami 3-5 razy w tygodniu");
}

void NewProfile::on_backButton_clicked()
{
    hide(); // schowanie aktualnego okna i otworzenie nowego
    Profiles profiles;
    profiles.setModal(true);
    profiles.exec();
}

void NewProfile::on_OKButton_clicked()
{

    QDir profiles = QDir::currentPath() + "/Profiles";// definiowanie sciezki
    QDir diaries = QDir::currentPath() + "/Diaries";
    if(!profiles.exists())
        profiles.mkpath(QDir::currentPath()+"/Profiles");
    if(!diaries.exists())
        profiles.mkpath(QDir::currentPath()+"/Diaries");

    QFile file(QDir::currentPath()+"/Profiles/profile.txt"); // zdefiniowanie sciezki wstepnej nowego profilu

    if(!file.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Nie można utworzyć profilu...");
        file.deleteLater();
    }

    QTextStream out(&file);
    QString name = ui->nameLineEdit->text();

    profiles.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks); //wyswietlanie jedynie plikow w sciezce
    foreach( const QFileInfo& var, profiles.entryInfoList( QStringList() << "*.txt", QDir::Files | QDir::Hidden | QDir::NoSymLinks ) )
    {

        if(name == var.baseName()) // sprawdzenie czy nazwa profilu sie nie powtorzyla
        {
            QMessageBox::warning(this,"Błąd aplikacji!","Profil z taką nazwą już istnieje...");
            file.close();
            QFile::remove(QDir::currentPath()+"/Profiles/profile.txt");
        }
        else if(name == "") // sprawdzenie czy uzytkownik nie zapomnial wpisac nazwy profilu
        {
            QMessageBox::warning(this,"Błąd aplikacji!","Musisz wpisać nazwę profilu!");
            file.close();
            QFile::remove(QDir::currentPath()+"/Profiles/profile.txt");
        }
        QString age = ui->ageSpinBox->text(); // zczytanie wartosci z poszczególnych okien formularza
        QString height = ui->heightSpinBox->text();
        QString weight = ui->weightSpinBox->text();
        QString activityLevel = ui->activityLevelDoubleSpinBox->text();
        QString goal = ui->goalComboBox->currentText();
        QString sex = "";
        QString kcal = "";

        if(ui->sexMaleRadioButton->isChecked())
            sex = "male";
        else
            sex = "female";

        if(goal == "Budowanie masy")
            kcal = "400";
        else if(goal == "Utrzymanie wagi")
            kcal = "0";
        else if(goal == "Redukcja wagi")
            kcal = "-400";

        out<<name<<endl; // zapisanie wartosci do pliku
        out<<age<<endl;
        out<<height<<endl;
        out<<weight<<endl;
        out<<activityLevel<<endl;
        out<<kcal<<endl;
        out<<sex<<endl;
        file.flush();
        file.close();

        if(!(name == var.baseName())) // jesli nazwa profilu sie nie powtorzyla to profil zostanie utworzony
        {
            QMessageBox::about(this,"Tworzenie profilu","Profil został utworzony!");
            file.rename(QDir::currentPath()+"/Profiles/"+name+".txt");
        }
        hide();
        Profiles profiles;
        profiles.setModal(true);
        profiles.exec();
    }
}