#include "diary.h"
#include "ui_diary.h"
#include "addfood.h"
#include "app.h"
#include "file.h"
#include <QDate>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDir>
#include <QStringList>
#include <QListWidget>
#include <QModelIndexList>
#include <QItemSelectionModel>
#include <QList>

diary::diary(QWidget *parent, QDate selected_date, QString profile_name, QString kcal, QString carbs, QString proteins, QString fats):
    QDialog(parent),
    ui(new Ui::diary)
{
    ui->setupUi(this);

    QString date = selected_date.toString("dd.MM.yyyy"); // konwersja daty do stringa

    QString breakfast = QDir::currentPath()+"/Diaries/"+profile_name+"_"+date+"/Śniadanie"; // tworzenie sciezek do folderow z posilkami
    QDir breakfast_dir(breakfast);
    QString breakfast_2 = QDir::currentPath()+"/Diaries/"+profile_name+"_"+date+"/Drugie śniadanie";
    QDir breakfast_2_dir(breakfast_2);
    QString dinner = QDir::currentPath()+"/Diaries/"+profile_name+"_"+date+"/Obiad";
    QDir dinner_dir(dinner);
    QString tea = QDir::currentPath()+"/Diaries/"+profile_name+"_"+date+"/Podwieczorek";
    QDir tea_dir(tea);
    QString supper = QDir::currentPath()+"/Diaries/"+profile_name+"_"+date+"/Kolacja";
    QDir supper_dir(supper);
    QString snacks = QDir::currentPath()+"/Diaries/"+profile_name+"_"+date+"/Przekąski";
    QDir snacks_dir(snacks);

        QStringList breakfast_meals = breakfast_dir.entryList(QStringList() << "*.txt",QDir::Files); // zczytanie wszystkich plikow z folderu
        QStringList breakfast_2_meals = breakfast_2_dir.entryList(QStringList() << "*.txt",QDir::Files);
        QStringList dinner_meals = dinner_dir.entryList(QStringList() << "*.txt",QDir::Files);
        QStringList tea_meals = tea_dir.entryList(QStringList() << "*.txt",QDir::Files);
        QStringList supper_meals = supper_dir.entryList(QStringList() << "*.txt",QDir::Files);
        QStringList snacks_meals = snacks_dir.entryList(QStringList() << "*.txt",QDir::Files);

        foreach(QString filename, breakfast_meals) // zczytanie wartosci z kazdego pliku w folderze i wypisanie do tabelki
        {
            QFile file(breakfast+"/"+filename);

                if(!file.open(QFile::ReadOnly | QFile::Text))
                {
                    QMessageBox::warning(this,"Błąd Aplikacji","Nie udało się otworzyć pliku");
                    file.close();
                }

                QTextStream in(&file);

                QString name = in.readLine(0);
                QString amount = in.readLine(0);
                QString kcal = in.readLine(0);
                QString carbs = in.readLine(0);
                QString proteins = in.readLine(0);
                QString fats = in.readLine(0);

                ui->breakfastTableWidget->insertRow(ui->breakfastTableWidget->rowCount());
                int row = ui->breakfastTableWidget->rowCount() - 1;

                QTableWidgetItem *amount_item = new QTableWidgetItem(amount);
                ui->breakfastTableWidget->setItem(row,AMOUNT,new QTableWidgetItem(amount));
                amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                ui->breakfastTableWidget->setItem(row,PRODUCT,new QTableWidgetItem(name));

                QTableWidgetItem *calories_item = new QTableWidgetItem(kcal);
                ui->breakfastTableWidget->setItem(row,CALORIES,new QTableWidgetItem(kcal));
                calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *carbs_item = new QTableWidgetItem(carbs);
                ui->breakfastTableWidget->setItem(row,CARBS,new QTableWidgetItem(carbs));
                carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *proteins_item = new QTableWidgetItem(proteins);
                ui->breakfastTableWidget->setItem(row,PROTEINS,new QTableWidgetItem(proteins));
                proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *fats_item = new QTableWidgetItem(fats);
                ui->breakfastTableWidget->setItem(row,FATS,new QTableWidgetItem(fats));
                fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                file.close();

        }

        foreach(QString filename, breakfast_2_meals) // zczytanie wartosci z kazdego pliku w folderze i wypisanie do tabelki
        {
            QFile file(breakfast_2+"/"+filename);

                if(!file.open(QFile::ReadOnly | QFile::Text))
                {
                    QMessageBox::warning(this,"Błąd Aplikacji","Nie udało się otworzyć pliku");
                    file.close();
                }

                QTextStream in(&file);

                QString name = in.readLine(0);
                QString amount = in.readLine(0);
                QString kcal = in.readLine(0);
                QString carbs = in.readLine(0);
                QString proteins = in.readLine(0);
                QString fats = in.readLine(0);

                ui->breakfast_2TableWidget->insertRow(ui->breakfast_2TableWidget->rowCount());
                int row = ui->breakfast_2TableWidget->rowCount() - 1;

                QTableWidgetItem *amount_item = new QTableWidgetItem(amount);
                ui->breakfast_2TableWidget->setItem(row,AMOUNT,new QTableWidgetItem(amount));
                amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                ui->breakfast_2TableWidget->setItem(row,PRODUCT,new QTableWidgetItem(name));

                QTableWidgetItem *calories_item = new QTableWidgetItem(kcal);
                ui->breakfast_2TableWidget->setItem(row,CALORIES,new QTableWidgetItem(kcal));
                calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *carbs_item = new QTableWidgetItem(carbs);
                ui->breakfast_2TableWidget->setItem(row,CARBS,new QTableWidgetItem(carbs));
                carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *proteins_item = new QTableWidgetItem(proteins);
                ui->breakfast_2TableWidget->setItem(row,PROTEINS,new QTableWidgetItem(proteins));
                proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *fats_item = new QTableWidgetItem(fats);
                ui->breakfast_2TableWidget->setItem(row,FATS,new QTableWidgetItem(fats));
                fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                file.close();

        }

        foreach(QString filename, dinner_meals) // zczytanie wartosci z kazdego pliku w folderze i wypisanie do tabelki
        {
            QFile file(dinner+"/"+filename);

                if(!file.open(QFile::ReadOnly | QFile::Text))
                {
                    QMessageBox::warning(this,"Błąd Aplikacji","Nie udało się otworzyć pliku");
                    file.close();
                }

                QTextStream in(&file);

                QString name = in.readLine(0);
                QString amount = in.readLine(0);
                QString kcal = in.readLine(0);
                QString carbs = in.readLine(0);
                QString proteins = in.readLine(0);
                QString fats = in.readLine(0);

                ui->dinnerTableWidget->insertRow(ui->dinnerTableWidget->rowCount());
                int row = ui->dinnerTableWidget->rowCount() - 1;

                QTableWidgetItem *amount_item = new QTableWidgetItem(amount);
                ui->dinnerTableWidget->setItem(row,AMOUNT,new QTableWidgetItem(amount));
                amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                ui->dinnerTableWidget->setItem(row,PRODUCT,new QTableWidgetItem(name));

                QTableWidgetItem *calories_item = new QTableWidgetItem(kcal);
                ui->dinnerTableWidget->setItem(row,CALORIES,new QTableWidgetItem(kcal));
                calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *carbs_item = new QTableWidgetItem(carbs);
                ui->dinnerTableWidget->setItem(row,CARBS,new QTableWidgetItem(carbs));
                carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *proteins_item = new QTableWidgetItem(proteins);
                ui->dinnerTableWidget->setItem(row,PROTEINS,new QTableWidgetItem(proteins));
                proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *fats_item = new QTableWidgetItem(fats);
                ui->dinnerTableWidget->setItem(row,FATS,new QTableWidgetItem(fats));
                fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                file.close();

        }

        foreach(QString filename, tea_meals) // zczytanie wartosci z kazdego pliku w folderze i wypisanie do tabelki
        {
            QFile file(tea+"/"+filename);

                if(!file.open(QFile::ReadOnly | QFile::Text))
                {
                    QMessageBox::warning(this,"Błąd Aplikacji","Nie udało się otworzyć pliku");
                    file.close();
                }

                QTextStream in(&file);

                QString name = in.readLine(0);
                QString amount = in.readLine(0);
                QString kcal = in.readLine(0);
                QString carbs = in.readLine(0);
                QString proteins = in.readLine(0);
                QString fats = in.readLine(0);

                ui->teaTableWidget->insertRow(ui->teaTableWidget->rowCount());
                int row = ui->teaTableWidget->rowCount() - 1;

                QTableWidgetItem *amount_item = new QTableWidgetItem(amount);
                ui->teaTableWidget->setItem(row,AMOUNT,new QTableWidgetItem(amount));
                amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                ui->teaTableWidget->setItem(row,PRODUCT,new QTableWidgetItem(name));

                QTableWidgetItem *calories_item = new QTableWidgetItem(kcal);
                ui->teaTableWidget->setItem(row,CALORIES,new QTableWidgetItem(kcal));
                calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *carbs_item = new QTableWidgetItem(carbs);
                ui->teaTableWidget->setItem(row,CARBS,new QTableWidgetItem(carbs));
                carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *proteins_item = new QTableWidgetItem(proteins);
                ui->teaTableWidget->setItem(row,PROTEINS,new QTableWidgetItem(proteins));
                proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *fats_item = new QTableWidgetItem(fats);
                ui->teaTableWidget->setItem(row,FATS,new QTableWidgetItem(fats));
                fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                file.close();

        }

        foreach(QString filename, supper_meals) // zczytanie wartosci z kazdego pliku w folderze i wypisanie do tabelki
        {
            QFile file(supper+"/"+filename);

                if(!file.open(QFile::ReadOnly | QFile::Text))
                {
                    QMessageBox::warning(this,"Błąd Aplikacji","Nie udało się otworzyć pliku");
                    file.close();
                }

                QTextStream in(&file);

                QString name = in.readLine(0);
                QString amount = in.readLine(0);
                QString kcal = in.readLine(0);
                QString carbs = in.readLine(0);
                QString proteins = in.readLine(0);
                QString fats = in.readLine(0);

                ui->supperTableWidget->insertRow(ui->supperTableWidget->rowCount());
                int row = ui->supperTableWidget->rowCount() - 1;

                QTableWidgetItem *amount_item = new QTableWidgetItem(amount);
                ui->supperTableWidget->setItem(row,AMOUNT,new QTableWidgetItem(amount));
                amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                ui->supperTableWidget->setItem(row,PRODUCT,new QTableWidgetItem(name));

                QTableWidgetItem *calories_item = new QTableWidgetItem(kcal);
                ui->supperTableWidget->setItem(row,CALORIES,new QTableWidgetItem(kcal));
                calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *carbs_item = new QTableWidgetItem(carbs);
                ui->supperTableWidget->setItem(row,CARBS,new QTableWidgetItem(carbs));
                carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *proteins_item = new QTableWidgetItem(proteins);
                ui->supperTableWidget->setItem(row,PROTEINS,new QTableWidgetItem(proteins));
                proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *fats_item = new QTableWidgetItem(fats);
                ui->supperTableWidget->setItem(row,FATS,new QTableWidgetItem(fats));
                fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                file.close();

        }

        foreach(QString filename, snacks_meals) // zczytanie wartosci z kazdego pliku w folderze i wypisanie do tabelki
        {
            QFile file(snacks+"/"+filename);

                if(!file.open(QFile::ReadOnly | QFile::Text))
                {
                    QMessageBox::warning(this,"Błąd Aplikacji","Nie udało się otworzyć pliku");
                    file.close();
                }

                QTextStream in(&file);

                QString name = in.readLine(0);
                QString amount = in.readLine(0);
                QString kcal = in.readLine(0);
                QString carbs = in.readLine(0);
                QString proteins = in.readLine(0);
                QString fats = in.readLine(0);

                ui->snacksTableWidget->insertRow(ui->snacksTableWidget->rowCount());
                int row = ui->snacksTableWidget->rowCount() - 1;

                QTableWidgetItem *amount_item = new QTableWidgetItem(amount);
                ui->snacksTableWidget->setItem(row,AMOUNT,new QTableWidgetItem(amount));
                amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                ui->snacksTableWidget->setItem(row,PRODUCT,new QTableWidgetItem(name));

                QTableWidgetItem *calories_item = new QTableWidgetItem(kcal);
                ui->snacksTableWidget->setItem(row,CALORIES,new QTableWidgetItem(kcal));
                calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *carbs_item = new QTableWidgetItem(carbs);
                ui->snacksTableWidget->setItem(row,CARBS,new QTableWidgetItem(carbs));
                carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *proteins_item = new QTableWidgetItem(proteins);
                ui->snacksTableWidget->setItem(row,PROTEINS,new QTableWidgetItem(proteins));
                proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                QTableWidgetItem *fats_item = new QTableWidgetItem(fats);
                ui->snacksTableWidget->setItem(row,FATS,new QTableWidgetItem(fats));
                fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                file.close();

        }

    int bar_kcal = kcal.toInt(); // konwersja stringow do intow
    int bar_carbs = carbs.toInt();
    int bar_proteins = proteins.toInt();
    int bar_fats = fats.toInt();

    ui->kcalprogressBar->setMaximum(bar_kcal);// ustawienie wartosci maksymalnej dla progress barow
    ui->carbsprogressBar->setMaximum(bar_carbs);
    ui->proteinsprogressBar->setMaximum(bar_proteins);
    ui->fatsprogressBar->setMaximum(bar_fats);

    if(bar_kcal<=0) // sprawdzenie czy poszczegolne wartosci zczytane z profilu nie sa mniejsze lub rowne 0
        ui->kcalprogressBar->setValue(0); // jesli sa, to ustaw wartosc suwaka na 0
    else
        ui->kcalprogressBar->setValue(bar_kcal); // w przeciwnym razie ustaw wartosci zczytane z profilu

    if(bar_carbs<=0)
        ui->carbsprogressBar->setValue(0);
    else
        ui->carbsprogressBar->setValue(bar_carbs);

    if(bar_proteins<=0)
        ui->proteinsprogressBar->setValue(0);
    else
        ui->proteinsprogressBar->setValue(bar_proteins);

    if(bar_fats<=0)
        ui->fatsprogressBar->setValue(0);
    else
        ui->fatsprogressBar->setValue(bar_fats);

    if(QFile(QDir::currentPath()+"/Diaries/"+profile_name+"_"+date+".txt").exists()) // jesli dzienny profil zostal wczesniej utworzony to zczytaj z niego wartosci
    {
        File f1;
        QString file_path = (profile_name+"_"+date);
        int new_kcal = f1.get_daily_Calories(file_path);
        int new_carbs = f1.get_daily_Carbs(file_path);
        int new_proteins = f1.get_daily_Proteins(file_path);
        int new_fats = f1.get_daily_Fats(file_path);

        ui->selectedDateLabel->setText(date);
        ui->profileNameLabel->setText(profile_name);
        ui->profileNameLabel->setAlignment(Qt::AlignCenter);
        ui->profileCalorieLabel->setNum(new_kcal);
        ui->profileCalorieLabel->setAlignment(Qt::AlignCenter);
        ui->profileCarbLabel->setNum(new_carbs);
        ui->profileCarbLabel->setAlignment(Qt::AlignCenter);
        ui->profileProteinLabel->setNum(new_proteins);
        ui->profileProteinLabel->setAlignment(Qt::AlignCenter);
        ui->profileFatLabel->setNum(new_fats);
        ui->profileFatLabel->setAlignment(Qt::AlignCenter);

        if(new_kcal<=0) // sprawdzenie czy poszczegolne wartosci zczytane z dziennego profilu nie sa mniejsze lub rowne 0
            ui->kcalprogressBar->setValue(0); // jesli sa, to ustaw wartosc suwaka na 0
        else
            ui->kcalprogressBar->setValue(new_kcal);

        if(new_carbs<=0)
            ui->carbsprogressBar->setValue(0);
        else
            ui->carbsprogressBar->setValue(new_carbs);

        if(new_proteins<=0)
            ui->proteinsprogressBar->setValue(0);
        else
            ui->proteinsprogressBar->setValue(new_proteins);

        if(new_fats<=0)
            ui->fatsprogressBar->setValue(0);
        else
            ui->fatsprogressBar->setValue(new_fats);

    }
    else // w przeciwnym razie ustaw wartosci domyslnie policzone przy tworzeniu profilu
    {
        int new_kcal = kcal.toInt();
        int new_carbs = carbs.toInt();
        int new_proteins = proteins.toInt();
        int new_fats = fats.toInt();

        ui->selectedDateLabel->setText(date);
        ui->profileNameLabel->setText(profile_name);
        ui->profileNameLabel->setAlignment(Qt::AlignCenter);
        ui->profileCalorieLabel->setNum(new_kcal);
        ui->profileCalorieLabel->setAlignment(Qt::AlignCenter);
        ui->profileCarbLabel->setNum(new_carbs);
        ui->profileCarbLabel->setAlignment(Qt::AlignCenter);
        ui->profileProteinLabel->setNum(new_proteins);
        ui->profileProteinLabel->setAlignment(Qt::AlignCenter);
        ui->profileFatLabel->setNum(new_fats);
        ui->profileFatLabel->setAlignment(Qt::AlignCenter);

        if(new_kcal<=0) // sprawdzenie czy poszczegolne wartosci zczytane z profilu nie sa mniejsze lub rowne 0
            ui->kcalprogressBar->setValue(0); // jesli sa, to ustaw wartosc suwaka na 0
        else
            ui->kcalprogressBar->setValue(new_kcal); // w przeciwnym razie ustaw wartosci zczytane z profilu

        if(new_carbs<=0)
            ui->carbsprogressBar->setValue(0);
        else
            ui->carbsprogressBar->setValue(new_carbs);

        if(new_proteins<=0)
            ui->proteinsprogressBar->setValue(0);
        else
            ui->proteinsprogressBar->setValue(new_proteins);

        if(new_fats<=0)
            ui->fatsprogressBar->setValue(0);
        else
            ui->fatsprogressBar->setValue(new_fats);
    }

}

