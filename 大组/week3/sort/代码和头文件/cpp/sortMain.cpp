#include"sort.h"


int main() {
	while (true)
	{
		switch (mainMenu()) {
		case 1:
			sonMenu1();
			break;
		case 2:
			sonMenu2();
		case 3:
			startTest1();
			break;
		case 4:
			startTest2();
			break;
		case 0:
			cout << "�˳�����" << endl;
			return 0;
			break;
		default:
			cout << "������������������" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}