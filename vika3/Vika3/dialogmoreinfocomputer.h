#ifndef DIALOGMOREINFOCOMPUTER_H
#define DIALOGMOREINFOCOMPUTER_H

#include <QDialog>

namespace Ui {
class DialogMoreInfoComputer;
}

class DialogMoreInfoComputer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMoreInfoComputer(QWidget *parent = 0);
    ~DialogMoreInfoComputer();

private:
    Ui::DialogMoreInfoComputer *ui;
};

#endif // DIALOGMOREINFOCOMPUTER_H
