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

    QByteArray outByteArray = domain.getPic(id);
    QPixmap outPixmap = QPixmap();
    outPixmap.loadFromData( outByteArray );


    ui->label_name->setText(name);
    ui->label_birth->setText(birth);
    ui->label_death->setText(death);
    ui->textEdit_bio->setText(sex);
    ui->label_image->setPixmap(
        outPixmap.scaled(250, 250, Qt::IgnoreAspectRatio, Qt::FastTransformation));


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
        ui->label_image->setPixmap(
            pixmap.scaled(250, 250, Qt::IgnoreAspectRatio, Qt::FastTransformation));
        QByteArray inByteArray;
        QBuffer inBuffer( &inByteArray );
        inBuffer.open( QIODevice::WriteOnly );
        pixmap.save( &inBuffer, "PNG" );
        domain.picture(id, inByteArray);

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
    ui->textEdit_bio->setEnabled(false);
}
