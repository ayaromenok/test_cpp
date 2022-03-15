#include "widget.h"
#include "yhexview.h"

#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YHexView *viewWidget = new YHexView();

    QMainWindow w;
    w.setCentralWidget(viewWidget);
    w.show();
    return a.exec();
}
