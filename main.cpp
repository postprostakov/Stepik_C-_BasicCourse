#include <iostream>;
using namespace std;
int pr1();
int pr2();
int pr3();
int pr4();

int main()
{
	setlocale(LC_ALL, "Rus");
	int i = 0;
	int choice;
	for (;;)
	{

		cout << "1.Выбрать практическую работу N1 " << endl;
		cout << "2.Выбрать практическую работу N2" << endl;
		cout << "3.Выбрать практическую работу N3" << endl;
		cout << "4.Выбрать практическую работу N4" << endl;
		cout << "5.Выход из программы." << endl;
		cout << "Выберите пункт меню. И введите номер выбранного пункта = ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\n";
			pr1();
			break;
		}
		
		case 2:
		{
			cout << "\n";
			pr2();
			break;
		}
		case 3:
		{
			cout << "\n";
			pr3();
			break;
		}
		case 4:
		{
			cout << "\n";
			pr4();
			break;
		}

		default:
			return 0;
			break;
		}
	}
}
	
