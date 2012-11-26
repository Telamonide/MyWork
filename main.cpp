#include <QtGui/QApplication>
#include <QtGui>
#include "StartWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    translator.load("Work_ru.qm");
    app.installTranslator(&translator);

    /*QTextCodec *codec = QTextCodec::codecForName("CP1251");
    QTextCodec::setCodecForTr(codec);*/

    StartWindow *dialog=new StartWindow;
    dialog->show();
    
    return app.exec();
}
