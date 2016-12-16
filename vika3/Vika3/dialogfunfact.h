#ifndef DIALOGFUNFACT_H
#define DIALOGFUNFACT_H

#include <QDialog>
#include "Domain.h"
#include <QString>

namespace Ui {
class DialogFunFact;
}

class DialogFunFact : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFunFact(QWidget *parent = 0);
    ~DialogFunFact();

private slots:
    void on_pushButton_newfact_clicked();

private:
    Ui::DialogFunFact *ui;
    Domain domain;
};

#endif // DIALOGFUNFACT_H
