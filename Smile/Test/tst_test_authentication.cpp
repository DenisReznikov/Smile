#include <QtTest>
#include "C/Users"
// add necessary includes here

class Test_Authentication : public QObject
{
  Q_OBJECT

public:
  Test_Authentication();
  ~Test_Authentication();

private slots:
  void test_case1();

};

Test_Authentication::Test_Authentication()
{

}

Test_Authentication::~Test_Authentication()
{

}

void Test_Authentication::test_case1()
{

}

QTEST_APPLESS_MAIN(Test_Authentication)

#include "tst_test_authentication.moc"
