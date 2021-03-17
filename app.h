#ifndef APP_H
#define APP_H

#include <QDialog>

namespace Ui {
class app;
}

class app : public QDialog
{
    Q_OBJECT

    public:
        explicit app(QWidget *parent = nullptr, QString name = "");
        ~app();

    private slots:
        void on_backButton_clicked();

        void on_helpButton_clicked();

        void on_exitButton_clicked();

        void on_calendarWidget_clicked(const QDate &date);

    private:
        Ui::app *ui;
};

#endif // APP_H
