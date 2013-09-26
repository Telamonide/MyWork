#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QtWidgets/QDialog>
#include <QtWidgets>

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = 0);
    ~StartWindow();

public slots:
    void pressLearn(); //Выбор режима обучения
    void pressEditMode(); //Режим администратора
    void pressGetPass(); //Получение пароля
    void pressTest(); //Прохождение теста

private:
//Элементы инерфейса
    QLabel *label;
    QPushButton *EditModeButton;
    QPushButton *LearnButton;
    QPushButton *TestButton;
    QPushButton *CloseButton;
    QPushButton *GetPassButton;
};

#endif // STARTWINDOW_H