diary::~diary()
{
    delete ui;
}

void diary::on_exitButton_clicked()
{
    QApplication::quit();
}

void diary::on_addBreakfastButton_clicked()
{

    int res; // otworzenie okna z formularzem z dodawaniem posilku
    addfood addfood(this);
    res = addfood.exec();
    if(res == QDialog::Rejected)
        return;

    QString product = addfood.product(); // zczytanie wartosci z formularza
    int amount = addfood.amount();
    int calories = addfood.calories();
    int carbs = addfood.carbs();
    int proteins = addfood.proteins();
    int fats = addfood.fats();

    ui->breakfastTableWidget->insertRow(ui->breakfastTableWidget->rowCount()); // wpisanie produktu do tabelki
    int row = ui->breakfastTableWidget->rowCount() - 1;

    QTableWidgetItem *amount_item = new QTableWidgetItem(QString::number(amount));
    ui->breakfastTableWidget->setItem(row,AMOUNT,amount_item);
    amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    ui->breakfastTableWidget->setItem(row,PRODUCT,new QTableWidgetItem(product));

    QTableWidgetItem *calories_item = new QTableWidgetItem(QString::number(calories));
    ui->breakfastTableWidget->setItem(row,CALORIES,calories_item);
    calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *carbs_item = new QTableWidgetItem(QString::number(carbs));
    ui->breakfastTableWidget->setItem(row,CARBS,carbs_item);
    carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *proteins_item = new QTableWidgetItem(QString::number(proteins));
    ui->breakfastTableWidget->setItem(row,PROTEINS,proteins_item);
    proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *fats_item = new QTableWidgetItem(QString::number(fats));
    ui->breakfastTableWidget->setItem(row,FATS,fats_item);
    fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
    QDir().mkdir(file_path+"/"+ui->breakfastLabel->text());

    QFile file(file_path+"/"+ui->breakfastLabel->text()+"/"+product+".txt"); // tworzenie pliku posilku z dziennika

    if(!file.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik dziennika nie mógł zostać utworzony...");
        file.deleteLater();
    }

    QTextStream out(&file); // wpisanie wartosci do pliku
    out<<product<<endl;
    out<<amount<<endl;
    out<<calories<<endl;
    out<<carbs<<endl;
    out<<proteins<<endl;
    out<<fats<<endl;
    file.close();

    QString profile_calories = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu i zamiana na liczby
    int new_calories = profile_calories.toInt();
    QString profile_carbs = ui->profileCarbLabel->text();
    int new_carbs = profile_carbs.toInt();
    QString profile_proteins = ui->profileProteinLabel->text();
    int new_proteins = profile_proteins.toInt();
    QString profile_fats = ui->profileFatLabel->text();
    int new_fats = profile_fats.toInt();

    int actual_kcal = new_calories - calories;
    int actual_carbs = new_carbs - carbs;
    int actual_proteins = new_proteins - proteins;
    int actual_fats = new_fats - fats;

    ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
    ui->profileCarbLabel->setNum(actual_carbs);
    ui->profileProteinLabel->setNum(actual_proteins);
    ui->profileFatLabel->setNum(actual_fats);

    ui->kcalprogressBar->setValue(actual_kcal);
    ui->carbsprogressBar->setValue(actual_carbs);
    ui->proteinsprogressBar->setValue(actual_proteins);
    ui->fatsprogressBar->setValue(actual_fats);

    QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

    if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
        dailyfile.deleteLater();
    }

    QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do profilu dziennego
    out_daily_file<<actual_kcal<<endl;
    out_daily_file<<actual_carbs<<endl;
    out_daily_file<<actual_proteins<<endl;
    out_daily_file<<actual_fats<<endl;
    dailyfile.close();

}

