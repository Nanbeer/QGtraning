#include"AVL.h"

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

void menu(AVLTREE* root) {
    int choice;
    int value;

    while (1) {
        printf("+----------------------------------+\n");
        printf("+----       AVL树             -----+\n");
        printf("+----     1.删除              -----+\n");
        printf("+----     2.插入              -----+\n");
        printf("+----     3.遍历(先序)        -----+\n");
        printf("+----     4.遍历(中序)        -----+\n");
        printf("+----     5.遍历(后序)        -----+\n");
        printf("+----     0.退出              -----+\n");
        printf("+----------------------------------+\n");

        printf("请选择: ");
        choice = getValidInput();

        switch (choice) {
        case 1:
            printf("请输入要删除的数字:");
            value = getValidInput();
            deletePoint(value, root);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("请输入要插入的数字:");
            value = getValidInput();
            insertPoint(value, root);
            system("pause");
            system("cls");
            break;
        case 3:
            showTreeByLeft(root);
            system("pause");
            system("cls");
            break;
        case 4:
            showTreeByMid(root);
            system("pause");
            system("cls");
            break;
        case 5:
            showTreeByRight(root);
            system("pause");
            system("cls");
            break;
        case 0:
            printf("已退出\n");
            return;
            break;
        default:
            printf("输入有误，请重新输入");
            break;
        }
    }
}