#include "addfood.h"
#include "ui_addfood.h"

addfood::addfood(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addfood)
{
    ui->setupUi(this);
}

addfood::~addfood()
{
    delete ui;
}

void addfood::on_buttonBox_accepted()
{
    accept();
}

void addfood::on_buttonBox_rejected()
{
    reject();
}

QString addfood::product() const
{
    return ui->itemLineEdit->text(); // zwrocenie wartosci z formularza
}

int addfood::amount() const
{
    return ui->amountSpinBox->value(); // zwrocenie wartosci z formularza
}

int addfood::calories() const
{
    return ui->kcalSpinBox->value(); // zwrocenie wartosci z formularza
}

int addfood::carbs() const
{
    return ui->carbsSpinBox->value(); // zwrocenie wartosci z formularza
}

int addfood::proteins() const
{
    return ui->proteinsSpinBox->value(); // zwrocenie wartosci z formularza
}

int addfood::fats() const
{
    return ui->fatsSpinBox->value(); // zwrocenie wartosci z formularza
}