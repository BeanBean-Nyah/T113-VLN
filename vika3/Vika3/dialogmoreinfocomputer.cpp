#include "dialogmoreinfocomputer.h"
#include "ui_dialogmoreinfocomputer.h"

DialogMoreInfoComputer::DialogMoreInfoComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMoreInfoComputer)
{
    ui->setupUi(this);
}

DialogMoreInfoComputer::~DialogMoreInfoComputer()
{
    delete ui;
}

void DialogMoreInfoComputer::setInfo(string& _ID, string &_name, string &_year, string &_type, string &_built, string &_about)
{
    name = QString::fromStdString(_name);
    year = QString::fromStdString(_year);
    type = QString::fromStdString(_type);
    built = QString::fromStdString(_built);

    id = _ID;

    string sabout = domain.aboutComputer(_ID);
    about = QString::fromStdString(sabout);

    QByteArray outByteArray = domain.getPicComputer(id);
    QPixmap outPixmap = QPixmap();
    outPixmap.loadFromData( outByteArray );



    ui->label_name->setText(name);
    ui->label_year->setText(year);
    ui->label_type->setText(type);
    ui->label_built->setText(built);
    ui->label_image->setPixmap(
        outPixmap.scaled(250, 250, Qt::IgnoreAspectRatio, Qt::FastTransformation));


    ui->textEdit_bio->setText(about);
}

void DialogMoreInfoComputer::on_btnBrowse_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                        this,
                        "Browse for image",
                        "",
                        "Image Files (*.png *.jpg *.bmp)"
                    );



    if(filename.endsWith(".jpg",Qt::CaseSensitive) || filename.endsWith(".png",Qt::CaseSensitive) ||
            filename.endsWith(".bmp",Qt::CaseSensitive))
    {
        if (filename.length())
        {
            QPixmap pixmap(filename);
            ui->label_image->setPixmap(
                pixmap.scaled(250, 250, Qt::IgnoreAspectRatio, Qt::FastTransformation));
            QByteArray inByteArray;
            QBuffer inBuffer( &inByteArray );
            inBuffer.open( QIODevice::WriteOnly );
            pixmap.save( &inBuffer, "PNG" );
            domain.pictureComputer(id, inByteArray);
        }
    }
    else
    {
          ui->label_errmsg->setText("Invalid filetype!");
    }


}

void DialogMoreInfoComputer::on_pushButton_edit_bio_clicked()
{
    ui->pushButton_save_bio->setEnabled(true);
    ui->pushButton_edit_bio->setEnabled(false);
    ui->textEdit_bio->setReadOnly(false);
}

void DialogMoreInfoComputer::on_pushButton_save_bio_clicked()
{
    QString newText = ui->textEdit_bio->toPlainText();
    domain.editInfoComputer(id, newText);
    ui->pushButton_save_bio->setEnabled(false);
    ui->pushButton_edit_bio->setEnabled(true);
    ui->textEdit_bio->setReadOnly(true);
}