void diary::on_addBreakfast_2Button_clicked()
{

    int res; // otworzenie okna z formularzem z dodawaniem posilku
    addfood addfood(this);
    res = addfood.exec();
    if(res == QDialog::Rejected)
        return;

    QString product = addfood.product(); // zczytanie wartosci z formularza
    int amount = addfood.amount();
    int calories = addfood.calories();
    int carbs = addfood.carbs();
    int proteins = addfood.proteins();
    int fats = addfood.fats();

    ui->breakfast_2TableWidget->insertRow(ui->breakfast_2TableWidget->rowCount()); // wpisanie produktu do tabelki
    int row = ui->breakfast_2TableWidget->rowCount() - 1;

    QTableWidgetItem *amount_item = new QTableWidgetItem(QString::number(amount));
    ui->breakfast_2TableWidget->setItem(row,AMOUNT,amount_item);
    amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    ui->breakfast_2TableWidget->setItem(row,PRODUCT,new QTableWidgetItem(product));

    QTableWidgetItem *calories_item = new QTableWidgetItem(QString::number(calories));
    ui->breakfast_2TableWidget->setItem(row,CALORIES,calories_item);
    calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *carbs_item = new QTableWidgetItem(QString::number(carbs));
    ui->breakfast_2TableWidget->setItem(row,CARBS,carbs_item);
    carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *proteins_item = new QTableWidgetItem(QString::number(proteins));
    ui->breakfast_2TableWidget->setItem(row,PROTEINS,proteins_item);
    proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *fats_item = new QTableWidgetItem(QString::number(fats));
    ui->breakfast_2TableWidget->setItem(row,FATS,fats_item);
    fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
    QDir().mkdir(file_path+"/"+ui->breakfast_2Label->text());

    QFile file(file_path+"/"+ui->breakfast_2Label->text()+"/"+product+".txt"); // tworzenie pliku posilku z dziennika

    if(!file.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik dziennika nie mógł zostać utworzony...");
        file.deleteLater();
    }

    QTextStream out(&file); // wpisanie wartosci do pliku
    out<<product<<endl;
    out<<amount<<endl;
    out<<calories<<endl;
    out<<carbs<<endl;
    out<<proteins<<endl;
    out<<fats<<endl;
    file.close();

    QString profile_calories = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu i zamiana na inty
    int new_calories = profile_calories.toInt();
    QString profile_carbs = ui->profileCarbLabel->text();
    int new_carbs = profile_carbs.toInt();
    QString profile_proteins = ui->profileProteinLabel->text();
    int new_proteins = profile_proteins.toInt();
    QString profile_fats = ui->profileFatLabel->text();
    int new_fats = profile_fats.toInt();

    int actual_kcal = new_calories - calories;
    int actual_carbs = new_carbs - carbs;
    int actual_proteins = new_proteins - proteins;
    int actual_fats = new_fats - fats;

    ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
    ui->profileCarbLabel->setNum(actual_carbs);
    ui->profileProteinLabel->setNum(actual_proteins);
    ui->profileFatLabel->setNum(actual_fats);

    ui->kcalprogressBar->setValue(actual_kcal);
    ui->carbsprogressBar->setValue(actual_carbs);
    ui->proteinsprogressBar->setValue(actual_proteins);
    ui->fatsprogressBar->setValue(actual_fats);

    QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

    if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
        dailyfile.deleteLater();
    }

    QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do profilu dziennego
    out_daily_file<<actual_kcal<<endl;
    out_daily_file<<actual_carbs<<endl;
    out_daily_file<<actual_proteins<<endl;
    out_daily_file<<actual_fats<<endl;
    dailyfile.close();

}

