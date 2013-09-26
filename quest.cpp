#include "quest.h"
#include "ui_quest.h"

Quest::Quest(QWidget *parent, QString dataFile) :
    QDialog(parent),
    ui(new Ui::Quest)
{
    ui->setupUi(this);

    studentRating=0;
    questNum=1;
    userFileName=dataFile;
    connect(ui->CancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->NextButton, SIGNAL(clicked()), this, SLOT(NextButtonPress()));

    getExamQuest();
    getQuestNumbers(dataFile);

    //Выводим первый вопрос
    ui->question->setText(task[questNumber[0]-1].question);
    ui->radioButton->setText(task[questNumber[0]-1].answer1);
    ui->radioButton_2->setText(task[questNumber[0]-1].answer2);
    ui->radioButton_3->setText(task[questNumber[0]-1].answer3);
}

Quest::~Quest()
{
    delete ui;
}

// Функция читает вопросы для экзамена и ответы к ним
void Quest::getExamQuest()
{
    quest myquest;

    QFile NamesFile("ExamQuest.txt");
    if(!NamesFile.exists())
    {
        QMessageBox *pmb=new QMessageBox (QMessageBox::Warning,tr("Error"), tr("File is not exist"), QMessageBox::Ok);
        pmb->exec();
        delete pmb;
    }
    if (!NamesFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox *pmb=new QMessageBox (QMessageBox::Warning,tr("Error"), tr("Cannot open file"), QMessageBox::Ok);
        pmb->exec();
        delete pmb;
    }

    QTextStream in(&NamesFile);

    //Заполнение вектора task
    while (!in.atEnd())
    {
        myquest.question=in.readLine();
        myquest.answer1=in.readLine();
        myquest.rightAns1=in.readLine().toInt();
        myquest.answer2=in.readLine();
        myquest.rightAns2=in.readLine().toInt();
        myquest.answer3=in.readLine();
        myquest.rightAns3=in.readLine().toInt();
        task.push_back(myquest);
    }
    NamesFile.close();
}

//Функция читает номера вопросов для экзамена
void Quest::getQuestNumbers(QString dataFile)
{
    QFile NamesFile(dataFile);
    if(!NamesFile.exists())
    {
        QMessageBox *pmb=new QMessageBox (QMessageBox::Warning,tr("Error"), tr("File is not exist"), QMessageBox::Ok);
        pmb->exec();
        delete pmb;
    }
    if (!NamesFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox *pmb=new QMessageBox (QMessageBox::Warning,tr("Error"), tr("Cannot open file"), QMessageBox::Ok);
        pmb->exec();
        delete pmb;
    }

    QTextStream in(&NamesFile);
    mystr=in.readLine();
    while (!in.atEnd())
    {
        questNumber.push_back(in.readLine().toInt());
    }
    NamesFile.close();
}

//Следующий вопрос
void Quest::NextButtonPress()
{
    if((ui->radioButton->isChecked() && task[questNumber[questNum-1]-1].rightAns1) ||
       (ui->radioButton_2->isChecked() && task[questNumber[questNum-1]-1].rightAns2) ||
       (ui->radioButton_3->isChecked() && task[questNumber[questNum-1]-1].rightAns3))
    {
        studentRating++;
    }
    if(questNum >= maxQuestion)
    {
        ExitFunc(studentRating, userFileName);
        delete this;
        return ;
    }

    ui->question->setText(task[questNumber[questNum]-1].question);
    ui->radioButton->setText(task[questNumber[questNum]-1].answer1);
    ui->radioButton_2->setText(task[questNumber[questNum]-1].answer2);
    ui->radioButton_3->setText(task[questNumber[questNum]-1].answer3);
    questNum++;

    if(ui->radioButton->isChecked()) ui->radioButton->setChecked(false);
    if(ui->radioButton_2->isChecked()) ui->radioButton_2->setChecked(false);
    if(ui->radioButton_3->isChecked()) ui->radioButton_3->setChecked(false);

}

void Quest::ExitFunc(int studentRating, QString dataFile)
{
    mystr=QString::number(studentRating);
    FinalWindow *MyFinal=new FinalWindow(mystr, dataFile);
    MyFinal->show();
}
