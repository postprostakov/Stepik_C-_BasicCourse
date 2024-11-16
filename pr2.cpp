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

		cout << "1.������� ������������� ������ ����������� N=100. �������� ������� ��������� ��������� �������� � ��������� �� -99 �� 99" << endl << endl;
		cout << "2.������������� �������� � ������ 1 ������ ����������� �� �������� � ��������" << endl << "���������� �����, ����������� �� ����������" << endl << endl;
		cout << "3.����� ������������ � ����������� �������� �������"<<endl<<"���������� ����� ������ ���� ��������� � ��������������� � ����������������� �������" << endl<<"������� ������� �������� ������������� � ������������ �������� � ��������������� � ����������������� �������"<<endl<<"������� ������� ���� ���������, ������� ����� �� �������� � �� ����������. ���������� ����� ������" << endl;
		cout << "4.������� ���������� ��������� � ��������������� �������, ������� ������ ����� a, ������� ���������������� �������������" << endl << endl;
		cout << "5.������� ���������� ��������� � ��������������� �������, ������� ������ ����� b, ������� ���������������� �������������" << endl << endl;
		cout << "6.������� ���������� � ���, ���� �� ��������� ������������� ����� � ��������������� �������. ����� ��������� �������� ��������� ��������� ������" << endl << endl;
		cout << "7.�������� ������� �������� �������, ������� ������� ������ ������������" << endl << endl;
		cout << "8.����� � ������� ����" << endl << endl;
		cout << "�������� ����� ����. � ������� ����� ���������� ������ = ";
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
			cout << "������� ����� a" << endl;
			cin >> a;
			cout << "����� a: "<<a << endl;
			Mina(massSort, N, a);
			cout << "\n" << "\n";
			break;
		}
		case 5:
		{
			int b;
			cout << "\n" << "\n";
			cout << "������� ����� b" << endl;
			cin >> b;
			cout << "����� b: " << b << endl;
			Maxb(massSort, N, b);
			cout << "\n" << "\n";
			break;
		}
		case 6:
		{
			int c;
			cout << "\n" << "\n";
			cout << "������� ����� c" << endl;
			cin >> c;
			cout << "����� c: " << c << endl;
			Search(massSort, c, N);
			cout << "\n" << "\n";
			break;
		}
		
		case 7:
		{
			int n1, n2;
			cout << "\n" << "\n";
			cout << "������� ������ ������� ��������" << endl;
			cin >> n1;
			cout << "������� ������ ������� ��������" << endl;
			cin >> n2;
			cout << "����� n1: " << n1 << endl;
			cout << "����� n2: " << n1 << endl;
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

    cout << "����������������� ������: " << endl;
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
	cout << "�����, ����������� �� ���������� �������: " << sec.count() << " ���." << endl;
	cout << "��������������� ������: " << endl;
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
	cout << "�����, ����������� �� ����� �������������/������������ �������� � ����������������� �������: " << sec1.count() << " ���." << endl;
	cout << "����������� �������� =" << min << endl;
	cout << "������������ �������� = " << max << endl;
	average = 0.5 * (max + min);
	cout << "������� �������� ��������� � �������: " << average << endl;

	cout << "\n\n";
	cout << "������ ��������� �������, ������ �������� ��������: " << endl;
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
	cout << "���������� ��������� � ����������������� �������, ������ ��������: " << k << endl;
	cout << "�����, ����������� �� ����� ���������, ������ ��������: " << sec2.count() << " ���." << endl;
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
	cout << "�����, ����������� �� ����� �������������/������������ �������� � ��������������� �������: " << sec3.count() << " ���." << endl;
	cout << "����������� �������� =" << min << endl;
	cout << "������������ �������� = " << max << endl;
	average = 0.5 * (max + min);
	cout << "������� �������� ��������� � �������: " << average << endl;

	cout << "\n\n";
	cout << "������ ��������� �������, ������ �������� ��������: " << endl;
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
	cout << "�����, ����������� �� ����� ���������, ������ ��������: " << sec4.count() << " ���." << endl;
}

void Mina(int* massSort, int N, int a)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (massSort[i] < a)
			k = k + 1;
	}
	cout << "���������� ���������, �������� ������� ������ �: " << k << endl;
}

void Maxb(int* massSort, int N, int b)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (massSort[i] > b)
			k = k + 1;
	}
	cout << "���������� ���������, �������� ������� ������ b: " << k << endl;

}


void Search(int* massSort, int c, int N)
{
	int result;
	result = binarySearch(massSort, c, 0, N - 1);
	system_clock::time_point start5 = system_clock::now();

	if (result == -1)
	{
		cout << "������� �� ������" << endl;
	}
	else
	{
		cout << "������� ��������� � ������� " << result << endl;
	}
	system_clock::time_point end5 = system_clock::now();
	duration<double> sec5 = end5 - start5;
	cout << "�����, ����������� �� ����� �������� ��� �������� ������: " << sec5.count() << " ���." << endl;


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
	cout << "�����, ����������� �� ��������� ��������� ��������� �������: " << sec6.count() << " ���." << endl << endl;
	cout << "������ ����� ������������ ���������: ";
	for (int i = 0; i < N; i++)
	{
		cout << mass[i] << " ";
	}
}