void diary::on_addDinnerButton_clicked()
{

    int res; // otworzenie okna z formularzem z dodawaniem posilku
    addfood addfood(this);
    res = addfood.exec();
    if(res == QDialog::Rejected)
        return;

    QString product = addfood.product(); // zczytanie wartosci z formularza
    int amount = addfood.amount();
    int calories = addfood.calories();
    int carbs = addfood.carbs();
    int proteins = addfood.proteins();
    int fats = addfood.fats();

    ui->dinnerTableWidget->insertRow(ui->dinnerTableWidget->rowCount()); // wpisanie produktu do tabelki
    int row = ui->dinnerTableWidget->rowCount() - 1;

    QTableWidgetItem *amount_item = new QTableWidgetItem(QString::number(amount));
    ui->dinnerTableWidget->setItem(row,AMOUNT,amount_item);
    amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    ui->dinnerTableWidget->setItem(row,PRODUCT,new QTableWidgetItem(product));

    QTableWidgetItem *calories_item = new QTableWidgetItem(QString::number(calories));
    ui->dinnerTableWidget->setItem(row,CALORIES,calories_item);
    calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *carbs_item = new QTableWidgetItem(QString::number(carbs));
    ui->dinnerTableWidget->setItem(row,CARBS,carbs_item);
    carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *proteins_item = new QTableWidgetItem(QString::number(proteins));
    ui->dinnerTableWidget->setItem(row,PROTEINS,proteins_item);
    proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *fats_item = new QTableWidgetItem(QString::number(fats));
    ui->dinnerTableWidget->setItem(row,FATS,fats_item);
    fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
    QDir().mkdir(file_path+"/"+ui->dinnerLabel->text());

    QFile file(file_path+"/"+ui->dinnerLabel->text()+"/"+product+".txt"); // tworzenie pliku posilku z dziennika

    if(!file.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik dziennika nie mógł zostać utworzony...");
        file.deleteLater();
    }

    QTextStream out(&file); // wpisanie wartosci do pliku
    out<<product<<endl;
    out<<amount<<endl;
    out<<calories<<endl;
    out<<carbs<<endl;
    out<<proteins<<endl;
    out<<fats<<endl;

    QString profile_calories = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu i zamiana na int
    int new_calories = profile_calories.toInt();
    QString profile_carbs = ui->profileCarbLabel->text();
    int new_carbs = profile_carbs.toInt();
    QString profile_proteins = ui->profileProteinLabel->text();
    int new_proteins = profile_proteins.toInt();
    QString profile_fats = ui->profileFatLabel->text();
    int new_fats = profile_fats.toInt();

    int actual_kcal = new_calories - calories;
    int actual_carbs = new_carbs - carbs;
    int actual_proteins = new_proteins - proteins;
    int actual_fats = new_fats - fats;

    ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
    ui->profileCarbLabel->setNum(actual_carbs);
    ui->profileProteinLabel->setNum(actual_proteins);
    ui->profileFatLabel->setNum(actual_fats);

    ui->kcalprogressBar->setValue(actual_kcal);
    ui->carbsprogressBar->setValue(actual_carbs);
    ui->proteinsprogressBar->setValue(actual_proteins);
    ui->fatsprogressBar->setValue(actual_fats);

    QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

    if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
        dailyfile.deleteLater();
    }

    QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do pliku profilu dziennego
    out_daily_file<<actual_kcal<<endl;
    out_daily_file<<actual_carbs<<endl;
    out_daily_file<<actual_proteins<<endl;
    out_daily_file<<actual_fats<<endl;
    dailyfile.close();
}



