#include "contact.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    contact w;
    w.show();
    return a.exec();
}
