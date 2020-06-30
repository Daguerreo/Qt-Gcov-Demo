#include <QtTest>
#include "angle.h"

class Test : public QObject
{
   Q_OBJECT

private slots:
   void initTestCase_data();

   void test_constructor();
   void test_type();
   void test_value();

private:
   float pi = M_PI;
   float p2 = M_PI_2;
};

void Test::initTestCase_data()
{
   QTest::addColumn<float>("degrees");
   QTest::addColumn<float>("radians");

   QTest::newRow("1") <<  0.0f   <<  0.0f;
   QTest::newRow("2") <<  180.0f <<  pi;
   QTest::newRow("3") <<  -90.0f <<  -p2;
   QTest::newRow("4") <<  360.0f << 2.0f*pi;
   QTest::newRow("5") <<  365.0f <<  6.370451f;
   QTest::newRow("6") <<  -400.0f <<  -6.98131f;
}

void Test::test_constructor()
{
   Angle a;
   qDebug() << a;

   QCOMPARE(a.isDeg(), true);
   QCOMPARE(a.deg(), 0.0f);
}

void Test::test_type()
{
   QFETCH_GLOBAL(float, degrees);
   QFETCH_GLOBAL(float, radians);

   Angle deg(degrees, Angle::Deg);
   Angle rad(radians, Angle::Rad);

   QCOMPARE(deg.isDeg(), true);
   QCOMPARE(deg.isRad(), false);
   QCOMPARE(rad.isDeg(), false);
   QCOMPARE(rad.isRad(), true);
}

void Test::test_value()
{
   QFETCH_GLOBAL(float, degrees);
   QFETCH_GLOBAL(float, radians);

   Angle deg(degrees, Angle::Deg);
   Angle rad(radians, Angle::Rad);

   QCOMPARE(deg.deg(), degrees);
   QCOMPARE(deg.rad(), radians);
   QCOMPARE(rad.deg(), degrees);
   QCOMPARE(rad.rad(), radians);
}

QTEST_APPLESS_MAIN(Test)

#include "tst_test.moc"
