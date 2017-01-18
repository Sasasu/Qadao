#include "AdaoJSON.h"
#include "AdaoNet.h"
#include <QVector>
#include <QSharedPointer>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
AdaoJSON::AdaoJSON(QObject *parent) : QObject(parent)
{
}
void AdaoJSON::getForumList(){
    QSharedPointer< QVector<ForumList> > vector(new QVector<ForumList>);
    QString url(AdaoURL+"/Api/getForumList?appid="+AdaoAPIid);
    qDebug() << "[INFO] getting url" << url;
    AdaoNet *net = AdaoNet::getInstance();
    net->get(url);
    connect(net,&AdaoNet::finished,
            [net,vector,this](QNetworkReply *reply){
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll(),&error);
        if(error.error != QJsonParseError::NoError){
            qDebug() << "[ERROR] json handle error";
            qDebug() << "raw json is";
            qDebug() << jsonDocument.toJson();
            qDebug() << "please connect Sasasu";
            exit(0);
        }
        QVariantMap result = jsonDocument.toVariant().toMap();

        for (const QVariant jsonlist : result["forums"].toList()) {
            ForumList list;
            QVariantMap jsonmap = jsonlist.toMap();
            list.id = jsonmap["id"].toInt();
            list.msg = jsonmap["msg"].toString();
            list.name = jsonmap["naame"].toString();
            vector->push_back(list);
        }

        emit this->finished(vector);
    });
}
