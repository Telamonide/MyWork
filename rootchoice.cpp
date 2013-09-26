#include "rootchoice.h"
#include "ui_rootchoice.h"

RootChoice::RootChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RootChoice)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(DataEditPress()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ResultViewPress()));
}

RootChoice::~RootChoice()
{
    delete ui;
}

//Режим редактирования
void RootChoice::DataEditPress()
{
    this->hide();
    QProcess *vec = new QProcess(this);
    vec->start("application.exe");

//Дожидаемся конца работы приложения
    connect(vec, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(ProgFinished()));
}

//Просмотр результатов
void RootChoice::ResultViewPress()
{
    this->hide();
    LearnWindow *NextWindow=new LearnWindow(QWidget::parentWidget(), "Result.txt", tr("Test results"));
    NextWindow->show();
}

//Действия после закрытия внешнего приложения
void RootChoice::ProgFinished()
{
    QDialog::parentWidget()->show();
    delete this;
}
