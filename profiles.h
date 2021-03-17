#ifndef PROFILES_H
#define PROFILES_H

#include <QDialog>

namespace Ui {
class Profiles;
}

class Profiles : public QDialog
{
    Q_OBJECT

    public:
        explicit Profiles(QWidget *parent = nullptr);
        ~Profiles();

    private slots:
        void on_Exit_clicked();

        void on_New_profile_button_clicked();

        void on_Browse_profiles_button_clicked();

    private:
        Ui::Profiles *ui;
};

#endif // PROFILES_H