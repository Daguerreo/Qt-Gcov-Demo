#include <QtTest>
#include "angle.h"

class Test : public QObject
{
   Q_OBJECT

private slots:
   void initTestCase_data();

   void test_type();

};

void Test::initTestCase_data()
{
   QTest::addColumn<double>("degrees");
   QTest::addColumn<double>("radians");

   QTest::newRow("1") <<  0.0   <<  0.0;
   QTest::newRow("2") <<  180.0 <<  M_PI;
   QTest::newRow("3") <<  -90.0 <<  -M_PI_2;
   QTest::newRow("4") <<  365.0 <<  6.37045;
   QTest::newRow("4") <<  -400.0 <<  -6.98132;

}

void Test::test_type()
{
   QFETCH_GLOBAL(double, degrees);
   QFETCH_GLOBAL(double, radians);

   Angle deg = Angle::Degree(degrees);
   Angle rad = Angle::Radians(radians);

   QCOMPARE(deg.isDeg(), true);
   QCOMPARE(deg.isRad(), false);
   QCOMPARE(rad.isDeg(), false);
   QCOMPARE(rad.isRad(), true);
}

QTEST_APPLESS_MAIN(Test)

#include "tst_test.moc"
