#ifndef PASSWINDOW_H
#define PASSWINDOW_H

#include <QtGui>
#include <QtWidgets>
#include <QMessageBox>
#include <QFile>

class PassWindow : public QDialog
{
    Q_OBJECT
public:
    PassWindow(QWidget *parent = 0);
    ~PassWindow();

public slots:
    void OkButtonPress();
    void MyButtonPress();

private:
    QLabel *LogLabel;
    QLabel *PassLabel;
    QPushButton *OkButton;
    QPushButton *MyButton;
    QLineEdit *MyLogEdit;
    QLineEdit *MyPassEdit;
    QString errorString;
    QString userPass; //Пароль считанный из файла
    QString userFile; //Имя файла с номерами вопросов
   /* int userPassword;*/
    /*int filePassword;*/

};

#endif // PASSWINDOW_H
