#ifndef DIALOGMOREINFOCOMPUTER_H
#define DIALOGMOREINFOCOMPUTER_H

#include "Domain.h"

#include <QDialog>
#include <QFileDialog>
#include <QPixmap>
#include <QBuffer>

namespace Ui {
class DialogMoreInfoComputer;
}

class DialogMoreInfoComputer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMoreInfoComputer(QWidget *parent = 0);
    ~DialogMoreInfoComputer();

    void setInfo(string& _ID, string &_name, string &_year, string &_type, string &_built, string &_about);

private slots:
    void on_btnBrowse_clicked();

    void on_pushButton_edit_bio_clicked();

    void on_pushButton_save_bio_clicked();

private:
    Ui::DialogMoreInfoComputer *ui;

    QString name;
    QString year;
    QString type;
    QString built;
    QString about;
    Domain domain;

    string id;
};

#endif // DIALOGMOREINFOCOMPUTER_H
