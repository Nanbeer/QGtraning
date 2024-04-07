#include"AVL.h"

//�ж��Ƿ�������ȷ
int getValidInput() {
    double input;
    int validInput;

    // ��������Ƿ�ɹ�
    while (scanf("%lf%*c", &input) != 1 || input != (int)input) {
        // ���ж������Ƿ�ɹ����������Ĳ������ֻ����޷���int���ͱ�ʾ������������
        printf("������Ч����������������ѡ�\n");
        // ������뻺����
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
        printf("+----       AVL��             -----+\n");
        printf("+----     1.ɾ��              -----+\n");
        printf("+----     2.����              -----+\n");
        printf("+----     3.����(����)        -----+\n");
        printf("+----     4.����(����)        -----+\n");
        printf("+----     5.����(����)        -----+\n");
        printf("+----     0.�˳�              -----+\n");
        printf("+----------------------------------+\n");

        printf("��ѡ��: ");
        choice = getValidInput();

        switch (choice) {
        case 1:
            printf("������Ҫɾ��������:");
            value = getValidInput();
            deletePoint(value, root);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("������Ҫ���������:");
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
            printf("���˳�\n");
            return;
            break;
        default:
            printf("������������������");
            break;
        }
    }
}