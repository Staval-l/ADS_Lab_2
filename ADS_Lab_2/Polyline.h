#pragma once
#include <complex>
#include <iostream>
#include <vector>

struct IntPoint2 {
	int _x;
	int _y;

	bool operator==(const IntPoint2& p) const
	{
		if ((_x == p._x) && (_y == p._y)) return true;
		else return false;
	}

	float Distance(const IntPoint2& p) const
	{
		return static_cast<float>(sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2)));
	}
};

std::ostream& operator<< (std::ostream& out, const IntPoint2& point)
{
	out << "[" << point._x << ";" << point._y << "]";
	return out;
}

struct DoublePoint3 {
	double _x;
	double _y;
	double _z;

	bool operator==(const DoublePoint3& p) const
	{
		if ((_x == p._x) && (_y == p._y) && (_z == p._z)) return true;
		else return false;
	}

	double Distance(const DoublePoint3& p) const
	{
		return sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2) + pow(_z - p._z, 2));
	}
};

std::ostream& operator<< (std::ostream& out, const DoublePoint3& point)
{
	out << "[" << point._x << ";" << point._y << ";" << point._z << "]";
	return out;
}

std::ostream& operator<< (std::ostream& out, const std::complex<double>& point)
{
	out << "[" << point.real() << ";" << point.imag() << " * i" << "]";
	return out;
}

template <class T>
class Polyline {
	std::vector<T> v;
public:
	Polyline();
	size_t Vertex() const;
	auto GetLenght() const;
	void AddToHead(const T& point);
	void AddToEnd(const T& point);
	T& operator [] (const size_t index);
	T operator [] (const size_t index) const;
	Polyline operator + (const Polyline& polyline);
	bool operator == (const Polyline& polyline) const;
	bool operator != (const Polyline& polyline) const;
};

template <class T>
std::ostream& operator<< (std::ostream& out, const Polyline<T>& polyline)
{
	out << "Polyline <";
	for (size_t i = 0; i < polyline.Vertex(); i++)
	{
		if (i != polyline.Vertex() - 1) out << polyline[i] << ", ";
		else out << polyline[i];
	}
	out << ">";
	return out;
}

template<class T>
Polyline<T>::Polyline() {}

template <class T>
size_t Polyline<T>::Vertex() const
{
	return v.size();
}

template <class T>
auto Polyline<T>::GetLenght() const
{
	if (v.empty()) throw "Line is empty";
	if (Vertex() == 1) throw "Only one point in line";
	auto len = v[0].Distance(v[1]);
	for (size_t i = 1; i < Vertex() - 1; i++)
	{
		len += v[i].Distance(v[i + 1]);
	}
	return len;
}

template <>
auto Polyline<std::complex<double>>::GetLenght() const
{
	if (v.empty()) throw "Line is empty";
	if (Vertex() == 1) throw "Only one point in line";
	double len = 0;
	for (size_t i = 0; i < Vertex() - 1; i++)
	{
		len += std::abs(v[i + 1] - v[i]);
	}
	return len;
}

template <class T>
void Polyline<T>::AddToHead(const T& point)
{
	v.insert(v.begin(), point);
}

template <class T>
void Polyline<T>::AddToEnd(const T& point)
{
	v.push_back(point);
}

template <class T>
T& Polyline<T>::operator [] (const size_t index)
{
	if (v.empty()) throw "Line is empty";
	if ((index >= Vertex()) || (index < 0)) throw "Invalid index";
	return v[index];
}

template <class T>
T Polyline<T>::operator [] (const size_t index) const
{
	if (v.empty()) throw "Line is empty";
	if ((index >= Vertex()) || (index < 0)) throw "Invalid index";
	return v[index];
}

template <class T>
Polyline<T> Polyline<T>::operator + (const Polyline<T>& polyline)
{
	if (v.empty()) return polyline;
	if (!polyline.Vertex()) return *this;
	Polyline res(*this);
	res.v.resize(Vertex() + polyline.Vertex());
	for (size_t i = 0; i < Vertex(); i++)
	{
		res.v[i] = v[i];
	}
	size_t size = Vertex();
	for (size_t i = 0; i < polyline.Vertex(); i++)
	{
		res.v[size + i] = polyline.v[i];
	}
	return res;
}

template <class T>
bool Polyline<T>::operator == (const Polyline<T>& polyline) const
{
	if (Vertex() != polyline.Vertex()) return false;
	for (size_t i = 0; i < Vertex(); i++)
	{
		if (!(v[i] == polyline.v[i])) return false;
	}
	return true;
}

template <class T>
bool Polyline<T>::operator != (const Polyline<T>& polyline) const
{
	if (Vertex() != polyline.Vertex()) return true;
	for (size_t i = 0; i < Vertex(); i++)
	{
		if (!(v[i] == polyline.v[i])) return true;
	}
	return false;
}