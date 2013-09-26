#include <QtWidgets/QApplication>
#include <QtGui>
#include "StartWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//Подключение файлов интернационализации
    QTranslator translator;
    translator.load("Work_ru.qm");
    app.installTranslator(&translator);

    StartWindow *dialog=new StartWindow;
    dialog->show();

    return app.exec();
}
