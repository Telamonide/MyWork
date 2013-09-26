#include "testdialog.h"
#include "ui_testdialog.h"

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    ui->setupUi(this);
    connect (ui->pushButton, SIGNAL(clicked()), this, SLOT (pressButtonCancel()));
    connect (ui->pushButtonOk, SIGNAL(clicked()), this, SLOT (pressButtonOk()));
}

TestDialog::~TestDialog()
{
    delete ui;
}

//Обработка нажатия кнопки отмены
void TestDialog::pressButtonCancel()
{
    QWidget::parentWidget()->show();
    delete this;
}

//Обработка нажатия кнопки Ок
void TestDialog::pressButtonOk()
{
    QFile NamesFile("Students.txt");
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

    //Поиск пароля пользователя
    while (!in.atEnd())
    {
        QString strLog=in.readLine();
        QString strPass=in.readLine();
        if(QString::compare(strLog, ui->lineEdit->text())==0)
        {
            strLog=tr("Your login is: ")+strLog;
            strPass=tr("Your Pass is: ")+strPass;
            strLog=strLog+"\n\n"+strPass;
            QMessageBox *pmb=new QMessageBox(QMessageBox::Information, tr("Password"), strLog, QMessageBox::Ok);
            pmb->exec();
            delete pmb;
            break;
        }

        //Пароль не найден
        if(in.atEnd())
        {
            QMessageBox *pmb=new QMessageBox (QMessageBox::Warning, tr("Error"), tr("This login is not registered"), QMessageBox::Ok);
            pmb->exec();
            delete pmb;
        }
    }
    NamesFile.close();
    QWidget::parentWidget()->show();
    delete this;
}
