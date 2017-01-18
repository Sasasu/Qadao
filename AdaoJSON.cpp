#include "AdaoJSON.h"
#include "AdaoNet.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QSharedPointer>
#include <QJsonObject>
#include <QVector>
AdaoJSON::AdaoJSON(QObject *parent) : QObject(parent) {}
void AdaoJSON::getForumList() {
    QSharedPointer<QVector<ForumList>> vector(new QVector<ForumList>);
    QString url(AdaoURL + "/Api/getForumList?appid=" + AdaoAPIid);
    AdaoNet *net = AdaoNet::getInstance();
    net->get(url);
    connect(net, &AdaoNet::finished, [vector, this](QNetworkReply *reply) {
        QJsonParseError error;
        QByteArray json = reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(json, &error);

        if (error.error != QJsonParseError::NoError) {
            qDebug() << "[ERROR] json handle error";
            qDebug() << error.errorString();
            qDebug() << QString(json).toUtf8();
            emit this->finished(vector);
            return;
        }

        for (const QJsonValueRef jsonarray : jsonDocument.array()) {
            QVariantMap result = jsonarray.toVariant().toMap();

            for (const QVariant jsonlist : result["forums"].toList()) {
                ForumList list;
                QVariantMap jsonmap = jsonlist.toMap();
                list.id = jsonmap["id"].toInt();
                list.msg = jsonmap["msg"].toString();
                list.name = jsonmap["name"].toString();
                vector->push_back(list);
            }
        }
        emit this->finished(vector);
    });
}

void AdaoJSON::getContent(int id, int page) {
    QSharedPointer<QVector<ThreadInfo> > vector(new QVector<ThreadInfo>);
    QString url(AdaoURL + "/Api/showf?id=" + QString::number(id) + "&page=" +
                QString::number(page) + "&appid=" + AdaoAPIid);
    AdaoNet *net = AdaoNet::getInstance();
    net->get(url);
    connect(net, &AdaoNet::finished, [vector, this](QNetworkReply *reply) {
        QJsonParseError error;
        QByteArray json = reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(json, &error);

        if (error.error != QJsonParseError::NoError) {
            qDebug() << "[ERROR] json hadle error";
            qDebug() << error.errorString();
            qDebug() << QString(json).toUtf8();
            emit this->finished(vector);
            return;
        }
        for(const QJsonValueRef jsonarry : jsonDocument.array()){
            ThreadInfo info;
            QVariantMap result = jsonarry.toVariant().toMap();
            info.id = result["id"].toInt();
            info.img = result["img"].toString();
            info.ext = result["ext"].toString();
            info.now = result["now"].toString();
            info.userid = result["userid"].toString();
            info.name = result["name"].toString();
            info.title = result["title"].toString();
            info.content = result["content"].toString();
            info.admin = result["admin"].toBool();
            for(const QVariant subarry:result["replys"].toList()){
                QVariantMap subresult = subarry.toMap();
                ThreadInfo subinfo;
                subinfo.id = subresult["id"].toInt();
                subinfo.img = subresult["img"].toString();
                subinfo.ext = subresult["ext"].toString();
                subinfo.now = subresult["now"].toString();
                subinfo.userid = subresult["userid"].toString();
                subinfo.name = subresult["name"].toString();
                subinfo.title = subresult["title"].toString();
                subinfo.content = subresult["content"].toString();
                subinfo.admin = subresult["admin"].toBool();
                subinfo.replys.push_back(subinfo);
            }
            vector->push_back(info);
        }
        emit this->finished(vector);
    });
}

void AdaoJSON::getThread(int id, int page){
    QSharedPointer<QVector<ThreadInfo> > vector(new QVector<ThreadInfo>);
    QString url(AdaoURL + "/Api/thread?id=" + QString::number(id) + "&page=" +
                QString::number(page) + "&appid=" + AdaoAPIid);
    AdaoNet *net = AdaoNet::getInstance();
    net->get(url);
    connect(net, &AdaoNet::finished, [vector, this](QNetworkReply *reply) {
        QJsonParseError error;
        QByteArray json = reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(json, &error);

        if (error.error != QJsonParseError::NoError) {
            qDebug() << "[ERROR] json hadle error";
            qDebug() << error.errorString();
            qDebug() << QString(json).toUtf8();
            emit this->finished(vector);
            return;
        }
        ThreadInfo info;
        QVariantMap result = jsonDocument.toVariant().toMap();
        info.id = result["id"].toInt();
        info.img = result["img"].toString();
        info.ext = result["ext"].toString();
        info.now = result["now"].toString();
        info.userid = result["userid"].toString();
        info.name = result["name"].toString();
        info.title = result["title"].toString();
        info.content = result["content"].toString();
        info.admin = result["admin"].toBool();
        for(const QVariant subarry : result["replys"].toList()){
            QVariantMap subresult = subarry.toMap();
            ThreadInfo subinfo;
            subinfo.id = subresult["id"].toInt();
            subinfo.img = subresult["img"].toString();
            subinfo.ext = subresult["ext"].toString();
            subinfo.now = subresult["now"].toString();
            subinfo.userid = subresult["userid"].toString();
            subinfo.name = subresult["name"].toString();
            subinfo.title = subresult["title"].toString();
            subinfo.content = subresult["content"].toString();
            subinfo.admin = subresult["admin"].toBool();
            subinfo.replys.push_back(subinfo);
            qDebug() << subinfo;
        }
        vector->push_back(info);

        emit this->finished(vector);
    });
}
