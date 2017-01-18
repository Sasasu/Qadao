#ifndef ADAODATA_H
#define ADAODATA_H
#include <QString>
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
    int replyCount;
};
QDebug operator <<(QDebug dbg, const ThreadInfo &w);
#endif // ADAODATA_H
