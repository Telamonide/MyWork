#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QtGui/QDialog>

class QPushButton;
class QLabel;

class StartWindow : public QDialog
{
    Q_OBJECT
    
public:
    StartWindow(QWidget *parent = 0);

public slots:
    void pressLearn();
    void pressEditMode();
    //void pressTest();

private:
    QLabel *label;
    QPushButton *EditModeButton;
    QPushButton *LearnButton;
    QPushButton *TestButton;
    QPushButton *CloseButton;
};

#endif // STARTWINDOW_H
