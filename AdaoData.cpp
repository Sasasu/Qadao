#include "AdaoData.h"
#include <QDebug>
QDebug operator <<(QDebug dbg, const ForumList &w)
{
    dbg.nospace() << "{ "
                  << "id: " << w.id << "; "
                  << "name: " << w.name << "; "
                  << "msg: " << w.msg << "; "
                  << "}";
    return dbg.space();
}
QDebug operator <<(QDebug dbg, const ThreadInfo &w){
    dbg.nospace() << "{"
                  << "id: " << w.id << "; "
                  << "img: " << w.img << "; "
                  << "ext: " << w.ext << "; "
                  << "now: " << w.now << "; "
                  << "userid: " << w.userid << "; "
                  << "name: " << w.name << "; "
                  << "title: " << w.title << "; "
                  << "content: " << w.content << "; "
                  << "}";
    return dbg.space();
}
