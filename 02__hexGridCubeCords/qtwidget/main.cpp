#include "yhexwidget.h"

#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YHexWidget *viewWidget = new YHexWidget();

    QMainWindow w;
    w.setWindowTitle("YHexTest");
    w.setCentralWidget(viewWidget);
    w.show();
    return a.exec();
}
