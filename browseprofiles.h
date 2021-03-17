#ifndef BROWSEPROFILES_H
#define BROWSEPROFILES_H

#include <QDialog>

namespace Ui {
class browseprofiles;
}

class browseprofiles : public QDialog
{
    Q_OBJECT

    public:
        explicit browseprofiles(QWidget *parent = nullptr);
        ~browseprofiles();

    private slots:
        void on_exitButton_clicked();

        void on_backButton_clicked();

        void on_OKButton_clicked();

        void on_deleteButton_clicked();

    private:
        Ui::browseprofiles *ui;

};

#endif // BROWSEPROFILES_H