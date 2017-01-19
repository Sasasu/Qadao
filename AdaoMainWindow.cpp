#include "AdaoMainWindow.h"
#include "ui_AdaoMainWindow.h"
#include "AdaoJSON.h"
#include "defines.h"
#include <QListWidgetItem>
AdaoMainWindow::AdaoMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdaoMainWindow),
    json(new AdaoJSON)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("QAdao") + " " VISION ARCH);
    this->getFormList();
    auto tmp = new QListWidgetItem(this->ui->ForumList);
    tmp->setText(tr("加载中"));
    this->ui->ForumList->addItem(tmp);
    tmp = new QListWidgetItem(this->ui->Threadlist);
    tmp->setText(tr("你要先点左边这里才会有东西"));
    this->ui->Threadlist->addItem(tmp);
}

AdaoMainWindow::~AdaoMainWindow(){
    delete ui;
    delete json;
}
void AdaoMainWindow::getFormList(){
    json->getForumList();
    connect(json,static_cast<void (AdaoJSON::*)(QSharedPointer<QVector<ForumList>>)>
            (&AdaoJSON::finished),[&](QSharedPointer< QVector<ForumList> > forumlist){
        this->ui->ForumList->clear();
        this->forumlist = forumlist;
        for(ForumList &forum : *forumlist){
            QListWidgetItem *qw = new QListWidgetItem(this->ui->ForumList);
            qw->setText(forum.name);
            this->ui->ForumList->addItem(qw);
        }
        QObject::connect(this->ui->ForumList,&QListWidget::currentTextChanged,
                         [&](const QString &str){
            int id = getForumIdByString(str);
            this->ui->Threadlist->clear();
            this->ui->Threadlist->addItem(tr("加载中"));
            this->changeThredList(id);
        });
    });
}
void AdaoMainWindow::getThreadInfo(int id,int page){
    json->getContent(id,page);
    connect(json,static_cast<void (AdaoJSON::*)(QSharedPointer<QVector<ThreadInfo>>)>
            (&AdaoJSON::finished),[&](QSharedPointer< QVector<ThreadInfo> > thredinfo){
        this->ui->Threadlist->clear();
        this->threadinfo = thredinfo;
        for(ThreadInfo &thread : *thredinfo){
            QListWidgetItem *qw = new QListWidgetItem(this->ui->Threadlist);
            qw->setText(tr("ID:") + thread.userid + "\n" + thread.content);
            this->ui->Threadlist->addItem(qw);
        }
    });
}
int AdaoMainWindow::getForumIdByString(QString name){
    for(ForumList &forum : *forumlist){ // 遍历不二分
        if(forum.name == name)
            return forum.id;
    }
    return 0;
}
void AdaoMainWindow::changeThredList(int id){
    this->getThreadInfo(id,1);
}