void diary::on_addTeaButton_clicked()
{

    int res; // otworzenie okna z formularzem z dodawaniem posilku
    addfood addfood(this);
    res = addfood.exec();
    if(res == QDialog::Rejected)
        return;

    QString product = addfood.product(); // zczytanie wartosci z formularza
    int amount = addfood.amount();
    int calories = addfood.calories();
    int carbs = addfood.carbs();
    int proteins = addfood.proteins();
    int fats = addfood.fats();

    ui->teaTableWidget->insertRow(ui->teaTableWidget->rowCount()); // wpisanie produktu do tabelki
    int row = ui->teaTableWidget->rowCount() - 1;

    QTableWidgetItem *amount_item = new QTableWidgetItem(QString::number(amount));
    ui->teaTableWidget->setItem(row,AMOUNT,amount_item);
    amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    ui->teaTableWidget->setItem(row,PRODUCT,new QTableWidgetItem(product));

    QTableWidgetItem *calories_item = new QTableWidgetItem(QString::number(calories));
    ui->teaTableWidget->setItem(row,CALORIES,calories_item);
    calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *carbs_item = new QTableWidgetItem(QString::number(carbs));
    ui->teaTableWidget->setItem(row,CARBS,carbs_item);
    carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *proteins_item = new QTableWidgetItem(QString::number(proteins));
    ui->teaTableWidget->setItem(row,PROTEINS,proteins_item);
    proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *fats_item = new QTableWidgetItem(QString::number(fats));
    ui->teaTableWidget->setItem(row,FATS,fats_item);
    fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
    QDir().mkdir(file_path+"/"+ui->teaLabel->text());

    QFile file(file_path+"/"+ui->teaLabel->text()+"/"+product+".txt"); // tworzenie pliku posilku z dziennika

    if(!file.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik dziennika nie mógł zostać utworzony...");
        file.deleteLater();
    }

    QTextStream out(&file); // wpisanie wartosci do pliku
    out<<product<<endl;
    out<<amount<<endl;
    out<<calories<<endl;
    out<<carbs<<endl;
    out<<proteins<<endl;
    out<<fats<<endl;

    QString profile_calories = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu i zamiana na inty
    int new_calories = profile_calories.toInt();
    QString profile_carbs = ui->profileCarbLabel->text();
    int new_carbs = profile_carbs.toInt();
    QString profile_proteins = ui->profileProteinLabel->text();
    int new_proteins = profile_proteins.toInt();
    QString profile_fats = ui->profileFatLabel->text();
    int new_fats = profile_fats.toInt();

    int actual_kcal = new_calories - calories;
    int actual_carbs = new_carbs - carbs;
    int actual_proteins = new_proteins - proteins;
    int actual_fats = new_fats - fats;

    ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
    ui->profileCarbLabel->setNum(actual_carbs);
    ui->profileProteinLabel->setNum(actual_proteins);
    ui->profileFatLabel->setNum(actual_fats);

    ui->kcalprogressBar->setValue(actual_kcal);
    ui->carbsprogressBar->setValue(actual_carbs);
    ui->proteinsprogressBar->setValue(actual_proteins);
    ui->fatsprogressBar->setValue(actual_fats);

    QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

    if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
        dailyfile.deleteLater();
    }

    QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do pliku profilu dziennego
    out_daily_file<<actual_kcal<<endl;
    out_daily_file<<actual_carbs<<endl;
    out_daily_file<<actual_proteins<<endl;
    out_daily_file<<actual_fats<<endl;
    dailyfile.close();

}

void diary::on_addSupperButton_clicked()
{

    int res; // otworzenie okna z formularzem z dodawaniem posilku
    addfood addfood(this);
    res = addfood.exec();
    if(res == QDialog::Rejected)
        return;

    QString product = addfood.product(); // zczytanie wartosci z formularza
    int amount = addfood.amount();
    int calories = addfood.calories();
    int carbs = addfood.carbs();
    int proteins = addfood.proteins();
    int fats = addfood.fats();

    ui->supperTableWidget->insertRow(ui->supperTableWidget->rowCount()); // wpisanie produktu do tabelki
    int row = ui->supperTableWidget->rowCount() - 1;

    QTableWidgetItem *amount_item = new QTableWidgetItem(QString::number(amount));
    ui->supperTableWidget->setItem(row,AMOUNT,amount_item);
    amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    ui->supperTableWidget->setItem(row,PRODUCT,new QTableWidgetItem(product));

    QTableWidgetItem *calories_item = new QTableWidgetItem(QString::number(calories));
    ui->supperTableWidget->setItem(row,CALORIES,calories_item);
    calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *carbs_item = new QTableWidgetItem(QString::number(carbs));
    ui->supperTableWidget->setItem(row,CARBS,carbs_item);
    carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *proteins_item = new QTableWidgetItem(QString::number(proteins));
    ui->supperTableWidget->setItem(row,PROTEINS,proteins_item);
    proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *fats_item = new QTableWidgetItem(QString::number(fats));
    ui->supperTableWidget->setItem(row,FATS,fats_item);
    fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
    QDir().mkdir(file_path+"/"+ui->supperLabel->text());

    QFile file(file_path+"/"+ui->supperLabel->text()+"/"+product+".txt"); // tworzenie pliku posilku z dziennika

    if(!file.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik dziennika nie mógł zostać utworzony...");
        file.deleteLater();
    }

    QTextStream out(&file); // wpisanie wartosci do pliku
    out<<product<<endl;
    out<<amount<<endl;
    out<<calories<<endl;
    out<<carbs<<endl;
    out<<proteins<<endl;
    out<<fats<<endl;

    QString profile_calories = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu i zamiana na inty
    int new_calories = profile_calories.toInt();
    QString profile_carbs = ui->profileCarbLabel->text();
    int new_carbs = profile_carbs.toInt();
    QString profile_proteins = ui->profileProteinLabel->text();
    int new_proteins = profile_proteins.toInt();
    QString profile_fats = ui->profileFatLabel->text();
    int new_fats = profile_fats.toInt();

    int actual_kcal = new_calories - calories;
    int actual_carbs = new_carbs - carbs;
    int actual_proteins = new_proteins - proteins;
    int actual_fats = new_fats - fats;

    ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
    ui->profileCarbLabel->setNum(actual_carbs);
    ui->profileProteinLabel->setNum(actual_proteins);
    ui->profileFatLabel->setNum(actual_fats);

    ui->kcalprogressBar->setValue(actual_kcal);
    ui->carbsprogressBar->setValue(actual_carbs);
    ui->proteinsprogressBar->setValue(actual_proteins);
    ui->fatsprogressBar->setValue(actual_fats);

    QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

    if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
        dailyfile.deleteLater();
    }

    QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do profilu dziennego
    out_daily_file<<actual_kcal<<endl;
    out_daily_file<<actual_carbs<<endl;
    out_daily_file<<actual_proteins<<endl;
    out_daily_file<<actual_fats<<endl;
    dailyfile.close();

}

