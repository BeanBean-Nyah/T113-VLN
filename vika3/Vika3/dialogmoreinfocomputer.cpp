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
