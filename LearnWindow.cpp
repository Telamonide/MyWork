#include <QtGui>
#include "LearnWindow.h"

LearnWindow::LearnWindow(QWidget *parent) :
    QDialog (parent)
{
    LearnTextBrows=new QTextBrowser();
    QFile LearnFile("C:\\Users\\Aleksandr\\Desktop\\Work\\Work\\DataFile.txt");
    LearnFile.open(QFile::ReadOnly);
    QByteArray data=LearnFile.readAll();
    QString str=QString::fromUtf8(data);
    LearnTextBrows->setPlainText(str);
    LearnFile.close();

    NextText=new QPushButton(tr("Next"));
    NextText->setDefault(true);

    BackText=new QPushButton(tr("Back"));
    BackText->setEnabled(false);

    CloseText=new QPushButton(tr("Close"));

    connect(CloseText, SIGNAL(clicked()),this, SLOT(CloseTextPress()));

    QHBoxLayout *ButtonLayout=new QHBoxLayout;
    ButtonLayout->addStretch();
    ButtonLayout->addWidget(CloseText);

    QVBoxLayout *LearnLayout=new QVBoxLayout;
    LearnLayout->addWidget(LearnTextBrows);
    LearnLayout->addLayout(ButtonLayout);

    setLayout(LearnLayout);
    setWindowTitle(tr("Text for learning"));
    this->resize(800,600);

}

void LearnWindow::CloseTextPress()
{
    QWidget::parentWidget()->show();
    delete this;
}
