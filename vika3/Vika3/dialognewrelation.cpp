#include "dialognewrelation.h"
#include "ui_dialognewrelation.h"

DialogNewRelation::DialogNewRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewRelation)
{
    ui->setupUi(this);
}

DialogNewRelation::~DialogNewRelation()
{
    delete ui;
}
