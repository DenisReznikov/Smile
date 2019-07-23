#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class desx : public QObject
{
  Q_OBJECT

public:
  desx();
  ~desx();

private slots:
  void test_case1();

};

desx::desx()
{

}

desx::~desx()
{

}

void desx::test_case1()
{

}

QTEST_MAIN(desx)

#include "tst_desx.moc"