void diary::on_addSnacksButton_clicked()
{

    int res; // otworzenie okna z formularzem z dodawaniem posilku
    addfood addfood(this);
    res = addfood.exec();
    if(res == QDialog::Rejected)
        return;

    QString product = addfood.product(); // zczytanie wartosci z formularza
    int amount = addfood.amount();
    int calories = addfood.calories();
    int carbs = addfood.carbs();
    int proteins = addfood.proteins();
    int fats = addfood.fats();

    ui->snacksTableWidget->insertRow(ui->snacksTableWidget->rowCount()); // wpisanie produktu do tabelki
    int row = ui->snacksTableWidget->rowCount() - 1;

    QTableWidgetItem *amount_item = new QTableWidgetItem(QString::number(amount));
    ui->snacksTableWidget->setItem(row,AMOUNT,amount_item);
    amount_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    ui->snacksTableWidget->setItem(row,PRODUCT,new QTableWidgetItem(product));

    QTableWidgetItem *calories_item = new QTableWidgetItem(QString::number(calories));
    ui->snacksTableWidget->setItem(row,CALORIES,calories_item);
    calories_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *carbs_item = new QTableWidgetItem(QString::number(carbs));
    ui->snacksTableWidget->setItem(row,CARBS,carbs_item);
    carbs_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *proteins_item = new QTableWidgetItem(QString::number(proteins));
    ui->snacksTableWidget->setItem(row,PROTEINS,proteins_item);
    proteins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *fats_item = new QTableWidgetItem(QString::number(fats));
    ui->snacksTableWidget->setItem(row,FATS,fats_item);
    fats_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
    QDir().mkdir(file_path+"/"+ui->snacksLabel->text());

    QFile file(file_path+"/"+ui->snacksLabel->text()+"/"+product+".txt"); // tworzenie pliku posilku z dziennika

    if(!file.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik dziennika nie mógł zostać utworzony...");
        file.deleteLater();
    }

    QTextStream out(&file); // wpisanie wartosci do pliku
    out<<product<<endl;
    out<<amount<<endl;
    out<<calories<<endl;
    out<<carbs<<endl;
    out<<proteins<<endl;
    out<<fats<<endl;

    QString profile_calories = ui->profileCalorieLabel->text();
    int new_calories = profile_calories.toInt();
    QString profile_carbs = ui->profileCarbLabel->text();
    int new_carbs = profile_carbs.toInt();
    QString profile_proteins = ui->profileProteinLabel->text();
    int new_proteins = profile_proteins.toInt();
    QString profile_fats = ui->profileFatLabel->text();
    int new_fats = profile_fats.toInt();

    int actual_kcal = new_calories - calories;
    int actual_carbs = new_carbs - carbs;
    int actual_proteins = new_proteins - proteins;
    int actual_fats = new_fats - fats;

    ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
    ui->profileCarbLabel->setNum(actual_carbs);
    ui->profileProteinLabel->setNum(actual_proteins);
    ui->profileFatLabel->setNum(actual_fats);

    ui->kcalprogressBar->setValue(actual_kcal);
    ui->carbsprogressBar->setValue(actual_carbs);
    ui->proteinsprogressBar->setValue(actual_proteins);
    ui->fatsprogressBar->setValue(actual_fats);

    QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

    if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
        dailyfile.deleteLater();
    }

    QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do profilu dziennego
    out_daily_file<<actual_kcal<<endl;
    out_daily_file<<actual_carbs<<endl;
    out_daily_file<<actual_proteins<<endl;
    out_daily_file<<actual_fats<<endl;
    dailyfile.close();

}

void diary::on_backButton_clicked()
{
    QString name = ui->profileNameLabel->text(); // zczytanie nazwy profilu i otworzenie wlasciwego profilu i  okna z kalendarzem
    hide();
    app app(nullptr, name);
    app.setModal(true);
    app.exec();
}

void diary::on_deleteBreakfastButton_clicked()
{

    QString date = ui->selectedDateLabel->text();
    QString profile = ui->profileNameLabel->text();
    int row = ui->breakfastTableWidget->currentRow(); // zczytanie aktualnej liczby wiersza

    if(row == (-1)) // jesli uzytkownik nie wybierze zadnego wiersza z tabelki wartosc row jest rowna -1
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Najpierw wybierz posiłek z tabeli.");
        return;
    }
    else
    {

        QString name = ui->breakfastTableWidget->item(row,1)->text(); // zczytanie wartosci zaznaczonego posilku i konwersja do int
        QString calories = ui->breakfastTableWidget->item(row,2)->text();
        QString carbs = ui->breakfastTableWidget->item(row,3)->text();
        QString proteins = ui->breakfastTableWidget->item(row,4)->text();
        QString fats = ui->breakfastTableWidget->item(row,5)->text();

        int deleted_kcal = calories.toInt(); // konwersja do int
        int deleted_carbs = carbs.toInt();
        int deleted_proteins = proteins.toInt();
        int deleted_fats = fats.toInt();

        QString c_kcal = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu i konwersja do int
        int current_kcal = c_kcal.toInt();
        QString c_carbs = ui->profileCarbLabel->text();
        int current_carbs = c_carbs.toInt();
        QString c_proteins = ui->profileProteinLabel->text();
        int current_proteins = c_proteins.toInt();
        QString c_fats = ui->profileFatLabel->text();
        int current_fats = c_fats.toInt();

        int actual_kcal = current_kcal + deleted_kcal;
        int actual_carbs = current_carbs + deleted_carbs;
        int actual_fats = current_fats + deleted_fats;
        int actual_proteins = current_proteins + deleted_proteins;

        ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
        ui->profileCarbLabel->setNum(actual_carbs);
        ui->profileProteinLabel->setNum(actual_proteins);
        ui->profileFatLabel->setNum(actual_fats);

        ui->kcalprogressBar->setValue(actual_kcal);
        ui->carbsprogressBar->setValue(actual_carbs);
        ui->proteinsprogressBar->setValue(actual_proteins);
        ui->fatsprogressBar->setValue(actual_fats);

        QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
        QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

        if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
        {
            QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
            dailyfile.deleteLater();
        }

        QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do profilu dziennego
        out_daily_file<<actual_kcal<<endl;
        out_daily_file<<actual_carbs<<endl;
        out_daily_file<<actual_proteins<<endl;
        out_daily_file<<actual_fats<<endl;
        dailyfile.close();

        ui->breakfastTableWidget->removeRow(ui->breakfastTableWidget->currentRow()); // wykasowanie zaznaczonego wiersza w tabeli
        QFile::remove(QDir::currentPath()+"/Diaries/"+profile+"_"+date+"/Śniadanie/"+name+".txt"); // usunięcie pliku posiłku o danej nazwie

    }
}

