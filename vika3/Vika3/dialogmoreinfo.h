#ifndef DIALOGMOREINFO_H
#define DIALOGMOREINFO_H

#include "Domain.h"

#include <QDialog>
#include <QFileDialog>
#include <QPixmap>

namespace Ui {
class DialogMoreInfo;
}

class DialogMoreInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMoreInfo(QWidget *parent = 0);
    ~DialogMoreInfo();

    void setInfo(string& ID, string& name, string& birth, string& death, string& about);

private slots:

    void on_btnBrowse_clicked();

    void on_pushButton_edit_bio_clicked();

    void on_pushButton_save_bio_clicked();

private:
    Ui::DialogMoreInfo *ui;
    QString name;
    QString sex;
    QString birth;
    QString death;
    Domain domain;

    string id;
};

#endif // DIALOGMOREINFO_H
