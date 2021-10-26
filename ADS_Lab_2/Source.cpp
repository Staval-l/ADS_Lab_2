#include <iostream>
#include <conio.h>
#include <math.h>
#include "Polyline.h"


int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int MainMenu()
{
	std::cout << "Select:" << std::endl;
	std::cout << "\n - 1\n - 2\n - 3\nExit - Esc" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 49) || (key == 50) || (key == 51) || (key == 27)) return key;
	}
}


int Menu1()
{
	std::cout << "\n�������� ������ ������ - 1\n�������� ������ ������ - 2\n�������� ������ - 3\n��������� ������ �� ��������� - 4\n��������� ������ �� ����������� - 5\n�������� ���� ������ - 6\n����� - Esc" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 27)) return key;
	}
}

int Menu2()
{
	std::cout << "\n�������� ����� � ������ ������ - 1\n�������� ����� � ����� ������ - 2\n�������� ������� �� ������� - 3\n���������� ����� ������ - 4\n����� - Esc" << std::endl;
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
		int m1 = Menu1();
		if (m1 == 49)
		{
			while (true)
			{
				system("cls");
				std::cout << line_1 << std::endl;
				int m2 = Menu2();
				if (m2 == 49)
				{
					IntPoint2 p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p._x >> p._y;
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
					IntPoint2 p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p._x >> p._y;
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
					int index = 0;
					std::cout << "������� ������ ����������" << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_1[index]._x << "," << line_1[index]._y << ")" << std::endl;
						IntPoint2 p;
						std::cout << "������� ����������� ���������� �������" << std::endl;
						std::cin >> p._x >> p._y;
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
						std::cout << "����� ������: " << line_1.GetLenght() << std::endl;
						std::cout << "��� ������������� ��������: " << typeid(line_1.GetLenght()).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 27) break;
			}
		}

		if (m1 == 50)
		{
			while (true)
			{
				system("cls");
				//std::cout << line_2 << std::endl;
				int m2 = Menu2();
				if (m2 == 49)
				{
					IntPoint2 p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p._x >> p._y;
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
					IntPoint2 p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p._x >> p._y;
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
					int index = 0;
					std::cout << "������� ������ ����������" << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_2[index]._x << "," << line_2[index]._y << ")" << std::endl;
						IntPoint2 p;
						std::cout << "������� ����������� ���������� �������" << std::endl;
						std::cin >> p._x >> p._y;
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
						std::cout << "����� ������: " << line_2.GetLenght() << std::endl;
						std::cout << "��� ������������� ��������: " << typeid(line_2.GetLenght()).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 27) break;
			}
		}

		if (m1 == 51)
		{
			system("cls");
			//std::cout << line_1 << std::endl;
			//std::cout << line_2 << std::endl;
			system("pause");
		}

		if (m1 == 52)
		{
			system("cls");
			//if (line_1 == line_2) std::cout << "�����" << std::endl;
			//else std::cout << "�������" << std::endl;
			system("pause");
		}

		if (m1 == 53)
		{
			system("cls");
			if (line_1 != line_2) std::cout << "�����" << std::endl;
			else std::cout << "�������" << std::endl;
			system("pause");
		}

		if (m1 == 54)
		{
			system("cls");
			Polyline<IntPoint2> result = line_1 + line_2;
			//std::cout << result << std::endl;
			system("pause");
		}

		if (m1 == 27) break;
	}
}

void PolylineOfPoints3()
{
	Polyline<DoublePoint3> line_1, line_2;
	while (true)
	{
		system("cls");
		int m1 = Menu1();
		if (m1 == 49)
		{
			while (true)
			{
				system("cls");
				//std::cout << line_1 << std::endl;
				int m2 = Menu2();
				if (m2 == 49)
				{
					DoublePoint3 p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p._x >> p._y >> p._z;
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
					DoublePoint3 p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p._x >> p._y >> p._z;
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
					int index = 0;
					std::cout << "������� ������ ����������" << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_1[index]._x << "," << line_1[index]._y << line_1[index]._z << ")" << std::endl;
						DoublePoint3 p;
						std::cout << "������� ����������� ���������� �������" << std::endl;
						std::cin >> p._x >> p._y >> p._z;
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
						std::cout << "����� ������: " << line_1.GetLenght() << std::endl;
						std::cout << "��� ������������� ��������: " << typeid(line_1.GetLenght()).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 27) break;
			}
		}

		if (m1 == 50)
		{
			while (true)
			{
				system("cls");
				//std::cout << line_2 << std::endl;
				int m2 = Menu2();
				if (m2 == 49)
				{
					DoublePoint3 p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p._x >> p._y >> p._z;
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
					DoublePoint3 p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p._x >> p._y >> p._z;
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
					int index = 0;
					std::cout << "������� ������ ����������" << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_2[index]._x << "," << line_2[index]._y << line_2[index]._z << ")" << std::endl;
						DoublePoint3 p;
						std::cout << "������� ����������� ���������� �������" << std::endl;
						std::cin >> p._x >> p._y >> p._z;
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
						auto length = line_2.GetLenght();
						std::cout << "����� ������: " << length << std::endl;
						std::cout << "��� ������������� ��������: " << typeid(length).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 27) break;
			}
		}

		if (m1 == 51)
		{
			system("cls");
			//std::cout << line_1 << std::endl;
			//std::cout << line_2 << std::endl;
			system("pause");
		}

		if (m1 == 52)
		{
			system("cls");
			if (line_1 == line_2) std::cout << "�����" << std::endl;
			else std::cout << "�������" << std::endl;
			system("pause");
		}

		if (m1 == 53)
		{
			system("cls");
			if (line_1 != line_2) std::cout << "�����" << std::endl;
			else std::cout << "�������" << std::endl;
			system("pause");
		}

		if (m1 == 54)
		{
			system("cls");
			Polyline<DoublePoint3> result = line_1 + line_2;
			//std::cout << result << std::endl;
			system("pause");
		}

		if (m1 == 27) break;
	}
}
int main()
{
	while (true)
	{
		system("cls");
		int polyline_type = MainMenu();

		if (polyline_type == 49) PolylineOfPoints2();

		if (polyline_type == 50) PolylineOfPoints3();

		if (polyline_type == 51) continue;

		if (polyline_type == 27) break;
	}
	return 0;
}