void diary::on_deleteBreakfastButton_2_clicked()
{

    QString date = ui->selectedDateLabel->text();
    QString profile = ui->profileNameLabel->text();
    int row = ui->breakfast_2TableWidget->currentRow();

    if(row == (-1))
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Najpierw wybierz posiłek z tabeli.");
        return;
    }
    else
    {
        QString name = ui->breakfast_2TableWidget->item(row,1)->text(); // zczytanie wartosci zaznaczonego posilku i konwersja do int
        QString calories = ui->breakfast_2TableWidget->item(row,2)->text();
        QString carbs = ui->breakfast_2TableWidget->item(row,3)->text();
        QString proteins = ui->breakfast_2TableWidget->item(row,4)->text();
        QString fats = ui->breakfast_2TableWidget->item(row,5)->text();

        int deleted_kcal = calories.toInt();
        int deleted_carbs = carbs.toInt();
        int deleted_proteins = proteins.toInt();
        int deleted_fats = fats.toInt();

        QString c_kcal = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu i konwersja do int
        int current_kcal = c_kcal.toInt();
        QString c_carbs = ui->profileCarbLabel->text();
        int current_carbs = c_carbs.toInt();
        QString c_proteins = ui->profileProteinLabel->text();
        int current_proteins = c_proteins.toInt();
        QString c_fats = ui->profileFatLabel->text();
        int current_fats = c_fats.toInt();

        int actual_kcal = current_kcal + deleted_kcal;
        int actual_carbs = current_carbs + deleted_carbs;
        int actual_fats = current_fats + deleted_fats;
        int actual_proteins = current_proteins + deleted_proteins;

        ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
        ui->profileCarbLabel->setNum(actual_carbs);
        ui->profileProteinLabel->setNum(actual_proteins);
        ui->profileFatLabel->setNum(actual_fats);

        ui->kcalprogressBar->setValue(actual_kcal);
        ui->carbsprogressBar->setValue(actual_carbs);
        ui->proteinsprogressBar->setValue(actual_proteins);
        ui->fatsprogressBar->setValue(actual_fats);

        QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
        QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

        if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
        {
            QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
            dailyfile.deleteLater();
        }

        QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do profilu dziennego
        out_daily_file<<actual_kcal<<endl;
        out_daily_file<<actual_carbs<<endl;
        out_daily_file<<actual_proteins<<endl;
        out_daily_file<<actual_fats<<endl;
        dailyfile.close();

        ui->breakfast_2TableWidget->removeRow(ui->breakfast_2TableWidget->currentRow()); // wykasowanie zaznaczonego wiersza w tabeli
        QFile::remove(QDir::currentPath()+"/Diaries/"+profile+"_"+date+"/Drugie śniadanie/"+name+".txt"); // usunięcie pliku posiłku o danej nazwie
    }
}

void diary::on_deleteDinnerButton_clicked()
{

    QString date = ui->selectedDateLabel->text();
    QString profile = ui->profileNameLabel->text();
    int row = ui->dinnerTableWidget->currentRow();

    if(row == (-1))
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Najpierw wybierz posiłek z tabeli.");
        return;
    }
    else
    {
        QString name = ui->dinnerTableWidget->item(row,1)->text(); // zczytanie wartosci zaznaczonego posilku i konwersja do int
        QString calories = ui->dinnerTableWidget->item(row,2)->text();
        QString carbs = ui->dinnerTableWidget->item(row,3)->text();
        QString proteins = ui->dinnerTableWidget->item(row,4)->text();
        QString fats = ui->dinnerTableWidget->item(row,5)->text();

        int deleted_kcal = calories.toInt();
        int deleted_carbs = carbs.toInt();
        int deleted_proteins = proteins.toInt();
        int deleted_fats = fats.toInt();

        QString c_kcal = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu i konwersja do int
        int current_kcal = c_kcal.toInt();
        QString c_carbs = ui->profileCarbLabel->text();
        int current_carbs = c_carbs.toInt();
        QString c_proteins = ui->profileProteinLabel->text();
        int current_proteins = c_proteins.toInt();
        QString c_fats = ui->profileFatLabel->text();
        int current_fats = c_fats.toInt();

        int actual_kcal = current_kcal + deleted_kcal;
        int actual_carbs = current_carbs + deleted_carbs;
        int actual_fats = current_fats + deleted_fats;
        int actual_proteins = current_proteins + deleted_proteins;

        ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
        ui->profileCarbLabel->setNum(actual_carbs);
        ui->profileProteinLabel->setNum(actual_proteins);
        ui->profileFatLabel->setNum(actual_fats);

        ui->kcalprogressBar->setValue(actual_kcal);
        ui->carbsprogressBar->setValue(actual_carbs);
        ui->proteinsprogressBar->setValue(actual_proteins);
        ui->fatsprogressBar->setValue(actual_fats);

        QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
        QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

        if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
        {
            QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
            dailyfile.deleteLater();
        }

        QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do pliku profilu dziennego
        out_daily_file<<actual_kcal<<endl;
        out_daily_file<<actual_carbs<<endl;
        out_daily_file<<actual_proteins<<endl;
        out_daily_file<<actual_fats<<endl;
        dailyfile.close();

        ui->dinnerTableWidget->removeRow(ui->dinnerTableWidget->currentRow()); // wykasowanie zaznaczonego wiersza w tabeli
        QFile::remove(QDir::currentPath()+"/Diaries/"+profile+"_"+date+"/Obiad/"+name+".txt"); // usunięcie pliku posiłku o danej nazwie
    }
}

void diary::on_deleteTeaButton_clicked()
{

    QString date = ui->selectedDateLabel->text();
    QString profile = ui->profileNameLabel->text();
    int row = ui->teaTableWidget->currentRow();

    if(row == (-1))
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Najpierw wybierz posiłek z tabeli.");
        return;
    }
    else
    {
        QString name = ui->teaTableWidget->item(row,1)->text(); // zczytanie wartosci zaznaczonego posilku i konwersja do int
        QString calories = ui->teaTableWidget->item(row,2)->text();
        QString carbs = ui->teaTableWidget->item(row,3)->text();
        QString proteins = ui->teaTableWidget->item(row,4)->text();
        QString fats = ui->teaTableWidget->item(row,5)->text();

        int deleted_kcal = calories.toInt();
        int deleted_carbs = carbs.toInt();
        int deleted_proteins = proteins.toInt();
        int deleted_fats = fats.toInt();

        QString c_kcal = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu i konwersja do int
        int current_kcal = c_kcal.toInt();
        QString c_carbs = ui->profileCarbLabel->text();
        int current_carbs = c_carbs.toInt();
        QString c_proteins = ui->profileProteinLabel->text();
        int current_proteins = c_proteins.toInt();
        QString c_fats = ui->profileFatLabel->text();
        int current_fats = c_fats.toInt();

        int actual_kcal = current_kcal + deleted_kcal;
        int actual_carbs = current_carbs + deleted_carbs;
        int actual_fats = current_fats + deleted_fats;
        int actual_proteins = current_proteins + deleted_proteins;

        ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
        ui->profileCarbLabel->setNum(actual_carbs);
        ui->profileProteinLabel->setNum(actual_proteins);
        ui->profileFatLabel->setNum(actual_fats);

        ui->kcalprogressBar->setValue(actual_kcal);
        ui->carbsprogressBar->setValue(actual_carbs);
        ui->proteinsprogressBar->setValue(actual_proteins);
        ui->fatsprogressBar->setValue(actual_fats);

        QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
        QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

        if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
        {
            QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
            dailyfile.deleteLater();
        }

        QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do pliku profilu dziennego
        out_daily_file<<actual_kcal<<endl;
        out_daily_file<<actual_carbs<<endl;
        out_daily_file<<actual_proteins<<endl;
        out_daily_file<<actual_fats<<endl;
        dailyfile.close();

        ui->teaTableWidget->removeRow(ui->teaTableWidget->currentRow()); // wykasowanie zaznaczonego wiersza w tabeli
        QFile::remove(QDir::currentPath()+"/Diaries/"+profile+"_"+date+"/Podwieczorek/"+name+".txt"); // usunięcie pliku posiłku o danej nazwie
    }
}

