#include <iostream>;
#include <stdlib.h>;
#include <time.h>;
#include <chrono>;
using namespace std;
using namespace chrono;
void Mass(int *mass, int N);
void Sort(int* mass, int* massSort, int N);
void minMaxTime(int* mass, int N);
void minMaxTimeSort(int* mass, int N);
void Mina(int* massSort, int N, int a);
void Maxb(int* massSort, int N, int b);
void Search(int* massSort, int c, int N);
int binarySearch(int* arr, int value, int start, int end);
void Swap(int* mass, int n1, int n2, int N);


int pr2()
{
	setlocale(LC_ALL, "Rus");
	const int N = 100;
	int mass[N];
	int massSort[N];
	int choice;
	for (;;)
	{

		cout << "1.Создать целочисленный массив размерности N=100. Элементы массива принимают случайные значения в диапазоне от -99 до 99" << endl << endl;
		cout << "2.Отсортировать заданный в пункте 1 массив сортировкой от меньшего к большему" << endl << "Определить время, затраченное на сортировку" << endl << endl;
		cout << "3.Найти максимальный и минимальный элементы массива"<<endl<<"Определить время поиска этих элементов в отсортированном и неотсортированном массиве" << endl<<"Вывести среднее значение максимального и минимального значения в отсортированном и неотсортированном массиве"<<endl<<"Вывести индексы всех элементов, которые равны их значению и их количество. Подсчитать время поиска" << endl;
		cout << "4.Вывести количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем" << endl << endl;
		cout << "5.Вывести количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем" << endl << endl;
		cout << "6.Вывести информацию о том, есть ли введенное пользователем число в отсортированном массиве. Поиск выполнить согласно алгоритму бинарного поиска" << endl << endl;
		cout << "7.Поменять местами элементы массива, индексы которых вводит пользователь" << endl << endl;
		cout << "8.Выход в главное меню" << endl << endl;
		cout << "Выберите пункт меню. И введите номер выбранного пункта = ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\n" << "\n";
			Mass(mass, N);
			cout << "\n" << "\n";
			break;
		}
		case 2:
		{
			cout << "\n" << "\n";
			Sort(mass, massSort, N);
			cout << "\n" << "\n";
			break;
		}
		case 3:
		{
			cout << "\n" << "\n";
			minMaxTime(mass, N);
			cout << "\n" << "\n";
			minMaxTimeSort(massSort, N);
			cout << "\n" << "\n";

			break;
		}
		case 4:
		{
			int a;
			cout << "\n" << "\n";
			cout << "Введите число a" << endl;
			cin >> a;
			cout << "Число a: "<<a << endl;
			Mina(massSort, N, a);
			cout << "\n" << "\n";
			break;
		}
		case 5:
		{
			int b;
			cout << "\n" << "\n";
			cout << "Введите число b" << endl;
			cin >> b;
			cout << "Число b: " << b << endl;
			Maxb(massSort, N, b);
			cout << "\n" << "\n";
			break;
		}
		case 6:
		{
			int c;
			cout << "\n" << "\n";
			cout << "Введите число c" << endl;
			cin >> c;
			cout << "Число c: " << c << endl;
			Search(massSort, c, N);
			cout << "\n" << "\n";
			break;
		}
		
		case 7:
		{
			int n1, n2;
			cout << "\n" << "\n";
			cout << "Введите индекс первого элемента" << endl;
			cin >> n1;
			cout << "Введите индекс второго элемента" << endl;
			cin >> n2;
			cout << "Число n1: " << n1 << endl;
			cout << "Число n2: " << n1 << endl;
			Swap(massSort, n1, n2, N);
			cout << "\n" << "\n";
			break;
		}
		
		case 8:
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

int GetRand(int min, int max)
{

	int num = min + rand() % (max - min + 1);
	return num;

}


void Mass(int *mass, int N)
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    int min;
    int max;
    int average;
    int k = 0;
    int a, b;
    int value, result;
    int n1, n2;

    cout << "Неотсортированный массив: " << endl;
    for (int i = 0; i < N; i++)
    {

        mass[i] = GetRand(-99, 99);
		cout << mass[i] << " ";
	 }
}

void Sort(int* mass, int*massSort, int N)
{
	system_clock::time_point start = system_clock::now();
	for (int i = 0; i < N; i++)
	{
		massSort[i] = mass[i];
	}
	int temp;
	temp = massSort[0];
	temp = 0;
	for (int i = 0; i < N; i++)
	{
		for (int k = i + 1; k < N; k++)
		{
			if (massSort[k] < massSort[i])
			{
				temp = massSort[k];
				massSort[k] = massSort[i];
				massSort[i] = temp;
			}
		}


	}
	cout << "\n\n";

	system_clock::time_point end = system_clock::now();
	duration<double> sec = end - start;
	cout << "Время, затраченное на сортировку массива: " << sec.count() << " сек." << endl;
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < N; i++)
	{

		cout << massSort[i] << " ";
	}
}


