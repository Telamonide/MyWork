#include <QtGui>
#include "StartWindow.h"
#include "LearnWindow.h"
#include "PassWindow.h"

StartWindow::StartWindow(QWidget *parent)
    : QDialog(parent)
{
    label=new QLabel(tr("Please select programm mode"));

    EditModeButton=new QPushButton(tr("Edit mode"));

    LearnButton=new QPushButton(tr("Learning"));
    LearnButton->setDefault(true);

    TestButton=new QPushButton(tr("Test"));

    CloseButton=new QPushButton(tr("Exit"));

    connect(CloseButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(LearnButton, SIGNAL(clicked()), this, SLOT(pressLearn()));
    connect(EditModeButton, SIGNAL(clicked()), this, SLOT(pressEditMode()));

    QHBoxLayout *StartButtonLayout=new QHBoxLayout;
    StartButtonLayout->addStretch();
    StartButtonLayout->addWidget(EditModeButton);
    StartButtonLayout->addWidget(LearnButton);
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

void StartWindow::pressEditMode()
{
    this->hide();
    PassWindow *MyPass=new PassWindow(this);
    MyPass->show();
}
