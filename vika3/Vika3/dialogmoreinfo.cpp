#include "dialogmoreinfo.h"
#include "ui_dialogmoreinfo.h"

DialogMoreInfo::DialogMoreInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMoreInfo)
{
    ui->setupUi(this);
}

DialogMoreInfo::~DialogMoreInfo()
{
    delete ui;
}

void DialogMoreInfo::setInfo(string& _ID, string &_name, string &_birth, string &_death, string &_about)
{
    name = QString::fromStdString(_name);
    sex  = QString::fromStdString(_about);
    birth = QString::fromStdString(_birth);
    death = QString::fromStdString(_death);
    id = _ID;


    ui->label_name->setText(name);
    ui->label_birth->setText(birth);
    ui->label_death->setText(death);
    ui->textEdit_bio->setText(sex);
}

void DialogMoreInfo::on_btnBrowse_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                        this,
                        "Browse for image",
                        "",
                        "Image Files (*.png *.jpg *.bmp)"
                    );

    if (filename.length())
    {
        QPixmap pixmap(filename);
        ui->label_image->setPixmap(pixmap);

    }
    else
    {

    }
}






























void DialogMoreInfo::on_pushButton_edit_bio_clicked()
{
    ui->pushButton_save_bio->setEnabled(true);
    ui->pushButton_edit_bio->setEnabled(false);
    ui->textEdit_bio->setEnabled(true);
}

void DialogMoreInfo::on_pushButton_save_bio_clicked()
{
    ui->pushButton_save_bio->setEnabled(false);
    ui->pushButton_edit_bio->setEnabled(true);
}
