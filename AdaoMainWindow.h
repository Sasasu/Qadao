#ifndef ADAOMAINWINDOW_H
#define ADAOMAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>
#include <QVector>
class AdaoJSON;
class ThreadInfo;
class ForumList;

namespace Ui {
class AdaoMainWindow;
}

class AdaoMainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit AdaoMainWindow(QWidget *parent = 0);
    ~AdaoMainWindow();

private:
    Ui::AdaoMainWindow *ui;
    void getFormList();
    void getThreadInfo(int id, int page);
    void getThreaddetail(int id, int page);
    void changeThredList(int id);
    int nowpage;
    int nowid;
    AdaoJSON *json;
    QSharedPointer<QVector<ForumList>> forumlist;
    QSharedPointer<QVector<ThreadInfo>> threadinfo;
};

#endif // ADAOMAINWINDOW_H
