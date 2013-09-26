#include "finalwindow.h"
#include "ui_finalwindow.h"

FinalWindow::FinalWindow(QString studentRating, QString studentName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FinalWindow)
{
    ui->setupUi(this);
    connect(ui->FinishButton, SIGNAL(clicked()), this, SLOT(close()));

    QFile NamesFile("Result.txt");

    //Запись в файл
    if (NamesFile.open(QFile::Append | QFile::Text))
    {
        QTextStream out(&NamesFile);
        //Выделение имени студента
        studName=studentName.split(".");

        out<<studName.first()<<"\t";
        out<<studentRating<<endl;
    }
    NamesFile.close();
    //Вывод результата в окно
    resultString=tr("You answered correctly on ")+studentRating+tr(" question(s)");
    ui->label->setText(resultString);
}

FinalWindow::~FinalWindow()
{
    delete ui;
}
