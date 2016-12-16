#include "dialogfunfact.h"
#include "ui_dialogfunfact.h"

DialogFunFact::DialogFunFact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFunFact)
{
    ui->setupUi(this);
    string fact = domain.funFact();
    QString ffact = QString::fromStdString(fact);
    ui->label_funfact->setText(ffact);
}

DialogFunFact::~DialogFunFact()
{
    delete ui;
}

void DialogFunFact::on_pushButton_newfact_clicked()
{
    string fact = domain.funFact();
    QString ffact = QString::fromStdString(fact);
    ui->label_funfact->setText(ffact);
}
