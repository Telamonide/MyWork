#ifndef LEARNWINDOW_H
#define LEARNWINDOW_H

#include <QtGui/QDialog>
#include <QTextBrowser>
#include <QFile>

class LearnWindow : public QDialog
{
    Q_OBJECT
public:
    LearnWindow(QWidget *parent =0);
    
signals:

    
public slots:
    void CloseTextPress();

private:
    QTextBrowser *LearnTextBrows;
    QPushButton *NextText;
    QPushButton *BackText;
    QPushButton *CloseText;
    
};

#endif // LEARNWINDOW_H
