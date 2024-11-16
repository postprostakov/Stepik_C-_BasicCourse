#include <iostream>;
#include <ctime>;
#include <conio.h>;
#include <stdio.h>;
using namespace std;
void size();
void integer();
int main();
void Float();
void Double();

int pr1()
{
	setlocale(LC_ALL, "Rus");
	int i = 0;
	int choice;
	for (;;)
	{

		cout << "1.Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных" << endl;
		cout << "2.Вывести на экран двоичное представление в памяти целого числа" << endl;
		cout << "3.Вывести на экран двоичное представление в памяти вещественного числа (типа float)" << endl;
		cout << "4.Вывести на экран двоичное представление в памяти числа типа double" << endl;
		cout << "5.Выход в главное меню" << endl;
		cout << "Выберите пункт меню. И введите номер выбранного пункта = ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\n" << "\n";
			size();
			cout << "\n" << "\n";
			break;
		}
		case 2:
		{
			cout << "\n" << "\n";
			integer();
			cout << "\n" << "\n";
			break;
		}
		case 3:
		{
			cout << "\n" << "\n";
			Float();
			cout << "\n" << "\n";

			break;
		}
		case 4:
		{
			cout << "\n" << "\n";
			Double();
			cout << "\n" << "\n";
			break;
		}
		case 5:
		{
			cout << "\n" << "\n";
			return 1;
			break;
		}

		default:
			break;
		
		}

	}

}


void size()
{
	setlocale(LC_ALL, "Rus");
	int value;
	cout << "Memory size (byte) of int: " << sizeof(value) << endl;
	cout << "Memory size (byte) of short int: " << sizeof((short int)value) << endl;
	cout << "Memory size (byte) of long int: " << sizeof((long int)value) << endl;
	cout << "Memory size (byte) of float: " << sizeof((float)value) << endl;
	cout << "Memory size (byte) of double: " << sizeof((double)value) << endl;
	cout << "Memory size (byte) of long double: " << sizeof((long double)value) << endl;
	cout << "Memory size (byte) of char: " << sizeof((char)value) << endl;
	cout << "Memory size (byte) of bool: " << sizeof((bool)value) << endl;

}

		void integer()
		{
	
	setlocale(LC_ALL, "Rus");
	int value;
	int temp;
	int placeCount, k;
	unsigned int order = 32;
	unsigned int mask = 1 << order - 1;
	k = 0;
	cout << "Введите целое число (положительное или отрицательное)";
	cin >> value;
	cout << "\n";
	cout << "Целое число: "<<value << endl;
	if (value < 0)
	{
		k = 1;
	}
	temp = value;
	do
	{
		placeCount = temp / 2;
		temp = placeCount;
		k = k + 1;
	} while (abs(placeCount) > 0);
	cout << "Significant digits: " << k << endl;
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		value <<= 1;
		if (i == 1)
		{
			putchar(' ');
		}
		if (i == (order - k))
		{
			putchar(' ');
		}
	}
		}

		void Float()
		{
			setlocale(LC_ALL, "Rus");
			unsigned int order = 32;
			unsigned int mask = 1 << order - 1;
			
			union 
			{
				int tool;
				float numb_f;
			};

			cout << "Введите вещественное число (положительное или отрицательное)";
			cin >> numb_f;
			cout << "\n";
			cout << "Число в десятичной системе счисления: " << numb_f << endl;
			cout << " Число, записанное согласно стандарту ieee-754: ";
			for (int i = 1; i <= order; i++)
			{
				putchar(tool & mask ? '1' : '0');
				tool <<= 1;
				if (i == 1)
				{
					putchar(' ');
				}
				if (i == 9)
				{
					putchar(' ');
				}
			}
		
		}

		void Double()
		{
			setlocale(LC_ALL, "Rus");
			unsigned int order = 64;
			unsigned int mask = 1 << order - 1;
			union {
				int arr[2];
				double numb_f;
			};

			cout << "Введите вещественное число (положительное или отрицательное)";
			cin >> numb_f;
			cout << "\n";
			cout << "Число в десятичной системе счисления: " << numb_f << endl;
			cout << " Число, записанное согласно стандарту ieee-754: ";
			for (int n = 1; n >= 0; n--)
			{
				for (int i = 1; i <= order / 2; i++)
				{
					putchar(arr[n] & mask ? '1' : '0');
					arr[n] <<= 1;
					if ((n == 1) && (i == 1))
					{
						putchar(' ');
					}
					if ((n == 1) && (i == 12))
					{
						putchar(' ');
					}
				}
			}


		}


		


