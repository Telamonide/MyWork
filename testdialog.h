#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <QFile>
#include <QString>
#include <QMessageBox>
//#include <QDebug>

//Pеализует определение пароля для пользователя

namespace Ui {
class TestDialog;
}

class TestDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TestDialog(QWidget *parent = 0);
    ~TestDialog();

public slots:
    void pressButtonOk();
    void pressButtonCancel();
    
private:
    Ui::TestDialog *ui;
};

#endif // TESTDIALOG_H


