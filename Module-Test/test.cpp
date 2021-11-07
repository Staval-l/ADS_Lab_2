#include "pch.h"
#include <complex>
#include "../ADS_Lab_2/Polyline.h"

TEST(Polyline, Constructor) {
	Polyline<IntPoint2> p_1;
	Polyline<DoublePoint3> p_2;
	Polyline<std::complex<double>> p_3;
	EXPECT_EQ(0, p_1.Vertex());
	EXPECT_EQ(0, p_2.Vertex());
	EXPECT_EQ(0, p_3.Vertex());
}

TEST(Polyline, Constructor_Param) {
	Polyline<IntPoint2> p_1(5);
	Polyline<DoublePoint3> p_2(3);
	EXPECT_EQ(5, p_1.Vertex());
	EXPECT_EQ(3, p_2.Vertex());
	EXPECT_THROW(Polyline<std::complex<double>> p_3(-1), const char*);
}

TEST(Polyline, Condtructor_Copy) {
	Polyline<IntPoint2> p_1(5);
	Polyline<DoublePoint3> p_2(3);
	Polyline<std::complex<double>> p_3(1);
	Polyline<IntPoint2> copy_1(p_1);
	Polyline<DoublePoint3> copy_2(p_2);
	Polyline<std::complex<double>> copy_3(p_3);
	EXPECT_EQ(5, copy_1.Vertex());
	EXPECT_EQ(3, copy_2.Vertex());
	EXPECT_EQ(1, copy_3.Vertex());
}

TEST(Polyline, Vertex) {
	Polyline<IntPoint2> p_1(1);
	Polyline<DoublePoint3> p_2(3);
	Polyline<std::complex<double>> p_3(5);
	EXPECT_EQ(1, p_1.Vertex());
	EXPECT_EQ(3, p_2.Vertex());
	EXPECT_EQ(5, p_3.Vertex());
}

TEST(Polyline, GetLenght) {
	Polyline<IntPoint2> p_1(2);
	Polyline<DoublePoint3> p_2(2);
	Polyline<std::complex<double>> p_3(2);
	p_1[0]._x = 0;
	p_1[0]._y = 0;
	p_1[1]._x = 6;
	p_1[1]._y = 8;
	p_2[0]._x = 0;
	p_2[0]._y = 0;
	p_2[0]._z = 0;
	p_2[1]._x = 4;
	p_2[1]._y = 7;
	p_2[1]._z = 9;
	std::complex<double> first_point(2, 3);
	std::complex<double> second_point(5, 7);
	p_3[0] = first_point;
	p_3[1] = second_point;
	EXPECT_EQ(10, p_1.GetLenght());
	EXPECT_EQ(sqrt(146), p_2.GetLenght());
	EXPECT_EQ(5, p_3.GetLenght());
}

TEST(Polyline, AddToHead) {
	Polyline<IntPoint2> p_1(1);
	p_1[0]._x = 25;
	p_1[0]._y = 33;
	IntPoint2 p;
	p._x = 1;
	p._y = 1;
	p_1.AddToHead(p);
	EXPECT_EQ(40, p_1.GetLenght());

	Polyline<DoublePoint3> p_2(1);
	p_2[0]._x = 4;
	p_2[0]._y = 7;
	p_2[0]._z = 9;
	DoublePoint3 a;
	a._x = 0;
	a._y = 0;
	a._z = 0;
	p_2.AddToHead(a);
	EXPECT_EQ(sqrt(146), p_2.GetLenght());

	Polyline<std::complex<double>> p_3(1);
	std::complex<double> first_point(5, 7);
	p_3[0] = first_point;
	std::complex<double> second_point(2, 3);
	p_3.AddToHead(second_point);
	EXPECT_EQ(5, p_3.GetLenght());
}

TEST(Polyline, AddToEnd) {
	Polyline<IntPoint2> p_1(1);
	p_1[0]._x = 1;
	p_1[0]._y = 1;
	IntPoint2 p;
	p._x = 25;
	p._y = 33;
	p_1.AddToEnd(p);
	EXPECT_EQ(40, p_1.GetLenght());

	Polyline<DoublePoint3> p_2(1);
	p_2[0]._x = 0;
	p_2[0]._y = 0;
	p_2[0]._z = 0;
	DoublePoint3 a;
	a._x = 4;
	a._y = 7;
	a._z = 9;
	p_2.AddToEnd(a);
	EXPECT_EQ(sqrt(146), p_2.GetLenght());

	Polyline<std::complex<double>> p_3(1);
	std::complex<double> first_point(2, 3);
	p_3[0] = first_point;
	std::complex<double> second_point(5, 7);
	p_3.AddToEnd(second_point);
	EXPECT_EQ(5, p_3.GetLenght());
}

