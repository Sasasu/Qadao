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
    void getForumList();
signals:
    void finished(QSharedPointer< QVector<ForumList> >);
public slots:

private:
    const QString AdaoURL = "https://h.nimingban.com";
    const QString AdaoAPIid = "adao";
};

#endif // ADAOJSON_H
