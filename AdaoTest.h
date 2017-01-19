#ifndef ADAOTEST_H
#define ADAOTEST_H
#include <QObject>
class AdaoJSON;
class AdaoTest : public QObject {
    Q_OBJECT
public:
    AdaoTest();
    bool testGetForumList();
    bool testGetContent();
    bool testGetThread();
    bool test();
    AdaoJSON *json;
};

#endif // ADAOTEST_H
