#ifndef NEWPROFILE_H
#define NEWPROFILE_H

#include <QDialog>

namespace Ui {
class NewProfile;
}

class NewProfile : public QDialog
{
    Q_OBJECT

    public:
        explicit NewProfile(QWidget *parent = nullptr);
        ~NewProfile();

    private slots:
        void on_exitButton_clicked();

        void on_tipButton_clicked();

        void on_backButton_clicked();

        void on_OKButton_clicked();

    private:
        Ui::NewProfile *ui;
};

#endif // NEWPROFILE_H