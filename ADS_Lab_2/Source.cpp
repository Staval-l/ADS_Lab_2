#include <iostream>
#include <conio.h>
#include <math.h>
#include <complex>
#include "Polyline.h"

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int FirstMenu()
{
	std::cout << "Good day! Let's start. Select type of numbers:\n" << std::endl;
	std::cout << "1 - Work with IntPoint2\n2 - Work with DoublePoint3\n3 - Work with ComplexPoint\n\nEsc - Exit" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 49) || (key == 50) || (key == 51) || (key == 27)) return key;
	}
}


int SecondMenu()
{
	std::cout << "1 - Work with first polyline\n2 - Work with second polyline\n3 - Show polylines\n4 - The sum of two polylines in first\n5 - The sum of two polylines in second\n6 - Check polylines for equality\n\nEsc - Return back" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 27)) return key;
	}
}

int ThirdMenu()
{
	std::cout << "1 - Add point to head of the polyline\n2 - Add point to end of the polyline\n3 - Change point by index\n4 - Calculate lenght of the polyline\n\nEsc - Return back" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 27)) return key;
	}
}

void PolylineOfPoints2()
{
	Polyline<IntPoint2> line_1, line_2;
	while (true)
	{
		system("cls");
		int m1 = SecondMenu();
		if (m1 == 27) break;
		if (m1 == 49)
		{
			while (true)
			{
				system("cls");
				std::cout << line_1 << std::endl;
				int m2 = ThirdMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates of the point" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_1.AddToHead(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates of the point:" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_1.AddToEnd(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					int index = 0;
					std::cout << "Enter index of element:" << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_1[index]._x << "," << line_1[index]._y << ")" << std::endl;
						IntPoint2 p;
						std::cout << "Enter the coordinates of the point: " << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p._x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p._y;
						line_1[index]._x = p._x;
						line_1[index]._y = p._y;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_1.GetLenght() << std::endl;
						std::cout << "Return type: " << typeid(line_1.GetLenght()).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 50)
		{
			while (true)
			{
				system("cls");
				std::cout << line_2 << std::endl;
				int m2 = ThirdMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates of the point:" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_2.AddToHead(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates of the point: " << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_2.AddToEnd(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					int index = 0;
					std::cout << "Enter index of element: " << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_2[index]._x << "," << line_2[index]._y << ")" << std::endl;
						IntPoint2 p;
						std::cout << "Enter the coordinates of the point: " << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p._x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p._y;
						line_2[index]._x = p._x;
						line_2[index]._y = p._y;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_2.GetLenght() << std::endl;
						std::cout << "Return type: " << typeid(line_2.GetLenght()).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 51)
		{
			system("cls");
			std::cout << line_1 << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 52)
		{
			system("cls");
			line_1 = line_1 + line_2;
			std::cout << "Successfully" << std::endl;
			std::cout << line_1 << std::endl;
			system("pause");
		}
		if (m1 == 53)
		{
			system("cls");
			line_2 = line_2 + line_1;
			std::cout << "Successfully" << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 54)
		{
			system("cls");
			if (line_1 == line_2) std::cout << "Lines are equal" << std::endl;
			else std::cout << "Lines aren't equal" << std::endl;
			system("pause");
		}
	}
}

void PolylineOfPoints3()
{
	Polyline<DoublePoint3> line_1, line_2;
	while (true)
	{
		system("cls");
		int m1 = SecondMenu();
		if (m1 == 27) break;
		if (m1 == 49)
		{
			while (true)
			{
				system("cls");
				std::cout << line_1 << std::endl;
				int m2 = ThirdMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					DoublePoint3 p;
					std::cout << "Enter the coordinates of the point: " << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					std::cout << "Enter z: " << std::endl;
					std::cin >> p._z;
					try
					{
						line_1.AddToHead(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					system("cls");
					DoublePoint3 p;
					std::cout << "Enter the coordinates of the point: " << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					std::cout << "Enter z: " << std::endl;
					std::cin >> p._z;
					try
					{
						line_1.AddToEnd(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					int index = 0;
					std::cout << "Enter index of element: " << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_1[index]._x << "," << line_1[index]._y << "," << line_1[index]._z << ")" << std::endl;
						DoublePoint3 p;
						std::cout << "Enter the coordinates of the point: " << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p._x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p._y;
						std::cout << "Enter z: " << std::endl;
						std::cin >> p._z;
						line_1[index]._x = p._x;
						line_1[index]._y = p._y;
						line_1[index]._z = p._z;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_1.GetLenght() << std::endl;
						std::cout << "Return type: " << typeid(line_1.GetLenght()).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 50)
		{
			while (true)
			{
				system("cls");
				std::cout << line_2 << std::endl;
				int m2 = ThirdMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					DoublePoint3 p;
					std::cout << "Enter the coordinates of the point: " << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					std::cout << "Enter z: " << std::endl;
					std::cin >> p._z;
					try
					{
						line_2.AddToHead(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					system("cls");
					DoublePoint3 p;
					std::cout << "Enter the coordinates of the point: " << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					std::cout << "Enter z: " << std::endl;
					std::cin >> p._z;
					try
					{
						line_2.AddToEnd(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					int index = 0;
					std::cout << "Enter index of element: " << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_2[index]._x << "," << line_2[index]._y << "," << line_2[index]._z << ")" << std::endl;
						DoublePoint3 p;
						std::cout << "Enter the coordinates of the point: " << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p._x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p._y;
						std::cout << "Enter z: " << std::endl;
						std::cin >> p._z;
						line_2[index]._x = p._x;
						line_2[index]._y = p._y;
						line_2[index]._z = p._z;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_2.GetLenght() << std::endl;
						std::cout << "Return type: " << typeid(line_2.GetLenght()).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 51)
		{
			system("cls");
			std::cout << line_1 << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 52)
		{
			system("cls");
			line_1 = line_1 + line_2;
			std::cout << "Successfully" << std::endl;
			std::cout << line_1 << std::endl;
			system("pause");
		}
		if (m1 == 53)
		{
			system("cls");
			line_2 = line_2 + line_1;
			std::cout << "Successfully" << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 54)
		{
			system("cls");
			if (line_1 == line_2) std::cout << "Lines are equal" << std::endl;
			else std::cout << "Lines aren't equal" << std::endl;
			system("pause");
		}
	}
}

void PolylineOfComplex()
{
	Polyline<std::complex<double>> line_1, line_2;
	while (true)
	{
		system("cls");
		int m1 = SecondMenu();
		if (m1 == 27) break;
		if (m1 == 49)
		{
			while (true)
			{
				system("cls");
				std::cout << line_1 << std::endl;
				int m2 = ThirdMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					std::cout << "Enter the coordinates of the point: " << std::endl;
					std::cout << "Enter real part: " << std::endl;
					double _re = 0;
					std::cin >> _re;
					std::cout << "Enter imag part: " << std::endl;
					double _im = 0;
					std::cin >> _im;
					std::complex<double> p(_re, _im);
					try
					{
						line_1.AddToHead(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					system("cls");
					std::cout << "Enter the coordinates of the point: " << std::endl;
					std::cout << "Enter real part: " << std::endl;
					double _re = 0;
					std::cin >> _re;
					std::cout << "Enter imag part: " << std::endl;
					double _im = 0;
					std::cin >> _im;
					std::complex<double> p(_re, _im);
					try
					{
						line_1.AddToEnd(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					try
					{
						int index = 0;
						std::cout << "Enter index of element:" << std::endl;
						std::cin >> index;
						std::cout << "(" << line_1[index].real() << "," << line_1[index].imag() << ")" << std::endl;
						std::cout << "Enter the coordinates of the point: " << std::endl;
						double _re = 0;
						std::cin >> _re;
						std::cout << "Enter imag part: " << std::endl;
						double _im = 0;
						std::cin >> _im;
						std::complex<double> p(_re, _im);
						line_1[index] = p;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_1.GetLenght() << std::endl;
						std::cout << "Return type: " << typeid(line_1.GetLenght()).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 50)
		{
			while (true)
			{
				system("cls");
				std::cout << line_2 << std::endl;
				int m2 = ThirdMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					std::cout << "Enter the coordinates of the point: " << std::endl;
					std::cout << "Enter real part: " << std::endl;
					double _re = 0;
					std::cin >> _re;
					std::cout << "Enter imag part: " << std::endl;
					double _im = 0;
					std::cin >> _im;
					std::complex<double> p(_re, _im);
					try
					{
						line_2.AddToHead(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					system("cls");
					std::cout << "Enter the coordinates of the point: " << std::endl;
					std::cout << "Enter real part: " << std::endl;
					double _re = 0;
					std::cin >> _re;
					std::cout << "Enter imag part: " << std::endl;
					double _im = 0;
					std::cin >> _im;
					std::complex<double> p(_re, _im);
					try
					{
						line_2.AddToEnd(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					try
					{
						int index = 0;
						std::cout << "Enter index of element:" << std::endl;
						std::cin >> index;
						std::cout << "(" << line_2[index].real() << "," << line_2[index].imag() << ")" << std::endl;
						std::cout << "Enter the coordinates of the point: " << std::endl;
						double _re = 0;
						std::cin >> _re;
						std::cout << "Enter imag part: " << std::endl;
						double _im = 0;
						std::cin >> _im;
						std::complex<double> p(_re, _im);
						line_2[index] = p;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_2.GetLenght() << std::endl;
						std::cout << "Return type: " << typeid(line_2.GetLenght()).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 51)
		{
			system("cls");
			std::cout << line_1 << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 52)
		{
			system("cls");
			line_1 = line_1 + line_2;
			std::cout << "Successfully" << std::endl;
			std::cout << line_1 << std::endl;
			system("pause");
		}
		if (m1 == 53)
		{
			system("cls");
			line_2 = line_2 + line_1;
			std::cout << "Successfully" << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 54)
		{
			system("cls");
			if (line_1 == line_2) std::cout << "Lines are equal" << std::endl;
			else std::cout << "Lines aren't equal" << std::endl;
			system("pause");
		}
	}
}

int main()
{
	while (true)
	{
		system("cls");
		int m = FirstMenu();
		if (m == 27) break;
		if (m == 49) PolylineOfPoints2();
		if (m == 50) PolylineOfPoints3();
		if (m == 51) PolylineOfComplex();
	}
	return 0;
}