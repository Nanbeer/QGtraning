#include"sort.h"

/*
	菜单函数实现
*/

//主菜单
int mainMenu() {
	cout << "+-----------------------------------+" << endl;
	cout << "|            排序系统               |" << endl;
	cout << "|                                   |" << endl;
	cout << "|          1.输入数据排序           |" << endl;
	cout << "|                                   |" << endl;
	cout << "|          2.读取文件数据排序       |" << endl;
	cout << "|                                   |" << endl;
	cout << "|          3.测试用时(大数据量)     |" << endl;
	cout << "|                                   |" << endl;
	cout << "|          4.测试用时(大量小数据)   |" << endl;
	cout << "|                                   |" << endl;
	cout << "|          0.退出                   |" << endl;
	cout << "+-----------------------------------+" << endl;

	int op;
	cin >> op;

	// 检查输入是否成功
	while (cin.fail()) {
		cout << "输入无效，请重新输入整数选项：" << endl;
		cin.clear(); // 清除错误标志
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略缓冲区中的无效字符
		cin >> op;
	}

	return op;
}


//子菜单3
void sonMenu3(int arr[],int length) {

	cout << "+----------------------------------+" << endl;
	cout << "|          排序系统                |" << endl;
	cout << "|         1.插入排序               |" << endl;
	cout << "|         2.归并排序               |" << endl;
	cout << "|         3.快排（递归）           |" << endl;
	cout << "|         4.计数排序               |" << endl;
	cout << "|         5.基数排序               |" << endl;
	cout << "|         6.冒泡排序（优化）       |" << endl;
	cout << "|         7.快排（非递归）         |" << endl;
	cout << "|         8.快排（优化）           |" << endl;
	cout << "|         0.返回上级菜单           |" << endl;
	cout << "+----------------------------------+" << endl;

	int op;
	cin >> op;

	// 检查输入是否成功
	while (cin.fail()) {
		cout << "输入无效，请重新输入整数选项：" << endl;
		cin.clear(); // 清除错误标志
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略缓冲区中的无效字符
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
			cout << "返回主菜单" << endl;
			return;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}

		cout << "请选择:" << endl;
		cin >> op;

	} while (op);
}


//子菜单1
void sonMenu1() {
	while (true) {
		int size;
		int inputCount; // 实际输入的元素数量
		int* arr;

		// 创建并返回动态分配的数组以及数组大小和实际元素数量
		arr = createArray(size, inputCount);

		cout << "+----------------------------------+" << endl;
		cout << "|           子菜单1                |" << endl;
		cout << "|         1.继续输入数组           |" << endl;
		cout << "|         2.执行下一步排序         |" << endl;
		cout << "|         0.返回主菜单             |" << endl;
		cout << "+----------------------------------+" << endl;

		int op;
		cin >> op;

		// 检查输入是否成功
		while (cin.fail()) {
			cout << "输入无效，请重新输入整数选项：" << endl;
			cin.clear(); // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略缓冲区中的无效字符
			cin >> op;
		}

		switch (op) {
		case 1:
			// 继续输入数组
			break;
		case 2:
			// 执行其他操作
			cout << "执行下一步操作" << endl;
			sonMenu3(arr,inputCount);
			break;
		case 0:
			cout << "返回主菜单" << endl;
			return; // 直接返回，结束当前函数，返回主菜单
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
}


//子菜单2
void sonMenu2() {
	while (true) {
		int* arr;
		int size;
		cout << "+----------------------------------+" << endl;
		cout << "|           子菜单2                |" << endl;
		cout << "|         1.读取文件数组           |" << endl;
		cout << "|         2.生成随机数组           |" << endl;
		cout << "|         0.返回主菜单             |" << endl;
		cout << "+----------------------------------+" << endl;

		int op;
		cin >> op;

		// 检查输入是否成功
		while (cin.fail()) {
			cout << "输入无效，请重新输入整数选项：" << endl;
			cin.clear(); // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略缓冲区中的无效字符
			cin >> op;
		}

		switch (op) {
		case 1:
			//读取文件数组
			arr = startRead();
			size = calculateArrayLength(arr);
			cout << "未排序前" << endl;
			printarr(arr, size);
			cout << endl;
			sonMenu3(arr, size);
			break;
		case 2:
			//生成随机数组
			startWrite();
			break;
		case 0:
			cout << "返回主菜单" << endl;
			return; // 直接返回，结束当前函数，返回主菜单
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}

	}
}





