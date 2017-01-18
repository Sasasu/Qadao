#include "AdaoNet.h"
#include "defines.h"
#include <QUrl>
#include <QNetworkRequest>
AdaoNet::AdaoNet(QObject *parent) : QObject(parent),
    NetManager(new QNetworkAccessManager)
{
    connect(NetManager,&QNetworkAccessManager::finished,
            this,&AdaoNet::finished);
}
AdaoNet::~AdaoNet(){
    delete NetManager;
    NetManager = nullptr;
}

AdaoNet* AdaoNet::getInstance(){
    static AdaoNet net;
    return &net;
}
void AdaoNet::get(QString url){
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setRawHeader("User-Agent", "HavfunClient-qt QAdao " VISION ARCH);
    NetManager->get(request);
}
