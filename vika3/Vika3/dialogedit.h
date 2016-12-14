#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H


#include "Domain.h"

#include <QDialog>
#include <QDebug>

using namespace std;

namespace Ui {
class dialogEdit;
}

class dialogEdit : public QDialog
{
    Q_OBJECT

public:
    explicit dialogEdit(QWidget *parent = 0); 
    ~dialogEdit();

    void setTextbox(string& _name, string& _sex, string& _birth, string& _death, string& _ID);

    string getName()
    {
        return name.toStdString();
    }
    string getSex()
    {
        return sex.toStdString();
    }
    string getBirt()
    {
        return birth.toStdString();
    }
    string getDeath()
    {
        return death.toStdString();
    }

private slots:
    void on_buttonBox_accepted();

private:
    Ui::dialogEdit *ui;
    QString name;
    QString sex;
    QString birth;
    QString death;
    Domain domain;

    string id;
};

#endif // DIALOGEDIT_H
