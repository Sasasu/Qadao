#include <QApplication>
#include <QNetworkReply>
#include <QDebug>
#include <QVector>
#include "AdaoData.h"
#include "AdaoJSON.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdaoJSON adao;
    adao.getThread(11205226,1);
//    adao.getContent(5,1);
    QObject::connect(&adao,
                     static_cast<void (AdaoJSON::*)(QSharedPointer< QVector<ThreadInfo> > ) >
                     (&AdaoJSON::finished),
                     [&](QSharedPointer< QVector<ThreadInfo> > data){
        for(ThreadInfo &a : *data){
            qDebug() << a;
            for(auto &b : a.replys)
                qDebug() << b;
        }
    });
    return a.exec();
}
