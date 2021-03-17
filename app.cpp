#include "app.h"
#include "ui_app.h"
#include "browseprofiles.h"
#include "ui_browseprofiles.h"
#include "profiles.h"
#include "diary.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <file.h>

app::app(QWidget *parent, QString profile_name) :
    QDialog(parent),
    ui(new Ui::app)
{
    File profile; // obiekt profilu
    QString name = profile.getName(profile_name); // zczytywanie poszczególnych informacji o profilu
    int calories = profile.getCalories(profile_name);
    int carbs = profile.getCarbs(profile_name);
    int proteins = profile.getProteins(profile_name);
    int fats = profile.getFats(profile_name);
    ui->setupUi(this);
    ui->profileNameLabel->setText(name); // wyswietlenie ich na ekranie
    ui->profileNameLabel->setAlignment(Qt::AlignCenter); // wyśrodkowanie tekstu
    ui->profileCalorieLabel->setNum(calories);
    ui->profileCalorieLabel->setAlignment(Qt::AlignCenter);
    ui->profileCarbLabel->setNum(carbs);
    ui->profileCarbLabel->setAlignment(Qt::AlignCenter);
    ui->profileProteinLabel->setNum(proteins);
    ui->profileProteinLabel->setAlignment(Qt::AlignCenter);
    ui->profileFatLabel->setNum(fats);
    ui->profileFatLabel->setAlignment(Qt::AlignCenter);
}

app::~app()
{
    delete ui;
}

void app::on_backButton_clicked()
{
    hide();
    browseprofiles profiles;
    profiles.setModal(true);
    profiles.exec();
}

void app::on_helpButton_clicked()
{
    QMessageBox::about(this,"Pomoc","Kliknij na dzień w kalendarzu aby otworzyć dziennik posiłków.");
}

void app::on_exitButton_clicked()
{
    QApplication::quit();
}

void app::on_calendarWidget_clicked(const QDate &date)
{
    QString dir_date = date.toString("dd.MM.yyyy"); // konwersja daty do stringa

    if(!QDir(QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()).exists()) // jesli folder z nazwa profilu nie istnieje to nalezy go stworzyc
        QDir().mkdir(QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+dir_date);

    QString kcal = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu
    QString carbs = ui->profileCarbLabel->text();
    QString proteins = ui->profileProteinLabel->text();
    QString fats = ui->profileFatLabel->text();
    QString name = ui->profileNameLabel->text();

    hide();
    diary diary(nullptr, date, name, kcal, carbs, proteins, fats); // przeslanie wartosci do nastepnego okna
    diary.setModal(true);
    diary.exec();
}