#include "widget.h"
#include "yhexview.h"

#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YHexWidget *viewWidget = new YHexWidget();

    QMainWindow w;
    w.setCentralWidget(viewWidget);
    w.show();
    return a.exec();
}
