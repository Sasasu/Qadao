#include <QApplication>
#include <AdaoMainWindow.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AdaoMainWindow mainwindows;
    mainwindows.show();

    return a.exec();
}
