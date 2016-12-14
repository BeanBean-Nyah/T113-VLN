#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

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
    void setTextbox(string& _name, string& _sex, string& _birth, string& _death);
    ~dialogEdit();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::dialogEdit *ui;
    QString name;
    QString sex;
    QString birth;
    QString death;
};

#endif // DIALOGEDIT_H
