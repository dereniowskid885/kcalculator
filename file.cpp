#include "file.h"
#include "ui_browseprofiles.h"
#include "browseprofiles.h"
#include <QFile>
#include <profiles.h>
#include <QTextStream>
#include <QDir>
#include <QMessageBox>

File::File()
{

}

File::~File()
{

}

int File::get_daily_Calories(QString profile_name)
{
    QFile file(QDir::currentPath()+"/Diaries/"+profile_name+".txt"); //zdefiniowanie sciezki pliku na podstawie parametru nazwy profilu
        if(!file.open(QFile::ReadOnly | QFile::Text)) // sprawdzenie czy plik zostal otwarty
        {
        }
        QTextStream in(&file); // zczytanie linijek z pliku
        QString calories = in.readLine(0);
        int kcal = calories.toInt();
        return kcal;
}

int File::get_daily_Carbs(QString profile_name)
{
    QFile file(QDir::currentPath()+"/Diaries/"+profile_name+".txt"); //zdefiniowanie sciezki pliku na podstawie parametru nazwy profilu
        if(!file.open(QFile::ReadOnly | QFile::Text)) // sprawdzenie czy plik zostal otwarty
        {
        }
        QTextStream in(&file); // zczytanie linijek z pliku
        QString calories = in.readLine(0);
        QString carbs = in.readLine(0);
        int carbohydrates = carbs.toInt();
        return carbohydrates;
}

int File::get_daily_Proteins(QString profile_name)
{
    QFile file(QDir::currentPath()+"/Diaries/"+profile_name+".txt"); //zdefiniowanie sciezki pliku na podstawie parametru nazwy profilu
        if(!file.open(QFile::ReadOnly | QFile::Text)) // sprawdzenie czy plik zostal otwarty
        {
        }
        QTextStream in(&file); // zczytanie linijek z pliku
        QString calories = in.readLine(0);
        QString carbs = in.readLine(0);
        QString proteins = in.readLine(0);
        int protein = proteins.toInt();
        return protein;
}

int File::get_daily_Fats(QString profile_name)
{
    QFile file(QDir::currentPath()+"/Diaries/"+profile_name+".txt");  //zdefiniowanie sciezki pliku na podstawie parametru nazwy profilu
        if(!file.open(QFile::ReadOnly | QFile::Text)) // sprawdzenie czy plik zostal otwarty
        {
        }
        QTextStream in(&file);  // zczytanie linijek z pliku
        QString calories = in.readLine(0);
        QString carbs = in.readLine(0);
        QString proteins = in.readLine(0);
        QString fats = in.readLine(0);
        int fat = fats.toInt();
        return fat;
}

QString File::getName(QString profile_name)
{
    QFile file(QDir::currentPath()+"/Profiles/"+profile_name+".txt"); //zdefiniowanie sciezki pliku na podstawie parametru nazwy profilu
        if(!file.open(QFile::ReadOnly | QFile::Text)) // sprawdzenie czy plik zostal otwarty
        {
        }
        QTextStream in(&file); // zczytanie linijek z pliku
        QString name = in.readLine(0);
        return name;
}

int File::getCalories(QString profile_name)
{
    QFile file(QDir::currentPath()+"/Profiles/"+profile_name+".txt"); //zdefiniowanie sciezki pliku na podstawie parametru nazwy profilu
        if(!file.open(QFile::ReadOnly | QFile::Text)) // sprawdzenie czy plik zostal otwarty
        {
        }

        QTextStream in(&file); // zczytanie linijek z pliku
        QString name = in.readLine(0);
        QString age = in.readLine(0);
        QString height = in.readLine(0);
        QString weight = in.readLine(0);
        QString activity_level = in.readLine(0);
        QString goalCalories = in.readLine(0);
        QString sex = in.readLine(0);
        activity_level.replace(1,1,".");  // zamiana przecinka na kropke, w celu uzyskania typu float

        int a = age.toInt(); // konwersja na typ int
        int h = height.toInt();
        int w = weight.toInt();
        float al = activity_level.toFloat();
        int gc = goalCalories.toInt();

        int ppm = (10*w)+(6.25*h)-(5*a); // obliczanie PPM na podstawie wzoru Mifflina

        if(sex == "male")
        {
            ppm += 5;
        }
        else if(sex == "female")
        {
            ppm -=161;
        }

        int cpm = (ppm * al) + gc; // obliczanie CPM, oraz dodanie, badz usuniecie dodatkowych kalorii w zaleznosci od celu
        return cpm;
}

