#include "AdaoTest.h"
#include "AdaoData.h"
#include "AdaoJSON.h"
#include <QDebug>
#include <QObject>
#include <QSharedPointer>
#include <QVector>
AdaoTest::AdaoTest() : json(new AdaoJSON()) {}
bool AdaoTest::test() {
  this->testGetContent();
//  this->testGetForumList();
//  this->testGetThread();
  return true;
}
bool AdaoTest::testGetContent() {
  json->getContent(5, 1);
  QObject::connect(
      json,
      static_cast<void (AdaoJSON::*)(QSharedPointer<QVector<ThreadInfo>>)>(
          &AdaoJSON::finished),
      [&](QSharedPointer<QVector<ThreadInfo>> data) {
        for (ThreadInfo &a : *data) {
          qDebug() << a;
          for (auto &b : a.replys)
            qDebug() << b;
        }
      });
  return true;
}
bool AdaoTest::testGetForumList() {
  json->getForumList();
  QObject::connect(
      json, static_cast<void (AdaoJSON::*)(QSharedPointer<QVector<ForumList>>)>(
                &AdaoJSON::finished),
      [&](QSharedPointer<QVector<ForumList>> data) {
        for (ForumList &a : *data)
          qDebug() << a;
      });
  return true;
}
bool AdaoTest::testGetThread() {
  json->getThread(11205226, 1);
  QObject::connect(
      json,
      static_cast<void (AdaoJSON::*)(QSharedPointer<QVector<ThreadInfo>>)>(
          &AdaoJSON::finished),
      [&](QSharedPointer<QVector<ThreadInfo>> data) {
        for (ThreadInfo &a : *data) {
          qDebug() << a;
          for (auto &b : a.replys)
            qDebug() << b;
        }
      });
  return true;
}
