#ifndef ADAODATA_H
#define ADAODATA_H
#include <QString>
#include <QVector>
class QDebug;
class ForumList
{
public:
    ForumList() {}
    int id;
    QString name;
    QString msg;
};
QDebug operator <<(QDebug dbg, const ForumList &w);

class ThreadInfo
{
public:
    ThreadInfo() {}
    int id;
    QString img;
    QString ext;
    QString now;
    QString userid;
    QString name;
    QString title;
    QString content;
    bool admin;
    QVector<ThreadInfo> replys;
};
QDebug operator <<(QDebug dbg, const ThreadInfo &w);
#endif // ADAODATA_H
