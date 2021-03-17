#ifndef ADDFOOD_H
#define ADDFOOD_H

#include <QDialog>

namespace Ui {
class addfood;
}

class addfood : public QDialog
{
    Q_OBJECT

public:
    explicit addfood(QWidget *parent = nullptr);
    ~addfood();

    QString product() const;
    int amount() const;
    int calories() const;
    int carbs() const;
    int proteins() const;
    int fats() const;

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::addfood *ui;
};

#endif // ADDFOOD_H
