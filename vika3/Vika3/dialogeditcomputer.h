#ifndef DIALOGEDITCOMPUTER_H
#define DIALOGEDITCOMPUTER_H

#include "Domain.h"
#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class DialogEditComputer;
}

class DialogEditComputer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditComputer(QWidget *parent = 0);
    ~DialogEditComputer();

    void setTextbox(string& _name, string& _year, string& _type, string& _built, string& _ID);

    string getName()
    {
        return name.toStdString();
    }
    string getSex()
    {
        return year.toStdString();
    }
    string getBirt()
    {
        return type.toStdString();
    }
    string getDeath()
    {
        return built.toStdString();
    }

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::DialogEditComputer *ui;
    QString name;
    QString year;
    QString type;
    QString built;
    Domain domain;

    string id;
};

#endif // DIALOGEDITCOMPUTER_H
