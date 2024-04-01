#include"sort.h"

/*
	�˵�����ʵ��
*/

//���˵�
int mainMenu() {
	cout << "+-----------------------------------+" << endl;
	cout << "|            ����ϵͳ               |" << endl;
	cout << "|                                   |" << endl;
	cout << "|          1.������������           |" << endl;
	cout << "|                                   |" << endl;
	cout << "|          2.��ȡ�ļ���������       |" << endl;
	cout << "|                                   |" << endl;
	cout << "|          3.������ʱ(��������)     |" << endl;
	cout << "|                                   |" << endl;
	cout << "|          4.������ʱ(����С����)   |" << endl;
	cout << "|                                   |" << endl;
	cout << "|          0.�˳�                   |" << endl;
	cout << "+-----------------------------------+" << endl;

	int op;
	cin >> op;

	// ��������Ƿ�ɹ�
	while (cin.fail()) {
		cout << "������Ч����������������ѡ�" << endl;
		cin.clear(); // ��������־
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Ի������е���Ч�ַ�
		cin >> op;
	}

	return op;
}


//�Ӳ˵�3
void sonMenu3(int arr[],int length) {

	cout << "+----------------------------------+" << endl;
	cout << "|          ����ϵͳ                |" << endl;
	cout << "|         1.��������               |" << endl;
	cout << "|         2.�鲢����               |" << endl;
	cout << "|         3.���ţ��ݹ飩           |" << endl;
	cout << "|         4.��������               |" << endl;
	cout << "|         5.��������               |" << endl;
	cout << "|         6.ð�������Ż���       |" << endl;
	cout << "|         7.���ţ��ǵݹ飩         |" << endl;
	cout << "|         8.���ţ��Ż���           |" << endl;
	cout << "|         0.�����ϼ��˵�           |" << endl;
	cout << "+----------------------------------+" << endl;

	int op;
	cin >> op;

	// ��������Ƿ�ɹ�
	while (cin.fail()) {
		cout << "������Ч����������������ѡ�" << endl;
		cin.clear(); // ��������־
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Ի������е���Ч�ַ�
		cin >> op;
	}

	do {
		switch (op)
		{
		case 1:
			Insert_sort(arr, length);
			printarr(arr, length);
			break;
		case 2:
			Merge_sort(arr, length);
			printarr(arr, length);
			break;
		case 3:
			Quick_sort(arr, 0, length - 1);
			printarr(arr, length);
			break;
		case 4:
			Count_sort(arr, length);
			printarr(arr, length);
			break;
		case 5:
			RadixCount_sort(arr, length);
			printarr(arr, length);
			break;
		case 6:
			Bubble_sort(arr, length);
			printarr(arr, length);
			break;
		case 7:
			Quick_sort2(arr, 0, length-1);
			printarr(arr, length);
			break;
		case 8:
			Quick_sortPro(arr, 0, length-1);
			printarr(arr, length);
			break;
		case 0:
			cout << "�������˵�" << endl;
			return;
			break;
		default:
			cout << "�����������������" << endl;
			break;
		}

		cout << "��ѡ��:" << endl;
		cin >> op;

	} while (op);
}


//�Ӳ˵�1
void sonMenu1() {
	while (true) {
		int size;
		int inputCount; // ʵ�������Ԫ������
		int* arr;

		// ���������ض�̬����������Լ������С��ʵ��Ԫ������
		arr = createArray(size, inputCount);

		cout << "+----------------------------------+" << endl;
		cout << "|           �Ӳ˵�1                |" << endl;
		cout << "|         1.������������           |" << endl;
		cout << "|         2.ִ����һ������         |" << endl;
		cout << "|         0.�������˵�             |" << endl;
		cout << "+----------------------------------+" << endl;

		int op;
		cin >> op;

		// ��������Ƿ�ɹ�
		while (cin.fail()) {
			cout << "������Ч����������������ѡ�" << endl;
			cin.clear(); // ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Ի������е���Ч�ַ�
			cin >> op;
		}

		switch (op) {
		case 1:
			// ������������
			break;
		case 2:
			// ִ����������
			cout << "ִ����һ������" << endl;
			sonMenu3(arr,inputCount);
			break;
		case 0:
			cout << "�������˵�" << endl;
			return; // ֱ�ӷ��أ�������ǰ�������������˵�
		default:
			cout << "�����������������" << endl;
			break;
		}
	}
}


//�Ӳ˵�2
void sonMenu2() {
	while (true) {
		int* arr;
		int size;
		cout << "+----------------------------------+" << endl;
		cout << "|           �Ӳ˵�2                |" << endl;
		cout << "|         1.��ȡ�ļ�����           |" << endl;
		cout << "|         2.�����������           |" << endl;
		cout << "|         0.�������˵�             |" << endl;
		cout << "+----------------------------------+" << endl;

		int op;
		cin >> op;

		// ��������Ƿ�ɹ�
		while (cin.fail()) {
			cout << "������Ч����������������ѡ�" << endl;
			cin.clear(); // ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Ի������е���Ч�ַ�
			cin >> op;
		}

		switch (op) {
		case 1:
			//��ȡ�ļ�����
			arr = startRead();
			size = calculateArrayLength(arr);
			cout << "δ����ǰ" << endl;
			printarr(arr, size);
			cout << endl;
			sonMenu3(arr, size);
			break;
		case 2:
			//�����������
			startWrite();
			break;
		case 0:
			cout << "�������˵�" << endl;
			return; // ֱ�ӷ��أ�������ǰ�������������˵�
		default:
			cout << "�����������������" << endl;
			break;
		}

	}
}