void minMaxTime(int* mass, int N)
{
	system_clock::time_point start1 = system_clock::now();
	int min;
	int max;
	int k=0;
	int average;
	min = mass[0];
	max = mass[0];
	for (int i = 1; i < N; i++)
	{
		if (mass[i] < min)
			min = mass[i];
		if (mass[i] > max)
			max = mass[i];
	}
	cout << "\n\n";
	system_clock::time_point end1 = system_clock::now();
	duration<double> sec1 = end1 - start1;
	cout << "Время, затраченное на поиск максимального/минимального элемента в неотсортированном массиве: " << sec1.count() << " сек." << endl;
	cout << "Минимальное значение =" << min << endl;
	cout << "Максимальное значение = " << max << endl;
	average = 0.5 * (max + min);
	cout << "Среднее значение элементов в массиве: " << average << endl;

	cout << "\n\n";
	cout << "Номера элементов массива, равные среднему значению: " << endl;
	system_clock::time_point start2 = system_clock::now();
	for (int i = 0; i < N; i++)
	{
		if (mass[i] == average)
		{
			cout << i << endl;
			k = k + 1;
		}
	}
	system_clock::time_point end2 = system_clock::now();
	duration<double> sec2 = end2 - start2;
	cout << "Количество элементов в неотсортированном массиве, равное среднему: " << k << endl;
	cout << "Время, затраченное на поиск элементов, равных среднему: " << sec2.count() << " сек." << endl;
}

void minMaxTimeSort(int* mass, int N)

{
	int min;
	int max;
	int average;
	int k = 0;

	system_clock::time_point start3 = system_clock::now();
	min = mass[0];
	max = mass[0];
	for (int i = 1; i < N; i++)
	{
		if (mass[i] < min)
			min = mass[i];
		if (mass[i] > max)
			max = mass[i];

	}
	cout << "\n\n";
	system_clock::time_point end3 = system_clock::now();
	duration<double> sec3 = end3 - start3;
	cout << "Время, затраченное на поиск максимального/минимального элемента в отсортированном массиве: " << sec3.count() << " сек." << endl;
	cout << "Минимальное значение =" << min << endl;
	cout << "Максимальное значение = " << max << endl;
	average = 0.5 * (max + min);
	cout << "Среднее значение элементов в массиве: " << average << endl;

	cout << "\n\n";
	cout << "Номера элементов массива, равные среднему значению: " << endl;
	system_clock::time_point start4 = system_clock::now();
	for (int i = 0; i < N; i++)
	{
		if (mass[i] == average)
		{
			cout << i << endl;

		}
	}
	system_clock::time_point end4 = system_clock::now();
	duration<double> sec4 = end4 - start4;
	cout << "Время, затраченное на поиск элементов, равных среднему: " << sec4.count() << " сек." << endl;
}

void Mina(int* massSort, int N, int a)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (massSort[i] < a)
			k = k + 1;
	}
	cout << "Количество элементов, значение которых меньше а: " << k << endl;
}

void Maxb(int* massSort, int N, int b)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (massSort[i] > b)
			k = k + 1;
	}
	cout << "Количество элементов, значение которых больше b: " << k << endl;

}


void Search(int* massSort, int c, int N)
{
	int result;
	result = binarySearch(massSort, c, 0, N - 1);
	system_clock::time_point start5 = system_clock::now();

	if (result == -1)
	{
		cout << "Элемент не найден" << endl;
	}
	else
	{
		cout << "Элемент находится в позиции " << result << endl;
	}
	system_clock::time_point end5 = system_clock::now();
	duration<double> sec5 = end5 - start5;
	cout << "Время, затраченное на поиск элемента при бинарном поиске: " << sec5.count() << " сек." << endl;


}



int binarySearch(int* arr, int value, int start, int end)
{

	if (end >= start) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == value) {
			return mid;
		}

		if (arr[mid] > value) {
			return binarySearch(arr, value, start, mid - 1);
		}

		return binarySearch(arr, value, mid + 1, end);
	}

	return -1;

}

void Swap(int* mass, int n1, int n2, int N)
{
	system_clock::time_point start6 = system_clock::now();
	int temp;
	temp = mass[n2];
	mass[n2] = mass[n1];
	mass[n1] = temp;
	system_clock::time_point end6 = system_clock::now();
	duration<double> sec6 = end6 - start6;
	cout << "\n\n";
	cout << "Время, затраченное на изменения положения элементов массива: " << sec6.count() << " сек." << endl << endl;
	cout << "Массив после перестановки элементов: ";
	for (int i = 0; i < N; i++)
	{
		cout << mass[i] << " ";
	}
}