int File::getCarbs(QString profile_name)
{
    QFile file(QDir::currentPath()+"/Profiles/"+profile_name+".txt"); //zdefiniowanie sciezki pliku na podstawie parametru nazwy profilu
        if(!file.open(QFile::ReadOnly | QFile::Text)) // sprawdzenie czy plik zostal otwarty
        {
        }

        QTextStream in(&file); // zczytanie linijek z pliku
        QString name = in.readLine(0);
        QString age = in.readLine(0);
        QString height = in.readLine(0);
        QString weight = in.readLine(0);
        QString activity_level = in.readLine(0);
        QString goalCalories = in.readLine(0);
        QString sex = in.readLine(0);
        activity_level.replace(1,1,"."); // zamiana przecinka na kropke, w celu uzyskania typu float

        int a = age.toInt(); // konwersja na typ int
        int h = height.toInt();
        int w = weight.toInt();
        float al = activity_level.toFloat();
        int gc = goalCalories.toInt();

        int ppm = (10*w)+(6.25*h)-(5*a); // obliczanie PPM na podstawie wzoru Mifflina

        if(sex == "male")
        {
            ppm += 5;
        }
        else if(sex == "female")
        {
            ppm -=161;
        }

        int cpm = (ppm * al) + gc; // obliczanie CPM, oraz dodanie, badz usuniecie dodatkowych kalorii w zaleznosci od celu
        int carbsCalories = 0.5*cpm;
        int carbs = carbsCalories/4; // wyznaczenie ilosci weglowodanow
        return carbs;
}

int File::getFats(QString profile_name)
{
    QFile file(QDir::currentPath()+"/Profiles/"+profile_name+".txt"); //zdefiniowanie sciezki pliku na podstawie parametru nazwy profilu
        if(!file.open(QFile::ReadOnly | QFile::Text)) // sprawdzenie czy plik zostal otwarty
        {
        }

        QTextStream in(&file); // zczytanie linijek z pliku
        QString name = in.readLine(0);
        QString age = in.readLine(0);
        QString height = in.readLine(0);
        QString weight = in.readLine(0);
        QString activity_level = in.readLine(0);
        QString goalCalories = in.readLine(0);
        QString sex = in.readLine(0);
        activity_level.replace(1,1,"."); // zamiana przecinka na kropke, w celu uzyskania typu float

        int a = age.toInt(); // konwersja na typ int
        int h = height.toInt();
        int w = weight.toInt();
        float al = activity_level.toFloat();
        int gc = goalCalories.toInt();

        int ppm = (10*w)+(6.25*h)-(5*a); // obliczanie PPM na podstawie wzoru Mifflina

        if(sex == "male")
        {
            ppm += 5;
        }
        else if(sex == "female")
        {
            ppm -=161;
        }

        int cpm = (ppm * al) + gc; // obliczanie CPM, oraz dodanie, badz usuniecie dodatkowych kalorii w zaleznosci od celu
        int fatsCalories = 0.25*cpm;
        int fats = fatsCalories/9; // wyznaczenie ilosci tluszczy
        return fats;
}

int File::getProteins(QString profile_name)
{
    QFile file(QDir::currentPath()+"/Profiles/"+profile_name+".txt"); //zdefiniowanie sciezki pliku na podstawie parametru nazwy profilu
        if(!file.open(QFile::ReadOnly | QFile::Text)) // sprawdzenie czy plik zostal otwarty
        {
        }

        QTextStream in(&file); // zczytanie linijek z pliku
        QString name = in.readLine(0);
        QString age = in.readLine(0);
        QString height = in.readLine(0);
        QString weight = in.readLine(0);
        QString activity_level = in.readLine(0);
        QString goalCalories = in.readLine(0);
        QString sex = in.readLine(0);
        activity_level.replace(1,1,"."); // zamiana przecinka na kropke, w celu uzyskania typu float

        int a = age.toInt(); // konwersja na typ int
        int h = height.toInt();
        int w = weight.toInt();
        float al = activity_level.toFloat();
        int gc = goalCalories.toInt();

        int ppm = (10*w)+(6.25*h)-(5*a); // obliczanie PPM na podstawie wzoru Mifflina

        if(sex == "male")
        {
            ppm += 5;
        }
        else if(sex == "female")
        {
            ppm -=161;
        }

        int cpm = (ppm * al) + gc; // obliczanie CPM, oraz dodanie, badz usuniecie dodatkowych kalorii w zaleznosci od celu
        int proteinsCalories = 0.25*cpm;
        int proteins = proteinsCalories/4; // wyznaczenie ilosci bialka
        return proteins;
}