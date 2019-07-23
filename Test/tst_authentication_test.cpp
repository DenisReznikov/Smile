#include <QtTest/QtTest>
#include <QtGui>
// add necessary includes here
#include <QtWidgets>
#include "Smile/UI/authentication.h"
#include "ui_authentication.h"
class authentication_test : public QObject
{
  Q_OBJECT

public:
  authentication_test();
  ~authentication_test();

private slots:
  void checkMissing_data();
  void checkMissing();
  void checkLogAndPassInBase_data();
  void checkLogAndPassInBase();
  void checkWidjet_data();
  void checkWidjetlineUserName();

};

authentication_test::authentication_test()
{
}

authentication_test::~authentication_test()
{

}
void authentication_test::checkMissing_data()
{
  QTest::addColumn<QString>("log");
  QTest::addColumn<QString>("pass");
  QTest::addColumn<bool>("result");
  QString str = "";
  QTest::newRow("all_empty") << QString(str) << QString(str) << bool(false);
  QTest::newRow("log_empty") << QString(str) << QString("d") << bool(false);
  QTest::newRow("pass_empty") << QString("2007") << QString(str) << bool(false);
  QTest::newRow("all_correct") << QString("dd") << QString("20")<< bool(true);
}

void authentication_test::checkMissing()
{
  Authentication auth;
  QFETCH(QString,log);
  QFETCH(QString,pass);
  QFETCH(bool,result);
  QCOMPARE(auth.checkMissing(log,pass),result);
}

void authentication_test::checkLogAndPassInBase_data()
{
  QTest::addColumn<QString>("login");
  QTest::addColumn<QString>("password");
  QTest::addColumn<bool>("result_DB");
  QString str = "";
  QTest::newRow("all_empty") << QString(str) << QString(str) << bool(false);
  QTest::newRow("log_empty") << QString(str) << QString("d") << bool(false);
  QTest::newRow("pass_empty") << QString("2007") << QString(str) << bool(false);
  QTest::newRow("Incorrect_all") << QString("dd") << QString("20")<< bool(false);
  QTest::newRow("Incorrect_login") << QString("ads") << QString("test")<< bool(false);
  QTest::newRow("Incorrect_password") << QString("denis") << QString("20")<< bool(false);
  QTest::newRow("AllCorrect") << QString("denis") << QString("test")<< bool(true);
}

void authentication_test::checkLogAndPassInBase()
{
  Authentication auth;
  QFETCH(QString,login);
  QFETCH(QString,password);
  QFETCH(bool,result_DB);
  QCOMPARE(auth.checkLogAndPassInBase(login,password),result_DB);
}

void authentication_test::checkWidjetlineUserName()
{
  Authentication auth;
  Ui_Authentication *txt=auth.ui;
  QTest::keyClicks(txt->lineUserName, "ABCDEFGH");
  QCOMPARE(txt->lineUserName->text(), QString("ABCDEFGH"));
  QVERIFY(txt->lineUserName->isModified());
}

QTEST_MAIN(authentication_test)

#include "tst_authentication_test.moc"
