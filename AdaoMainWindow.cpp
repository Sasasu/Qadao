#include "AdaoMainWindow.h"
#include "AdaoJSON.h"
#include "defines.h"
#include "ui_AdaoMainWindow.h"
#include <QDebug>
#include <QListWidgetItem>
AdaoMainWindow::AdaoMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::AdaoMainWindow), json(new AdaoJSON) {
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

AdaoMainWindow::~AdaoMainWindow() {
    delete ui;
    delete json;
}
void AdaoMainWindow::getFormList() {
    json->getForumList();
    connect(
                json, static_cast<void (AdaoJSON::*)(QSharedPointer<QVector<ForumList>>)>(
                    &AdaoJSON::finished),
                [&](QSharedPointer<QVector<ForumList>> forumlist) {
        this->ui->ForumList->clear();
        this->forumlist = forumlist;
        for (ForumList &forum : *forumlist) {
            QListWidgetItem *qw = new QListWidgetItem(this->ui->ForumList);
            qw->setText(forum.name);
            this->ui->ForumList->addItem(qw);
        }
        QObject::connect(this->ui->ForumList, &QListWidget::currentRowChanged,
                         [this](const int i) {
            this->ui->Threadlist->clear();
            this->ui->Threadlist->addItem(tr("加载中"));
            this->changeThredList((*(this->forumlist))[i].id);
        });
        disconnect(json);
    });
}
void AdaoMainWindow::getThreadInfo(int id, int page) {
    json->getContent(id, page);
    connect(json,
            static_cast<void (AdaoJSON::*)(QSharedPointer<QVector<ThreadInfo>>)>(
                &AdaoJSON::finished),
            [&](QSharedPointer<QVector<ThreadInfo>> thredinfo) {
        this->ui->Threadlist->clear();
        this->threadinfo = thredinfo;
        for (ThreadInfo &thread : *thredinfo) {
            QListWidgetItem *qw = new QListWidgetItem(this->ui->Threadlist);
            qw->setText(tr("ID:") + thread.userid + "\t" + thread.now + "\n" +
                        thread.content + "\n");
            this->ui->Threadlist->addItem(qw);
        }
        this->ui->Threadlist->addItem(tr("\n\t\t点击加载下一页\n"));
        QObject::connect(this->ui->Threadlist,
                         &QListWidget::currentRowChanged,
                         [this](const int) {});
        disconnect(json);
    });
}
void AdaoMainWindow::getThreaddetail(int id, int page) {
    json->getContent(id, page);
}

void AdaoMainWindow::changeThredList(int id) { this->getThreadInfo(id, 1); }
