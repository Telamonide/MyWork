#include <QtGui>
#include "PassWindow.h"
#include "quest.h"
#include "rootchoice.h"

#define MyRootPass 12345678

PassWindow::PassWindow(QWidget *parent) :
    QDialog(parent)
{
    LogLabel=new QLabel(tr("Enter Login:"));
    PassLabel=new QLabel(tr("Enter Password:"));
    OkButton=new QPushButton(tr("Ok"));
    MyButton=new QPushButton(tr("Cancel"));
    MyLogEdit=new QLineEdit;
    MyPassEdit=new QLineEdit;
    MyPassEdit->setEchoMode(QLineEdit::Password);//Secure pass entering

    connect(OkButton, SIGNAL(clicked()), this, SLOT(OkButtonPress()));
    connect(MyButton, SIGNAL(clicked()), this, SLOT(MyButtonPress()));

    QHBoxLayout *HorLayout=new QHBoxLayout;
    HorLayout->addStretch();
    HorLayout->addWidget(OkButton);
    HorLayout->addWidget(MyButton);
    HorLayout->addStretch();

    QHBoxLayout *topLayout=new QHBoxLayout;
    topLayout->addWidget(LogLabel);
    topLayout->addWidget(MyLogEdit);

    QHBoxLayout *lowLayout=new QHBoxLayout;
    lowLayout->addWidget(PassLabel);
    lowLayout->addWidget(MyPassEdit);

    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(lowLayout);
    mainLayout->addLayout(HorLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("Password"));
}

PassWindow::~PassWindow()
{
    delete LogLabel;
    delete PassLabel;
    delete OkButton;
    delete MyButton;
    delete MyLogEdit;
    delete MyPassEdit;
}

void PassWindow::MyButtonPress()
{
    parentWidget()->show();
    delete this;
}

void PassWindow::OkButtonPress()
{
    //Проверка записи пользователя
    if((MyLogEdit->text()=="Root")&&(MyPassEdit->text()==QString::number(MyRootPass)))
    {
        RootChoice *RootChoiceWindow=new RootChoice(QWidget::parentWidget());
        this->hide();
        RootChoiceWindow->show();
        delete this;
    }
    else
    {
        userFile=MyLogEdit->text()+".txt";
        QFile NamesFile(userFile);
        if(!NamesFile.exists())
        {
            //Ошибка отсутствия файла
            errorString=tr("User ")+MyLogEdit->text()+tr(" is not registered");
            QMessageBox *pmb=new QMessageBox (QMessageBox::Warning,tr("Error"), errorString, QMessageBox::Ok);
            pmb->exec();
            delete pmb;
            QWidget::parentWidget()->show();
            delete this;
        }
        else
        {
            if (!NamesFile.open(QFile::ReadOnly | QFile::Text))
            {
                //Невозможно открыть файл
                QMessageBox *pmb=new QMessageBox (QMessageBox::Warning,tr("Error"), tr("Cannot open file"), QMessageBox::Ok);
                pmb->exec();
                delete pmb;
                QWidget::parentWidget()->show();
                delete this;
            }

            QTextStream in(&NamesFile);
            userPass=in.readLine();

            //Проверка пароля введенного пользователем
            if(QString::compare(userPass, MyPassEdit->text())!=0)
            {
                errorString=tr("Password for user\n")+"         "+MyLogEdit->text()+tr("\n       is not valid");
                QMessageBox *pmb=new QMessageBox (QMessageBox::Warning,tr("Error"), errorString, QMessageBox::Ok);
                pmb->exec();
                delete pmb;
                NamesFile.close();
                //переход к предыдущему окну
                QWidget::parentWidget()->show();
                delete this;
                return;
            }
            NamesFile.close();
            //Открытия окна теста
            Quest *MyQuest=new Quest(0, userFile);
            MyQuest->show();
            delete this;
        }
    }
}

