#include <iostream>
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;
using namespace chrono;
int GetRand(int min, int max);
void Spiral(int (& arr)[10][10]);
void clear();
void Snake(int(&arr)[10][10]);
void BlockA(int(&arr)[10][10]);
void BlockB(int(&arr)[10][10]);
void BlockC(int(&arr)[10][10]);
void BlockD(int(&arr)[10][10]);
void Sort3(int(&arr)[10][10]);
void Arithmetic(int(&arr)[10][10]);

int pr3()
{
	setlocale(LC_ALL, "Rus");
	const int N = 10;
	int mass[10][10];
	int choice;
	for (;;)
	{

		cout << "1.Используя арифметику указателей, заполнить квадратичную целочисленную матрицу порядка 10 случайными числами от 1 до 100 по схеме Спираль" << endl<< endl;
		cout << "2.Используя арифметику указателей, заполнить квадратичную целочисленную матрицу порядка 10 случайными числами от 1 до 100 по схеме Змейка" << endl << endl;
		cout << "3.Получить новую матрицу перестановкой блоков по схеме а" << endl << endl;
		cout << "4.Получить новую матрицу перестановкой блоков по схеме б" << endl << endl;
		cout << "5.Получить новую матрицу перестановкой блоков по схеме в" << endl << endl;
		cout << "6.Получить новую матрицу перестановкой блоков по схеме г" << endl << endl;
		cout << "7.Используя арифметику указателей, сортировать элементы методом shaker sort" << endl << endl;
		cout << "8.Выполнить уменьшение/умножение/деление элементов матрицы на введенное пользователем число, использую только арифметику указателей" << endl << endl;
		cout << "9.Выход в главное меню" << endl << endl;
		cout << "Выберите пункт меню. И введите номер выбранного пункта = ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\n" << "\n";
			Spiral(mass);
			cout << "\n" << "\n";
			break;
		}
		case 2:
		{
			cout << "\n" << "\n";
			Snake(mass);
			cout << "\n" << "\n";
			break;
		}
		case 3:
		{
			cout << "\n" << "\n";
			BlockA(mass);
			cout << "\n" << "\n";
						break;
		}
		case 4:
		{
			cout << "\n" << "\n";
			BlockB(mass);
			cout << "\n" << "\n";
			break;
		}
		case 5:
		{
			
			cout << "\n" << "\n";
			BlockC(mass);
			cout << "\n" << "\n";
			break;
		}
		case 6:
		{
			
			cout << "\n" << "\n";
			BlockD(mass);
			cout << "\n" << "\n";
			break;
		}

		case 7:
		{
			
			cout << "\n" << "\n";
			Sort3(mass);
			cout << "\n" << "\n";
			break;
		}

		case 8:
		{

			cout << "\n" << "\n";
			Arithmetic(mass);
			cout << "\n" << "\n";
			break;
		}
		
		case 9:
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


void Spiral(int (& arr)[10][10])
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int width = 3;
	int k;
	int* first = nullptr;
	int* ptr = nullptr;
	int* aP = nullptr;
	int n0 = sizeof(arr) / sizeof(*arr);
	int m0 = sizeof(*arr) / sizeof(**arr);
	int* end = *arr + m0 * n0 - 1;
	int iter;
	int n1, m1;

	clear();

	for (int* ptr = *arr; ptr <= end; ptr++)
	{
		*ptr = GetRand(1, 100);
	}


	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);


	for (aP = *arr, n1 = n0, m1 = m0, iter = 0; n1 >= 2; aP = aP + (m0 + 1), n1 = n1 - 2, m1 = m1 - 2, iter++)
	{
		end = aP + (n1 - 1);

		for (int* ptr = aP, k = iter; ptr <= end; ptr++, k++)

		{
			destCoord.X = width * k;
			destCoord.Y = (ptr - *arr) / m0;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *ptr << " ";
			cout.flush();
			Sleep(50);
		}

		first = end + n0;
		end = first + n0 * (m0 - 2 * (iter + 1));


		for (ptr = first; ptr <= end; ptr = ptr + n0)
		{
			k = m0 - iter - 1;
			destCoord.X = width * k;
			destCoord.Y = (ptr - *arr) / m0;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *ptr << " ";
			cout.flush();
			Sleep(50);
		}

		first = end - 1;
		end = first - (n1 - 2);

		for (ptr = first, k = (m0 - 2 - iter); ptr >= end; ptr--, k--)
		{
			destCoord.X = width * k;
			destCoord.Y = (ptr - *arr) / m0;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *ptr << " ";
			cout.flush();
			Sleep(50);
		}


		first = end - n0;
		end = first - n0 * (m0 - 2 * (iter + 1));


		for (ptr = first; ptr > end; ptr = ptr - m0)
		{
			destCoord.X = width * iter;
			destCoord.Y = (ptr - *arr) / m0;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *ptr << " ";
			cout.flush();
			Sleep(50);
		}
	}
		cout << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n";


	for (int l = 0; l < m0; l++)
	{
		for (int r = 0; r < n0; r++)
		{
			cout << arr[l][r] << " ";
			if (r == (n0 - 1))
				cout << endl;
		}
	}
}

