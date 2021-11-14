#include "pch.h"
#include <complex>
#include <vector>
#include "../ADS_Lab_2/Polyline.h"

TEST(Polyline, Vertex) {
	Polyline<IntPoint2> p_1;
	IntPoint2 p;
	p._x = 1;
	p._y = 1;
	p_1.AddToEnd(p);
	EXPECT_EQ(1, p_1.Vertex());

	Polyline<DoublePoint3> p_2;
	DoublePoint3 s;
	s._x = 1;
	s._y = 1;
	s._z = 1;
	p_2.AddToEnd(s);
	EXPECT_EQ(1, p_2.Vertex());

	Polyline<std::complex<double>> p_3;
	std::complex<double> t(1, 1);
	p_3.AddToEnd(t);
	EXPECT_EQ(1, p_3.Vertex());
}

TEST(Polyline, GetLenght) {
	Polyline<IntPoint2> p_1;
	IntPoint2 p;
	p._x = 0;
	p._y = 0;
	p_1.AddToEnd(p);
	p._x = 6;
	p._y = 8;
	p_1.AddToEnd(p);
	EXPECT_EQ(10, p_1.GetLenght());

	Polyline<DoublePoint3> p_2;
	DoublePoint3 t;
	t._x = 0;
	t._y = 0;
	t._z = 0;
	p_2.AddToEnd(t);
	t._x = 4;
	t._y = 7;
	t._z = 9;
	p_2.AddToEnd(t);
	EXPECT_EQ(sqrt(146), p_2.GetLenght());

	Polyline<std::complex<double>> p_3;
	std::complex<double> first_point(2, 3);
	std::complex<double> second_point(5, 7);
	p_3.AddToEnd(first_point);
	p_3.AddToEnd(second_point);
	EXPECT_EQ(5, p_3.GetLenght());
}

TEST(Polyline, AddToHead) {
	Polyline<IntPoint2> p_1;
	IntPoint2 p;
	p._x = 25;
	p._y = 33;
	p_1.AddToHead(p);
	p._x = 1;
	p._y = 1;
	p_1.AddToHead(p);
	EXPECT_EQ(40, p_1.GetLenght());

	Polyline<DoublePoint3> p_2;
	DoublePoint3 t;
	t._x = 4;
	t._y = 7;
	t._z = 9;
	p_2.AddToHead(t);
	t._x = 0;
	t._y = 0;
	t._z = 0;
	p_2.AddToHead(t);
	EXPECT_EQ(sqrt(146), p_2.GetLenght());

	Polyline<std::complex<double>> p_3;
	std::complex<double> first_point(5, 7);
	p_3.AddToHead(first_point);
	std::complex<double> second_point(2, 3);
	p_3.AddToHead(second_point);
	EXPECT_EQ(5, p_3.GetLenght());
}

TEST(Polyline, AddToEnd) {
	Polyline<IntPoint2> p_1;
	IntPoint2 p;
	p._x = 1;
	p._y = 1;
	p_1.AddToEnd(p);
	p._x = 25;
	p._y = 33;
	p_1.AddToEnd(p);
	EXPECT_EQ(40, p_1.GetLenght());

	Polyline<DoublePoint3> p_2;
	DoublePoint3 t;
	t._x = 0;
	t._y = 0;
	t._z = 0;
	p_2.AddToEnd(t);
	t._x = 4;
	t._y = 7;
	t._z = 9;
	p_2.AddToEnd(t);
	EXPECT_EQ(sqrt(146), p_2.GetLenght());

	Polyline<std::complex<double>> p_3;
	std::complex<double> first_point(2, 3);
	p_3.AddToEnd(first_point);
	std::complex<double> second_point(5, 7);
	p_3.AddToEnd(second_point);
	EXPECT_EQ(5, p_3.GetLenght());
}

