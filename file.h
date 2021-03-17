#ifndef FILE_H
#define FILE_H

#include <QString>

class File
{
    QString name,sex;
    int age,height,weight,activity_level,kcal;

    public:
        File();
        QString getName(QString profile_name);
        int getCalories(QString profile_name);
        int getCarbs(QString profile_name);
        int getProteins(QString profile_name);
        int getFats(QString profile_name);
        int get_daily_Calories(QString profile_name);
        int get_daily_Carbs(QString profile_name);
        int get_daily_Proteins(QString profile_name);
        int get_daily_Fats(QString profile_name);
        ~File();
};

#endif // FILE_H