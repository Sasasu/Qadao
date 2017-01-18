#ifndef ADAOJSON_H
#define ADAOJSON_H
#include <QObject>
#include <QString>
#include "AdaoData.h"
class AdaoJSON : public QObject
{
    Q_OBJECT
public:
    explicit AdaoJSON(QObject *parent = 0);
    void getForumList();    //获取板块列表
    void getContent(int id,int page);   //获取板块串
    void getThread(int id,int page);    //获取串的内容
signals:
    void finished(QSharedPointer< QVector<ForumList> >);
    void finished(QSharedPointer< QVector<ThreadInfo> >);
public slots:

private:
    const QString AdaoURL = "https://h.nimingban.com";
    const QString AdaoAPIid = "adao";
};

#endif // ADAOJSON_H
