#ifndef ADAONET_H
#define ADAONET_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
class QByteArray;
class QString;

class AdaoNet : public QObject
{
    Q_OBJECT
public:
    static AdaoNet *getInstance();
    virtual ~AdaoNet();
    void get(QString url);

private:
    explicit AdaoNet(QObject *parent = 0);
    AdaoNet & operator =(AdaoNet) = delete;
    AdaoNet(const AdaoNet &) = delete;

    QNetworkAccessManager *NetManager;
signals:
    void finished(QNetworkReply *reply);
public slots:
};

#endif // ADAONET_H
