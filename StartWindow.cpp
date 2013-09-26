#include <QtGui>
#include "StartWindow.h"
#include "LearnWindow.h"
#include "PassWindow.h"
#include "testdialog.h"
#include "quest.h"

StartWindow::StartWindow(QWidget *parent)
    : QDialog(parent)
{
    label=new QLabel(tr("Please select programm mode"));

    EditModeButton=new QPushButton(tr("Admin mode"));

    LearnButton=new QPushButton(tr("Learning"));
    LearnButton->setDefault(true);

    GetPassButton=new QPushButton(tr("Get Pass"));

    TestButton=new QPushButton(tr("Test"));

    CloseButton=new QPushButton(tr("Exit"));

    connect(CloseButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(LearnButton, SIGNAL(clicked()), this, SLOT(pressLearn()));
    connect(EditModeButton, SIGNAL(clicked()), this, SLOT(pressEditMode()));
    connect(GetPassButton, SIGNAL(clicked()), this, SLOT(pressGetPass()));
    connect(TestButton, SIGNAL(clicked()), this, SLOT(pressEditMode()));

    QHBoxLayout *StartButtonLayout=new QHBoxLayout;
    StartButtonLayout->addStretch();
    StartButtonLayout->addWidget(EditModeButton);
    StartButtonLayout->addWidget(LearnButton);
    StartButtonLayout->addWidget(GetPassButton);
    StartButtonLayout->addWidget(TestButton);
    StartButtonLayout->addWidget(CloseButton);
    StartButtonLayout->addStretch();

    QHBoxLayout *LabelLayout=new QHBoxLayout;
    LabelLayout->addStretch();
    LabelLayout->addWidget(label);
    LabelLayout->addStretch();

    QVBoxLayout *FirstWindowLayout=new QVBoxLayout;
    FirstWindowLayout->addLayout(LabelLayout);
    FirstWindowLayout->addLayout(StartButtonLayout);
    setLayout(FirstWindowLayout);
    setWindowTitle(tr("Assessment of knowledge"));
}

void StartWindow::pressLearn()
{
    this->hide();
    LearnWindow *NextWindow=new LearnWindow(this);
    NextWindow->show();
}

StartWindow::~StartWindow()
{
    delete label;
    delete EditModeButton;
    delete LearnButton;
    delete TestButton;
    delete CloseButton;
    delete GetPassButton;
}

void StartWindow::pressEditMode()
{
    this->hide();
    PassWindow *MyPass=new PassWindow(this);
    MyPass->show();
}

void StartWindow::pressGetPass()
{
    this->hide();
    TestDialog *MyTest=new TestDialog(this);
    MyTest->show();
}

void StartWindow::pressTest()
{
    this->hide();
    Quest *MyQuest=new Quest(this);
    MyQuest->show();
}
