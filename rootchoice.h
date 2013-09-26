#ifndef ROOTCHOICE_H
#define ROOTCHOICE_H

#include <QDialog>
#include <QtWidgets>
#include "LearnWindow.h"

namespace Ui {
class RootChoice;
}

class RootChoice : public QDialog
{
    Q_OBJECT
    
public:
    explicit RootChoice(QWidget *parent = 0);
    ~RootChoice();
public slots:
    void DataEditPress();
    void ResultViewPress();
    void ProgFinished();

private:
    Ui::RootChoice *ui;
};

#endif // ROOTCHOICE_H
