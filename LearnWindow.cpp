#include "LearnWindow.h"

LearnWindow::LearnWindow(QWidget *parent, QString datafile, QString wintitle) :
    QDialog (parent)
{
    LearnTextBrows=new QTextBrowser();
    QFile LearnFile(datafile);
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
    setWindowTitle(wintitle);
    this->resize(800,600);
}

LearnWindow::~LearnWindow()
{
    delete LearnTextBrows;
    delete NextText;
    delete BackText;
    delete CloseText;
}

//Обрабатываем нажатие кнопки завершения
void LearnWindow::CloseTextPress()
{
    QWidget::parentWidget()->show();
    delete this;
}