void clear() 
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void Snake(int(&arr)[10][10])
{
int width = 3;
int k;
int* first = nullptr;
int* ptr = nullptr;
int* aP = nullptr;
int n0 = sizeof(arr) / sizeof(*arr);
int m0 = sizeof(*arr) / sizeof(**arr);
int* end = *arr + m0 * n0 - 1;
int iter;

clear();

for (int* ptr = *arr; ptr <= end; ptr++)
{
	*ptr = GetRand(1, 36);
}


HANDLE hStdout;
COORD destCoord;
hStdout = GetStdHandle(STD_OUTPUT_HANDLE);



for (aP = *arr, iter = 0, k = 0; iter <= (n0 / 2 - 1); aP = aP + 2, iter++, k = k + 2)
{
	end = aP + n0 * (m0 - 1);

	for (ptr = aP; ptr <= end; ptr = ptr + n0)
	{
		destCoord.X = width * k;
		destCoord.Y = (ptr - *arr) / m0;
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << *ptr << " ";
		cout.flush();
		Sleep(50);
	}

	first = end + 1;
	end = first - n0 * (m0 - 1);

	for (ptr = first; ptr >= end; ptr = ptr - n0)
	{
		destCoord.X = width * (k + 1);
		destCoord.Y = (ptr - *arr) / m0;
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << *ptr << " ";
		cout.flush();
		Sleep(50);
	}

}

 cout << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n";
 cout << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n";

for (int l = 0; l < m0; l++)
{
	for (int r = 0; r < n0; r++)
	{
		cout << arr[l][r] << " ";
		if (r == (n0 - 1))
			cout << endl;
	}
}
}

