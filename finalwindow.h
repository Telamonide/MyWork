#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QDialog>
#include <QFile>
#include <QStringList>
#include <QTextStream>

namespace Ui {
class FinalWindow;
}

class FinalWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit FinalWindow(QString studentRating, QString studentName, QWidget *parent = 0);
    ~FinalWindow();
    
private:
    Ui::FinalWindow *ui;
    QString resultString;
//    QString resultDataFile;
    QStringList studName;
};

#endif // FINALWINDOW_H
