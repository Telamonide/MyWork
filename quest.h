#ifndef QUEST_H
#define QUEST_H

#include <QDialog>
#include <QFile>
#include <QtWidgets>
#include <QMessageBox>
#include <QVector>
#include "finalwindow.h"

#define maxQuestion 3

namespace Ui {
class Quest;
}

class Quest : public QDialog
{
    Q_OBJECT
    
public:
    explicit Quest(QWidget *parent = 0, QString dataFile="Foo");
    ~Quest();

public slots:
    void NextButtonPress();
    
private:
    Ui::Quest *ui;
    int studentRating; //Оценка
    int questNum;
    QString mystr; //Переменная для разных целей
    QString userFileName;

    //Структура описывает вопрос и ответы
    struct quest
    {
        QString question;
        QString answer1;
        int rightAns1;
        QString answer2;
        int rightAns2;
        QString answer3;
        int rightAns3;
    };

    QVector<quest> task;
    QVector<int>  questNumber;

    void getExamQuest(); // Функция читает вопросы для экзамена и ответы к ним
    void getQuestNumbers(QString dataFile); //Функция читает номера вопросов для экзамена
    void ExitFunc(int studentRating, QString dataFile);

};

#endif // QUEST_H