void BlockA(int(&arr)[10][10])
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	const int M = 10;
	const int N = 5;
	int arr1[N][N];
	int arr2[N][N];
	int arr3[N][N];
	int arr4[N][N];
	int width = 3;
	int k;
	int* first = nullptr;
	int* ptr = nullptr;
	int* ptr1 = nullptr;
	int* aP = nullptr;
	int* aP1 = nullptr;
	int n0 = sizeof(arr) / sizeof(*arr);
	int m0 = sizeof(*arr) / sizeof(**arr);
	int* end = *arr + m0 * n0 - 1;
	int* end1 = nullptr;
	int iter;
	int n1, m1;

	clear();

	for (ptr = *arr; ptr <= end; ptr++)
	{
		*ptr = GetRand(1, 100);
	}

	cout << "Исходный вид массива" << endl;

	for (int l = 0; l < n0; l++)
	{
		for (int r = 0; r < m0; r++)
		{
			cout << arr[l][r] << " ";
			if (r == (n0 - 1))
				cout << endl;
		}
	}

	cout << "\n" << "\n" << "\n" << "\n";

	//Сборка первой коробки

	for (aP = *arr, end = *arr + n0 / 2 - 1, aP1 = *arr1, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr1 = *ptr;

		}
	}

	//Сборка второй коробки

	for (aP = *arr + n0 / 2, end = *arr + n0 - 1, aP1 = *arr2, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr1 = *ptr;

		}
	}

	//Сборка третьей коробки

	for (aP = *arr + n0 * n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 - 1, aP1 = *arr3, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr1 = *ptr;

		}
	}

	//Сборка четвертой коробки

	for (aP = *arr + n0 * n0 / 2 + n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 + n0 / 2 - 1, aP1 = *arr4, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr1 = *ptr;

		}
	}


	//Запись третьей коробки

	for (aP = *arr, end = *arr + n0 / 2 - 1, aP1 = *arr3, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr = *ptr1;

		}
	}

	//Запись первой коробки

	for (aP = *arr + n0 / 2, end = *arr + n0 - 1, aP1 = *arr1, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr = *ptr1;

		}
	}

	//Запись третьей коробки

	for (aP = *arr + n0 * n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 - 1, aP1 = *arr4, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr = *ptr1;

		}
	}

	//Запись четвертой коробки

	for (aP = *arr + n0 * n0 / 2 + n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 + n0 / 2 - 1, aP1 = *arr2, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
	{

		for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
		{
			*ptr = *ptr1;

		}
	}


	for (int l = 0; l < n0 / 2; l++)
	{
		for (int r = 0; r < n0 / 2; r++)
		{
			cout << arr1[l][r] << " ";
			if (r == (n0 / 2 - 1))
				cout << endl;

		}
	}

	cout << "\n" << "\n" << "\n" << "\n";


	for (int l = 0; l < n0 / 2; l++)
	{
		for (int r = 0; r < n0 / 2; r++)
		{
			cout << arr2[l][r] << " ";
			if (r == (n0 / 2 - 1))
				cout << endl;

		}
	}

	cout << "\n" << "\n" << "\n" << "\n";


	for (int l = 0; l < n0 / 2; l++)
	{
		for (int r = 0; r < n0 / 2; r++)
		{
			cout << arr3[l][r] << " ";
			if (r == (n0 / 2 - 1))
				cout << endl;

		}
	}





cout << "\n" << "\n" << "\n" << "\n";


for (int l = 0; l < n0 / 2; l++)
{
	for (int r = 0; r < n0 / 2; r++)
	{
		cout << arr4[l][r] << " ";
		if (r == (n0 / 2 - 1))
			cout << endl;

	}
}

cout << "\n" << "\n" << "\n" << "\n";

cout << "Вид массива после перестановки:" << endl;

for (int l = 0; l < n0; l++)
{
	for (int r = 0; r < m0; r++)
	{
		cout << arr[l][r] << " ";
		if (r == (n0 - 1))
			cout << endl;
	}
}
		}

	void BlockB(int(&arr)[10][10])
{
			srand(time(NULL));
			setlocale(LC_ALL, "ru");
			const int M = 10;
			const int N = 5;
			int arr1[N][N];
			int arr2[N][N];
			int arr3[N][N];
			int arr4[N][N];
			int width = 3;
			int k;
			int* first = nullptr;
			int* ptr = nullptr;
			int* ptr1 = nullptr;
			int* aP = nullptr;
			int* aP1 = nullptr;
			int n0 = sizeof(arr) / sizeof(*arr);
			int m0 = sizeof(*arr) / sizeof(**arr);
			int* end = *arr + m0 * n0 - 1;
			int* end1 = nullptr;
			int iter;
			int n1, m1;

			clear();


			for (ptr = *arr; ptr <= end; ptr++)
			{
				*ptr = GetRand(1, 100);
			}

			cout << "Исходный вид массива" << endl;

			for (int l = 0; l < n0; l++)
			{
				for (int r = 0; r < m0; r++)
				{
					cout << arr[l][r] << " ";
					if (r == (n0 - 1))
						cout << endl;
				}
			}

			cout << "\n" << "\n" << "\n" << "\n";

			//Сборка первой коробки

			for (aP = *arr, end = *arr + n0 / 2 - 1, aP1 = *arr1, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
			{

				for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
				{
					*ptr1 = *ptr;

				}
			}

			//Сборка второй коробки

			for (aP = *arr + n0 / 2, end = *arr + n0 - 1, aP1 = *arr2, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
			{

				for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
				{
					*ptr1 = *ptr;

				}
			}

			//Сборка третьей коробки

			for (aP = *arr + n0 * n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 - 1, aP1 = *arr3, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
			{

				for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
				{
					*ptr1 = *ptr;

				}
			}

			//Сборка четвертой коробки

			for (aP = *arr + n0 * n0 / 2 + n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 + n0 / 2 - 1, aP1 = *arr4, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
			{

				for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
				{
					*ptr1 = *ptr;

				}
			}


			//Запись первой коробки

			for (aP = *arr, end = *arr + n0 / 2 - 1, aP1 = *arr4, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
			{

				for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
				{
					*ptr = *ptr1;

				}
			}

			//Запись второй коробки

			for (aP = *arr + n0 / 2, end = *arr + n0 - 1, aP1 = *arr3, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
			{

				for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
				{
					*ptr = *ptr1;

				}
			}

			//Запись третьей коробки

			for (aP = *arr + n0 * n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 - 1, aP1 = *arr2, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
			{

				for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
				{
					*ptr = *ptr1;

				}
			}

			//Запись четвертой коробки

			for (aP = *arr + n0 * n0 / 2 + n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 + n0 / 2 - 1, aP1 = *arr1, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
			{

				for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
				{
					*ptr = *ptr1;

				}
			}


			for (int l = 0; l < n0 / 2; l++)
			{
				for (int r = 0; r < n0 / 2; r++)
				{
					cout << arr1[l][r] << " ";
					if (r == (n0 / 2 - 1))
						cout << endl;

				}
			}

			cout << "\n" << "\n" << "\n" << "\n";


			for (int l = 0; l < n0 / 2; l++)
			{
				for (int r = 0; r < n0 / 2; r++)
				{
					cout << arr2[l][r] << " ";
					if (r == (n0 / 2 - 1))
						cout << endl;

				}
			}

			cout << "\n" << "\n" << "\n" << "\n";


			for (int l = 0; l < n0 / 2; l++)
			{
				for (int r = 0; r < n0 / 2; r++)
				{
					cout << arr3[l][r] << " ";
					if (r == (n0 / 2 - 1))
						cout << endl;

				}
			}

			cout << "\n" << "\n" << "\n" << "\n";


			for (int l = 0; l < n0 / 2; l++)
			{
				for (int r = 0; r < n0 / 2; r++)
				{
					cout << arr4[l][r] << " ";
					if (r == (n0 / 2 - 1))
						cout << endl;

				}
			}

			cout << "\n" << "\n" << "\n" << "\n";

			cout << "Вид массива после перестановки: " << endl;

			for (int l = 0; l < n0; l++)
			{
				for (int r = 0; r < m0; r++)
				{
					cout << arr[l][r] << " ";
					if (r == (n0 - 1))
						cout << endl;
				}
			}


}

void BlockC(int(&arr)[10][10])
{
		srand(time(NULL));
		setlocale(LC_ALL, "ru");
		const int M = 10;
		const int N = 5;
		int arr1[N][N];
		int arr2[N][N];
		int arr3[N][N];
		int arr4[N][N];
		int width = 3;
		int k;
		int* first = nullptr;
		int* ptr = nullptr;
		int* ptr1 = nullptr;
		int* aP = nullptr;
		int* aP1 = nullptr;
		int n0 = sizeof(arr) / sizeof(*arr);
		int m0 = sizeof(*arr) / sizeof(**arr);
		int* end = *arr + m0 * n0 - 1;
		int* end1 = nullptr;
		int iter;
		int n1, m1;

		clear();

		for (ptr = *arr; ptr <= end; ptr++)
		{
			*ptr = GetRand(1, 100);
		}

		cout << "Исходный вид массива" << endl;

		for (int l = 0; l < n0; l++)
		{
			for (int r = 0; r < m0; r++)
			{
				cout << arr[l][r] << " ";
				if (r == (n0 - 1))
					cout << endl;
			}
		}

		cout << "\n" << "\n" << "\n" << "\n";

		//Сборка первой коробки

		for (aP = *arr, end = *arr + n0 / 2 - 1, aP1 = *arr1, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr1 = *ptr;

			}
		}

		//Сборка второй коробки

		for (aP = *arr + n0 / 2, end = *arr + n0 - 1, aP1 = *arr2, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr1 = *ptr;

			}
		}

		//Сборка третьей коробки

		for (aP = *arr + n0 * n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 - 1, aP1 = *arr3, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr1 = *ptr;

			}
		}

		//Сборка четвертой коробки

		for (aP = *arr + n0 * n0 / 2 + n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 + n0 / 2 - 1, aP1 = *arr4, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr1 = *ptr;

			}
		}


		//Запись первой коробки

		for (aP = *arr, end = *arr + n0 / 2 - 1, aP1 = *arr3, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr = *ptr1;

			}
		}

		//Запись второй коробки

		for (aP = *arr + n0 / 2, end = *arr + n0 - 1, aP1 = *arr4, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr = *ptr1;

			}
		}

		//Запись третьей коробки

		for (aP = *arr + n0 * n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 - 1, aP1 = *arr1, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr = *ptr1;

			}
		}

		//Запись четвертой коробки

		for (aP = *arr + n0 * n0 / 2 + n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 + n0 / 2 - 1, aP1 = *arr2, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr = *ptr1;

			}
		}


		for (int l = 0; l < n0 / 2; l++)
		{
			for (int r = 0; r < n0 / 2; r++)
			{
				cout << arr1[l][r] << " ";
				if (r == (n0 / 2 - 1))
					cout << endl;

			}
		}

		cout << "\n" << "\n" << "\n" << "\n";


		for (int l = 0; l < n0 / 2; l++)
		{
			for (int r = 0; r < n0 / 2; r++)
			{
				cout << arr2[l][r] << " ";
				if (r == (n0 / 2 - 1))
					cout << endl;

			}
		}

		cout << "\n" << "\n" << "\n" << "\n";


		for (int l = 0; l < n0 / 2; l++)
		{
			for (int r = 0; r < n0 / 2; r++)
			{
				cout << arr3[l][r] << " ";
				if (r == (n0 / 2 - 1))
					cout << endl;

			}
		}

		cout << "\n" << "\n" << "\n" << "\n";


		for (int l = 0; l < n0 / 2; l++)
		{
			for (int r = 0; r < n0 / 2; r++)
			{
				cout << arr4[l][r] << " ";
				if (r == (n0 / 2 - 1))
					cout << endl;

			}
		}

		cout << "\n" << "\n" << "\n" << "\n";

		cout << "Вид массива после перестановки: " << endl;

		for (int l = 0; l < n0; l++)
		{
			for (int r = 0; r < m0; r++)
			{
				cout << arr[l][r] << " ";
				if (r == (n0 - 1))
					cout << endl;
			}
		}

	}

	void BlockD(int(&arr)[10][10])
	{
		srand(time(NULL));
		setlocale(LC_ALL, "ru");
		const int M = 10;
		const int N = 5;
		int arr1[N][N];
		int arr2[N][N];
		int arr3[N][N];
		int arr4[N][N];
		int width = 3;
		int k;
		int* first = nullptr;
		int* ptr = nullptr;
		int* ptr1 = nullptr;
		int* aP = nullptr;
		int* aP1 = nullptr;
		int n0 = sizeof(arr) / sizeof(*arr);
		int m0 = sizeof(*arr) / sizeof(**arr);
		int* end = *arr + m0 * n0 - 1;
		int* end1 = nullptr;
		int iter;
		int n1, m1;

		clear();

		for (ptr = *arr; ptr <= end; ptr++)
		{
			*ptr = GetRand(1, 100);
		}

		cout << "Исходный вид массива" << endl;

		for (int l = 0; l < n0; l++)
		{
			for (int r = 0; r < m0; r++)
			{
				cout << arr[l][r] << " ";
				if (r == (n0 - 1))
					cout << endl;
			}
		}

		cout << "\n" << "\n" << "\n" << "\n";

		//Сборка первой коробки

		for (aP = *arr, end = *arr + n0 / 2 - 1, aP1 = *arr1, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr1 = *ptr;

			}
		}

		//Сборка второй коробки

		for (aP = *arr + n0 / 2, end = *arr + n0 - 1, aP1 = *arr2, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr1 = *ptr;

			}
		}

		//Сборка третьей коробки

		for (aP = *arr + n0 * n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 - 1, aP1 = *arr3, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr1 = *ptr;

			}
		}

		//Сборка четвертой коробки

		for (aP = *arr + n0 * n0 / 2 + n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 + n0 / 2 - 1, aP1 = *arr4, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr1 = *ptr;

			}
		}


		//Запись первой коробки

		for (aP = *arr, end = *arr + n0 / 2 - 1, aP1 = *arr2, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr = *ptr1;

			}
		}

		//Запись второй коробки

		for (aP = *arr + n0 / 2, end = *arr + n0 - 1, aP1 = *arr1, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr = *ptr1;

			}
		}

		//Запись третьей коробки

		for (aP = *arr + n0 * n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 - 1, aP1 = *arr4, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr = *ptr1;

			}
		}

		//Запись четвертой коробки

		for (aP = *arr + n0 * n0 / 2 + n0 / 2, end = *arr + n0 * n0 / 2 + n0 / 2 + n0 / 2 - 1, aP1 = *arr3, k = 1; k <= n0 / 2; aP = aP + n0, end = end + n0, aP1 = aP1 + (n0 / 2), k++)
		{

			for (ptr = aP, ptr1 = aP1; ptr <= end; ptr++, ptr1++)
			{
				*ptr = *ptr1;

			}
		}


		for (int l = 0; l < n0 / 2; l++)
		{
			for (int r = 0; r < n0 / 2; r++)
			{
				cout << arr1[l][r] << " ";
				if (r == (n0 / 2 - 1))
					cout << endl;

			}
		}

		cout << "\n" << "\n" << "\n" << "\n";


		for (int l = 0; l < n0 / 2; l++)
		{
			for (int r = 0; r < n0 / 2; r++)
			{
				cout << arr2[l][r] << " ";
				if (r == (n0 / 2 - 1))
					cout << endl;

			}
		}

		cout << "\n" << "\n" << "\n" << "\n";


		for (int l = 0; l < n0 / 2; l++)
		{
			for (int r = 0; r < n0 / 2; r++)
			{
				cout << arr3[l][r] << " ";
				if (r == (n0 / 2 - 1))
					cout << endl;

			}
		}

		cout << "\n" << "\n" << "\n" << "\n";


		for (int l = 0; l < n0 / 2; l++)
		{
			for (int r = 0; r < n0 / 2; r++)
			{
				cout << arr4[l][r] << " ";
				if (r == (n0 / 2 - 1))
					cout << endl;

			}
		}

		cout << "\n" << "\n" << "\n" << "\n";

		cout << "Вид массива после перестановки" << endl;

		for (int l = 0; l < n0; l++)
		{
			for (int r = 0; r < m0; r++)
			{
				cout << arr[l][r] << " ";
				if (r == (n0 - 1))
					cout << endl;
			}
		}


	}

	void Sort3(int(&arr)[10][10])
	{
#include <iostream>
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;

clear();
	
			srand(time(NULL));
			setlocale(LC_ALL, "ru");
			const int M = 10;
			const int N = 5;
			int arr1[N][N];
			int arr2[N][N];
			int arr3[N][N];
			int arr4[N][N];
			int width = 3;
			int k;
			int* first = nullptr;
			int* ptr = nullptr;
			int* ptr1 = nullptr;
			int* aP = nullptr;
			int* aP1 = nullptr;
			int n0 = sizeof(arr) / sizeof(*arr);
			int m0 = sizeof(*arr) / sizeof(**arr);
			int* end = *arr + m0 * n0 - 1;
			int* end1 = nullptr;
			int iter;
			int n1, m1;
			bool swapped = true;
			int* start = *arr;


			for (ptr = *arr; ptr <= end; ptr++)
			{
				*ptr = GetRand(1, 100);
			}

			cout << "Исходный вид массива" << endl;

			for (int l = 0; l < n0; l++)
			{
				for (int r = 0; r < m0; r++)
				{
					cout << arr[l][r] << " ";
					if (r == (n0 - 1))
						cout << endl;
				}
			}

			cout << "\n" << "\n" << "\n" << "\n";






			while (swapped) {
				swapped = false;

				// Проход слева направо
				for (int* i = *arr; i < end; ++i)
				{
					if (*i > *(i + 1))
					{
						swap(*i, *(i + 1));
						swapped = true;
					}
				}

				if (!swapped) {
					break;
				}

				swapped = false;
				--end;

				// Проход справа налево
				for (int* i = end; i >= start; --i)
				{
					if (*i > *(i + 1))
					{
						swap(*i, *(i + 1));
						swapped = true;
					}
				}

				++start;
			}


			cout << "\n" << "\n" << "\n" << "\n";

			cout << "Вид массива после сортировки" << endl;

			for (int l = 0; l < n0; l++)
			{
				for (int r = 0; r < m0; r++)
				{
					cout << arr[l][r] << " ";
					if (r == (n0 - 1))
						cout << endl;
				}
			}

		}