TEST(Polyline, Operator_Square_Brackets) {
	Polyline<IntPoint2> p_1(1);
	p_1[0]._x = 0;
	p_1[0]._y = 1;
	EXPECT_EQ(0, p_1[0]._x);
	EXPECT_EQ(1, p_1[0]._y);

	Polyline<DoublePoint3> p_2(1);
	p_2[0]._x = 4;
	p_2[0]._y = 7;
	p_2[0]._z = 9;
	EXPECT_EQ(4, p_2[0]._x);
	EXPECT_EQ(7, p_2[0]._y);
	EXPECT_EQ(9, p_2[0]._z);

	Polyline<std::complex<double>> p_3(1);
	std::complex<double> first_point(2, 3);
	p_3[0] = first_point;
	EXPECT_EQ(2, p_3[0].real());
	EXPECT_EQ(3, p_3[0].imag());
}

TEST(Polyline, Operator_Square_Brackets_const) {
	Polyline<IntPoint2> p_1(1);
	Polyline<DoublePoint3> p_2(1);
	Polyline<std::complex<double>> p_3(1);
	EXPECT_THROW(p_1[5]._x, const char*);
	EXPECT_THROW(p_1[5]._y, const char*);
	EXPECT_THROW(p_2[6]._x, const char*);
	EXPECT_THROW(p_2[6]._y, const char*);
	EXPECT_THROW(p_2[6]._z, const char*);
	EXPECT_THROW(p_3[3].real(), const char*);
	EXPECT_THROW(p_3[3].imag(), const char*);
}

TEST(Polyline, Operator_Plus) {
	Polyline<IntPoint2> p_1(1);
	p_1[0]._x = 1;
	p_1[0]._y = 1;
	Polyline<IntPoint2> p(1);
	p[0]._x = 25;
	p[0]._y = 33;
	p_1 = p_1 + p;
	EXPECT_EQ(40, p_1.GetLenght());

	Polyline<DoublePoint3> p_2(1);
	p_2[0]._x = 0;
	p_2[0]._y = 0;
	p_2[0]._z = 0;
	Polyline<DoublePoint3> a(1);
	a[0]._x = 4;
	a[0]._y = 7;
	a[0]._z = 9;
	p_2 = p_2 + a;
	EXPECT_EQ(sqrt(146), p_2.GetLenght());

	Polyline<std::complex<double>> first(1);
	Polyline<std::complex<double>> second(1);
	std::complex<double> a_1(2, 3);
	std::complex<double> b_1(5, 7);
	first[0] = a_1;
	second[0] = b_1;
	first = first + second;
	EXPECT_EQ(5, first.GetLenght());
}

TEST(Polyline, Operator_Equal) {
	Polyline<IntPoint2> p_1(1);
	Polyline<IntPoint2> p_2(1);
	EXPECT_EQ(1, p_1 == p_2);

	Polyline<DoublePoint3> p_3(1);
	Polyline<DoublePoint3> p_4(2);
	EXPECT_EQ(0, p_3 == p_4);

	Polyline<std::complex<double>> first(5);
	Polyline<std::complex<double>> second(5);
	EXPECT_EQ(1, first == second);
}

TEST(Polyline, Operator_Inequality) {
	Polyline<IntPoint2> p_1(1);
	Polyline<IntPoint2> p_2(1);
	EXPECT_EQ(0, p_1 != p_2);

	Polyline<DoublePoint3> p_3(1);
	Polyline<DoublePoint3> p_4(2);
	EXPECT_EQ(1, p_3 != p_4);

	Polyline<std::complex<double>> first(5);
	Polyline<std::complex<double>> second(5);
	EXPECT_EQ(0, first != second);
}

TEST(Polyline, Operator_Assignment) {
	Polyline<IntPoint2> p_1(2);
	p_1[0]._x = 0;
	p_1[0]._y = 0;
	p_1[1]._x = 25;
	p_1[1]._y = 33;
	Polyline<IntPoint2> p(1);
	p[0]._x = 1;
	p[0]._y = 1;
	p_1[0] = p[0];
	EXPECT_EQ(40, p_1.GetLenght());

	Polyline<DoublePoint3> p_2(2);
	p_2[0]._x = 1;
	p_2[0]._y = 1;
	p_2[0]._z = 1;
	p_2[1]._x = 4;
	p_2[1]._y = 7;
	p_2[1]._z = 9;
	Polyline<DoublePoint3> a(1);
	a[0]._x = 0;
	a[0]._y = 0;
	a[0]._z = 0;
	p_2[0] = a[0];
	EXPECT_EQ(sqrt(146), p_2.GetLenght());

	Polyline<std::complex<double>> first(2);
	Polyline<std::complex<double>> second(1);
	std::complex<double> a_1(2, 3);
	std::complex<double> b_1(5, 7);
	first[0] = a_1;
	second[0] = b_1;
	first[1] = second[0];
	EXPECT_EQ(5, first.GetLenght());
}