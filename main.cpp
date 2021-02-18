#include "mybutton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mybutton w;
    w.show();
    return a.exec();
}
