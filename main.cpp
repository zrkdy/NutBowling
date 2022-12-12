#include "mainscene.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainScene w;
    w.setWindowTitle("坚果保龄球");
    w.show();

    return a.exec();
}
