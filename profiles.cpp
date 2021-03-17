#include "profiles.h"
#include "ui_profiles.h"
#include "newprofile.h"
#include "browseprofiles.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>

Profiles::Profiles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profiles)
{
    ui->setupUi(this);
}

Profiles::~Profiles()
{
    delete ui;
}

void Profiles::on_Exit_clicked()
{
    QApplication::quit(); // po kliknieciu w przycisk "Exit" aplikacja zostanie wylaczona
}

void Profiles::on_New_profile_button_clicked()
{
    hide(); // schowanie aktualnego okna i otworzenie nowego
    NewProfile newprofile;
    newprofile.setModal(true);
    newprofile.exec();
}

void Profiles::on_Browse_profiles_button_clicked()
{

    hide(); // schowanie aktualnego okna i otworzenie nowego
    browseprofiles profile;
    profile.setModal(true);
    profile.exec();
}