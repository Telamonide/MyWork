#ifndef LEARNWINDOW_H
#define LEARNWINDOW_H

#include <QtWidgets/QDialog>
#include <QtWidgets>
#include <QTextBrowser>
#include <QFile>
#include <QtGui>

class LearnWindow : public QDialog
{
    Q_OBJECT
public:
    LearnWindow(QWidget *parent =0, QString datafiile="DataFile.txt", QString wintitle=tr("Text for learning"));
    ~LearnWindow();
signals:


public slots:
    void CloseTextPress();

private:
    QTextBrowser *LearnTextBrows;
    QPushButton *NextText;
    QPushButton *BackText;
    QPushButton *CloseText;
    QString datafile; //Файл с данными
    QString wintitle; //Заголовок окна

};

#endif // LEARNWINDOW_H
