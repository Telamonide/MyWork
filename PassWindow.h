#ifndef PASSWINDOW_H
#define PASSWINDOW_H

#include <QtGui>

class PassWindow : public QDialog
{
    Q_OBJECT
public:
    PassWindow(QWidget *parent = 0);
    
signals:
    
public slots:
    void OkButtonPress();
    void MyButtonPress();

private:
    QLabel *PassLabel;
    QPushButton *OkButton;
    QPushButton *MyButton;
    QLineEdit *MyPassEdit;
    
};

#endif // PASSWINDOW_H
