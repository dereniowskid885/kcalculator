#ifndef DIARY_H
#define DIARY_H

#include <QDialog>
#include <QDate>

namespace Ui {
class diary;
}

class diary : public QDialog
{
    Q_OBJECT

    public:
        explicit diary(QWidget *parent = nullptr, QDate date = QDate::currentDate(), QString profile_name = "", QString kcal = "", QString carbs = "", QString proteins = "", QString fats = "");
        ~diary();

    private slots:

        void on_exitButton_clicked();

        void on_addBreakfastButton_clicked();

        void on_addBreakfast_2Button_clicked();

        void on_addDinnerButton_clicked();

        void on_addTeaButton_clicked();

        void on_addSupperButton_clicked();

        void on_addSnacksButton_clicked();

        void on_backButton_clicked();

        void on_deleteBreakfastButton_clicked();

        void on_deleteBreakfastButton_2_clicked();

        void on_deleteDinnerButton_clicked();

        void on_deleteTeaButton_clicked();

        void on_deleteSupperButton_clicked();

        void on_deleteSnacksButton_clicked();

    private:
        Ui::diary *ui;
        enum Columns
        {
            AMOUNT,PRODUCT,CALORIES,CARBS,PROTEINS,FATS
        };
};

#endif // DIARY_H