void diary::on_deleteSupperButton_clicked()
{

    QString date = ui->selectedDateLabel->text();
    QString profile = ui->profileNameLabel->text();
    int row = ui->supperTableWidget->currentRow();

    if(row == (-1))
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Najpierw wybierz posiłek z tabeli.");
        return;
    }
    else
    {
        QString name = ui->supperTableWidget->item(row,1)->text(); // zczytanie wartosci zaznaczonego posilku i konwersja do int
        QString calories = ui->supperTableWidget->item(row,2)->text();
        QString carbs = ui->supperTableWidget->item(row,3)->text();
        QString proteins = ui->supperTableWidget->item(row,4)->text();
        QString fats = ui->supperTableWidget->item(row,5)->text();

        int deleted_kcal = calories.toInt();
        int deleted_carbs = carbs.toInt();
        int deleted_proteins = proteins.toInt();
        int deleted_fats = fats.toInt();

        QString c_kcal = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu i konwersja do int
        int current_kcal = c_kcal.toInt();
        QString c_carbs = ui->profileCarbLabel->text();
        int current_carbs = c_carbs.toInt();
        QString c_proteins = ui->profileProteinLabel->text();
        int current_proteins = c_proteins.toInt();
        QString c_fats = ui->profileFatLabel->text();
        int current_fats = c_fats.toInt();

        int actual_kcal = current_kcal + deleted_kcal;
        int actual_carbs = current_carbs + deleted_carbs;
        int actual_fats = current_fats + deleted_fats;
        int actual_proteins = current_proteins + deleted_proteins;

        ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
        ui->profileCarbLabel->setNum(actual_carbs);
        ui->profileProteinLabel->setNum(actual_proteins);
        ui->profileFatLabel->setNum(actual_fats);

        ui->kcalprogressBar->setValue(actual_kcal);
        ui->carbsprogressBar->setValue(actual_carbs);
        ui->proteinsprogressBar->setValue(actual_proteins);
        ui->fatsprogressBar->setValue(actual_fats);

        QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
        QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

        if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
        {
            QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
            dailyfile.deleteLater();
        }

        QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do pliku profilu dziennego
        out_daily_file<<actual_kcal<<endl;
        out_daily_file<<actual_carbs<<endl;
        out_daily_file<<actual_proteins<<endl;
        out_daily_file<<actual_fats<<endl;
        dailyfile.close();

        ui->supperTableWidget->removeRow(ui->supperTableWidget->currentRow()); // wykasowanie zaznaczonego wiersza w tabeli
        QFile::remove(QDir::currentPath()+"/Diaries/"+profile+"_"+date+"/Kolacja/"+name+".txt"); // usunięcie pliku posiłku o danej nazwie
    }
}

void diary::on_deleteSnacksButton_clicked()
{

    QString date = ui->selectedDateLabel->text();
    QString profile = ui->profileNameLabel->text();
    int row = ui->snacksTableWidget->currentRow();

    if(row == (-1))
    {
        QMessageBox::warning(this,"Błąd aplikacji!","Najpierw wybierz posiłek z tabeli.");
        return;
    }
    else
    {
        QString name = ui->snacksTableWidget->item(row,1)->text(); // zczytanie wartosci zaznaczonego posilku i konwersja do int
        QString calories = ui->snacksTableWidget->item(row,2)->text();
        QString carbs = ui->snacksTableWidget->item(row,3)->text();
        QString proteins = ui->snacksTableWidget->item(row,4)->text();
        QString fats = ui->snacksTableWidget->item(row,5)->text();

        int deleted_kcal = calories.toInt();
        int deleted_carbs = carbs.toInt();
        int deleted_proteins = proteins.toInt();
        int deleted_fats = fats.toInt();

        QString c_kcal = ui->profileCalorieLabel->text(); // zczytanie wartosci z ekranu i konwersja do int
        int current_kcal = c_kcal.toInt();
        QString c_carbs = ui->profileCarbLabel->text();
        int current_carbs = c_carbs.toInt();
        QString c_proteins = ui->profileProteinLabel->text();
        int current_proteins = c_proteins.toInt();
        QString c_fats = ui->profileFatLabel->text();
        int current_fats = c_fats.toInt();

        int actual_kcal = current_kcal + deleted_kcal;
        int actual_carbs = current_carbs + deleted_carbs;
        int actual_fats = current_fats + deleted_fats;
        int actual_proteins = current_proteins + deleted_proteins;

        ui->profileCalorieLabel->setNum(actual_kcal); // zmiana wartosci na ekranie i wartosci suwakow
        ui->profileCarbLabel->setNum(actual_carbs);
        ui->profileProteinLabel->setNum(actual_proteins);
        ui->profileFatLabel->setNum(actual_fats);

        ui->kcalprogressBar->setValue(actual_kcal);
        ui->carbsprogressBar->setValue(actual_carbs);
        ui->proteinsprogressBar->setValue(actual_proteins);
        ui->fatsprogressBar->setValue(actual_fats);

        QString file_path = QDir::currentPath()+"/Diaries/"+ui->profileNameLabel->text()+"_"+ui->selectedDateLabel->text();
        QFile dailyfile(file_path+".txt"); // tworzenie profilu dziennego

        if(!dailyfile.open(QFile::WriteOnly | QFile::Text)) // sprawdzenie czy profil został prawidlowo otwarty
        {
            QMessageBox::warning(this,"Błąd aplikacji!","Plik profilu dziennego nie mógł zostać utworzony...");
            dailyfile.deleteLater();
        }

        QTextStream out_daily_file(&dailyfile); // wpisanie wartosci do pliku profilu dziennego
        out_daily_file<<actual_kcal<<endl;
        out_daily_file<<actual_carbs<<endl;
        out_daily_file<<actual_proteins<<endl;
        out_daily_file<<actual_fats<<endl;
        dailyfile.close();

        ui->snacksTableWidget->removeRow(ui->snacksTableWidget->currentRow()); // wykasowanie zaznaczonego wiersza w tabeli
        QFile::remove(QDir::currentPath()+"/Diaries/"+profile+"_"+date+"/Przekąski/"+name+".txt"); // usunięcie pliku posiłku o danej nazwie
    }
}