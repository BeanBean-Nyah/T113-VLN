#ifndef DIALOGNEWRELATION_H
#define DIALOGNEWRELATION_H

#include <QDialog>

namespace Ui {
class DialogNewRelation;
}

class DialogNewRelation : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewRelation(QWidget *parent = 0);
    ~DialogNewRelation();

private:
    Ui::DialogNewRelation *ui;
};

#endif // DIALOGNEWRELATION_H
