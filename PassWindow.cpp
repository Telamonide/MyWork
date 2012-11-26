#include <QtGui>
#include "PassWindow.h"

#define MyRootPass 12345678

PassWindow::PassWindow(QWidget *parent) :
    QDialog(parent)
{
    PassLabel=new QLabel(tr("Enter Password:"));
    OkButton=new QPushButton(tr("Ok"));
    MyButton=new QPushButton(tr("Cancel"));
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
    topLayout->addWidget(PassLabel);
    topLayout->addWidget(MyPassEdit);

    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(HorLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("Password"));
}

void PassWindow::MyButtonPress()
{
    parentWidget()->show();
    delete this;
}

void PassWindow::OkButtonPress()
{
    if(MyPassEdit->text()==QString::number(MyRootPass))
    {
        this->hide();
        QApplication::aboutQt();
        parentWidget()->show();
        delete this;
    }
}
