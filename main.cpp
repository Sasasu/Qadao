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
    adao.getForumList();
    QObject::connect(&adao,&AdaoJSON::finished,
                     [&](QSharedPointer< QVector<ForumList> > data){
        for(ForumList &a : *data)
            qDebug() << a;
    });
    return a.exec();
}