void Arithmetic(int(&arr)[10][10])
{
		srand(time(NULL));
		setlocale(LC_ALL, "ru");
		const int M = 10;
		const int N = 10;
		int k;
		int* first = nullptr;
		int* ptr = nullptr;
		int* aP = nullptr;
		int n0 = sizeof(arr) / sizeof(*arr);
		int m0 = sizeof(*arr) / sizeof(**arr);
		int* end = *arr + m0 * n0 - 1;
		int iter;
		int n1, m1;

		clear();

		for (ptr = *arr; ptr <= end; ptr++)
		{
			*ptr = GetRand(1, 100);
		}

		cout << "Исходный вид массива: " << endl;

		for (int l = 0; l < n0; l++)
		{
			for (int r = 0; r < m0; r++)
			{
				cout << arr[l][r] << " ";
				if (r == (n0 - 1))
					cout << endl;
			}
		}

		cout << "\n" << "\n";

		cout << "Введите произвольное целое число: ";
		cin >> k;


		for (ptr = *arr; ptr <= end; ptr++)
		{
			*ptr = *ptr + k;

		}




		cout << "\n" << "\n";

		cout << "Вид массива после увеличения на заданное число: " << endl;

		for (int l = 0; l < n0; l++)
		{
			for (int r = 0; r < m0; r++)
			{
				cout << arr[l][r] << " ";
				if (r == (n0 - 1))
					cout << endl;
			}
		}

		cout << "\n" << "\n";


		for (ptr = *arr; ptr <= end; ptr++)
		{
			*ptr = *ptr - 2 * k;

		}

		cout << "Вид массива после уменьшения на заданное число: " << endl;

		for (int l = 0; l < n0; l++)
		{
			for (int r = 0; r < m0; r++)
			{
				cout << arr[l][r] << " ";
				if (r == (n0 - 1))
					cout << endl;
			}
		}

		cout << "\n" << "\n";

		for (ptr = *arr; ptr <= end; ptr++)
		{
			*ptr = (*ptr + k) * k;

		}

		cout << "Вид массива после умножения на заданное число: " << endl;

		for (int l = 0; l < n0; l++)
		{
			for (int r = 0; r < m0; r++)
			{
				cout << arr[l][r] << " ";
				if (r == (n0 - 1))
					cout << endl;
			}
		}

		cout << "\n" << "\n";

		for (ptr = *arr; ptr <= end; ptr++)
		{
			*ptr = *ptr / k / k;

		}

		cout << "Вид массива после деления на заданное число: " << endl;

		for (int l = 0; l < n0; l++)
		{
			for (int r = 0; r < m0; r++)
			{
				cout << arr[l][r] << " ";
				if (r == (n0 - 1))
					cout << endl;
			}
		}

}

		
		

