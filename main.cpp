#include <QApplication>
#include "AdaoTest.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdaoTest().test();
    return a.exec();
}