TEST(Polyline, Operator_Square_Brackets) {
	Polyline<IntPoint2> p_1;
	IntPoint2 p;
	p._x = 0;
	p._y = 1;
	p_1.AddToEnd(p);
	EXPECT_EQ(0, p_1[0]._x);
	EXPECT_EQ(1, p_1[0]._y);

	Polyline<DoublePoint3> p_2;
	DoublePoint3 t;
	t._x = 4;
	t._y = 7;
	t._z = 9;
	p_2.AddToEnd(t);
	EXPECT_EQ(4, p_2[0]._x);
	EXPECT_EQ(7, p_2[0]._y);
	EXPECT_EQ(9, p_2[0]._z);

	Polyline<std::complex<double>> p_3;
	std::complex<double> first_point(2, 3);
	p_3.AddToEnd(first_point);
	EXPECT_EQ(2, p_3[0].real());
	EXPECT_EQ(3, p_3[0].imag());
}

TEST(Polyline, Operator_Square_Brackets_const) {
	Polyline<IntPoint2> p_1;
	Polyline<DoublePoint3> p_2;
	Polyline<std::complex<double>> p_3;
	EXPECT_THROW(p_1[5]._x, const char*);
	EXPECT_THROW(p_1[5]._y, const char*);
	EXPECT_THROW(p_2[6]._x, const char*);
	EXPECT_THROW(p_2[6]._y, const char*);
	EXPECT_THROW(p_2[6]._z, const char*);
	EXPECT_THROW(p_3[3].real(), const char*);
	EXPECT_THROW(p_3[3].imag(), const char*);
}

TEST(Polyline, Operator_Plus) {
	Polyline<IntPoint2> p_1;
	IntPoint2 p;
	p._x = 0;
	p._y = 0;
	p_1.AddToEnd(p);
	Polyline<IntPoint2> p_2;
	p._x = 6;
	p._y = 8;
	p_2.AddToEnd(p);
	p_1 = p_1 + p_2;
	EXPECT_EQ(10, p_1.GetLenght());

	Polyline<DoublePoint3> p_3;
	DoublePoint3 t;
	t._x = 0;
	t._y = 0;
	t._z = 0;
	p_3.AddToEnd(t);
	Polyline<DoublePoint3> p_4;
	t._x = 4;
	t._y = 7;
	t._z = 9;
	p_4.AddToEnd(t);
	p_3 = p_3 + p_4;
	EXPECT_EQ(sqrt(146), p_3.GetLenght());

	Polyline<std::complex<double>> p_5;
	std::complex<double> first_point(2, 3);
	p_5.AddToEnd(first_point);
	Polyline<std::complex<double>> p_6;
	std::complex<double> second_point(5, 7);
	p_6.AddToEnd(second_point);
	p_5 = p_5 + p_6;
	EXPECT_EQ(5, p_5.GetLenght());
}

TEST(Polyline, Operator_Equal) {
	Polyline<IntPoint2> p_1;
	Polyline<IntPoint2> p_2;
	EXPECT_EQ(1, p_1 == p_2);

	Polyline<DoublePoint3> p_3;
	DoublePoint3 t;
	t._x = 0;
	t._y = 0;
	t._z = 0;
	p_3.AddToEnd(t);
	Polyline<DoublePoint3> p_4;
	t._x = 0;
	t._y = 0;
	t._z = 0;
	p_4.AddToEnd(t);
	t._x = 4;
	t._y = 7;
	t._z = 9;
	p_4.AddToEnd(t);
	EXPECT_EQ(0, p_3 == p_4);

	Polyline<std::complex<double>> p_5;
	std::complex<double> first(2, 3);
	p_5.AddToEnd(first);
	Polyline<std::complex<double>> p_6;
	std::complex<double> second(5, 7);
	p_6.AddToEnd(second);
	EXPECT_EQ(0, first == second);
}

TEST(Polyline, Operator_Inequality) {
	Polyline<IntPoint2> p_1;
	Polyline<IntPoint2> p_2;
	EXPECT_EQ(0, p_1 != p_2);

	Polyline<DoublePoint3> p_3;
	DoublePoint3 t;
	t._x = 0;
	t._y = 0;
	t._z = 0;
	p_3.AddToEnd(t);
	Polyline<DoublePoint3> p_4;
	EXPECT_EQ(1, p_3 != p_4);

	Polyline<std::complex<double>> p_5;
	std::complex<double> first(2, 3);
	p_5.AddToEnd(first);
	Polyline<std::complex<double>> p_6;
	std::complex<double> second(5, 7);
	p_6.AddToEnd(second);
	EXPECT_EQ(1, first != second);
}