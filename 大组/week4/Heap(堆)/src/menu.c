#include"Heap.h"

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

void menu(HP* php) {
    int choice;
    int value;

    while (1) {
        printf("+----------------------------------+\n");
        printf("+----       ��                -----+\n");
        printf("+----     1.����              -----+\n");
        printf("+----     2.ɾ���Ѷ�Ԫ��      -----+\n");
        printf("+----     3.����              -----+\n");
        printf("+----     4.�鿴�Ѷ�������    -----+\n");
        printf("+----     5.�鿴�������ݸ���  -----+\n");
        printf("+----     0.�˳�              -----+\n");
        printf("+----------------------------------+\n");

        printf("��ѡ��: ");
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
            printf("���������� ");
            value = getValidInput();
            HeapPush(php, value);
            printf("����ɹ�\n");
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
            printf("�˳�����\n");
            return;
            break;
        default:
            printf("������������������\n");
            break;
        }
    }
}