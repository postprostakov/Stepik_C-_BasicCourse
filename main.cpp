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

		cout << "1.������� ������������ ������ N1 " << endl;
		cout << "2.������� ������������ ������ N2" << endl;
		cout << "3.������� ������������ ������ N3" << endl;
		cout << "4.������� ������������ ������ N4" << endl;
		cout << "5.����� �� ���������." << endl;
		cout << "�������� ����� ����. � ������� ����� ���������� ������ = ";
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
	
