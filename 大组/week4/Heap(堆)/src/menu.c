#include"Heap.h"

//判断是否输入正确
int getValidInput() {
    double input;
    int validInput;

    // 检查输入是否成功
    while (scanf("%lf%*c", &input) != 1 || input != (int)input) {
        // 先判断输入是否成功，如果输入的不是数字或者无法用int类型表示，则重新输入
        printf("输入无效，请重新输入整数选项：\n");
        // 清除输入缓冲区
        while (getchar() != '\n');
    }

    validInput = (int)input;
    return validInput;
}

void menu(HP* php) {
    int choice;
    int value;

    while (1) {
        printf("+----------------------------------+\n");
        printf("+----       堆                -----+\n");
        printf("+----     1.遍历              -----+\n");
        printf("+----     2.删除堆顶元素      -----+\n");
        printf("+----     3.插入              -----+\n");
        printf("+----     4.查看堆顶的数据    -----+\n");
        printf("+----     5.查看堆中数据个数  -----+\n");
        printf("+----     0.退出              -----+\n");
        printf("+----------------------------------+\n");

        printf("请选择: ");
        choice = getValidInput();

        switch (choice) {
        case 1:
            HeapPrint(php);
            system("pause");
            system("cls");
            break;
        case 2:
            HeapPop(php); 
            system("pause");
            system("cls");
            break;
        case 3:
            printf("请输入数字 ");
            value = getValidInput();
            HeapPush(php, value);
            printf("插入成功\n");
            system("pause");
            system("cls");
            break;
        case 4:
            HpTop(php);
            system("pause");
            system("cls");
            break;
        case 5:
            HpSize(php);
            system("pause");
            system("cls");
            break;
        case 0:
            printf("退出程序\n");
            return;
            break;
        default:
            printf("输入有误，请重新输入\n");
            break;
        }
    }
}