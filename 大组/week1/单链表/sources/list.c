#include"list.h"

//�˵�
void showMenu() {
	printf("+---------------------------+\n");
	printf("|                           |\n");
	printf("|    1.¼����������         |\n");
	printf("|    2.չʾ¼������         |\n");
	printf("|    3.��������ż����       |\n");
	printf("|    4.�ҵ��������е�       |\n");
	printf("|    5.�ж������Ƿ�ɻ�     |\n");
	printf("|    6.��ת����             |\n");
	printf("|    0.�˳�                 |\n");
	printf("|                           |\n");
	printf("+---------------------------+\n");
}

//��ӡ
void printList(List* head) {
	List* move = head->next;
	printf("¼�������Ϊ��");
	while (move!=NULL) {
		printf("%d ",move->number);
		move = move->next;
	}
	printf("\n");
}

//��������
void inputList(List* head) {
	List* fresh = malloc(sizeof(List));
	fresh->next = NULL;
	printf("���������֣�");
	scanf("%d", &fresh->number);

	List* move = head;
	while (move->next != NULL) {
		move = move->next;
	}
	move->next = fresh;
	system("pause");
	system("cls");
}

//�������м�ڵ�
void findMidpoint(List* head) {
	List* slow, * fast;
	slow = head;
	fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("������м�ڵ��ǣ�%d\n", slow->number);
}

//�ж������Ƿ�ɻ�
bool isCircle(List* head) {
	List* slow = head, * fast = head;
	while (fast->next != NULL && slow->next != NULL)
	{
		if ((fast = fast->next->next) == NULL)
		{
			return false;
		}
		slow = slow->next;
		if (fast == slow) {
			return true;
		}
	}
	return false;
}

//��ת�����ǵݹ飩
void reverseList(List* head) {
	List* p, * q;
	p = head->next;
	head->next = NULL;
	while (p) {
		q = p;
		p = p->next;
		q->next = head->next;
		head->next = q;
	}
}

//��ż����
void ParitySwap(List* head) {
	List* p = (List*)malloc(sizeof(List));//�����ڵ�
	p->next = head->next;
	head->next = head->next->next;

	while (p->next != NULL && p->next->next != NULL) {
		//node1Ϊ�����ڵ� node2Ϊż���ڵ� p����ǽڵ�
		List* node1 = p->next;
		List* node2 = p->next->next;
		//����
		p->next = node2;
		node1->next = node2->next;
		node2->next = node1;
		//�ѱ�ǽڵ��ƶ�������
		p = node1;
	}
	printf("��ż�����ɹ���\n");
}

int main() {
	List* head = malloc(sizeof(List));
	head->next = NULL;

	int choice = 0;
	while (true) {
		showMenu();
		printf("��ѡ��Ҫʵ�ֵĹ��ܣ�");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			inputList(head);
			break;
		case 2:
			printList(head);
			break;
		case 3:
			ParitySwap(head);
			printList(head);
			system("pause");
			system("cls");
			break;
		case 4:
			findMidpoint(head);
			system("pause");
			system("cls");
			break;
		case 5:
			if (isCircle==true) {
				printf("true\n");
			}
			else {
				printf("false\n");
			}
			system("pause");
			system("cls");
			break;
		case 6:
			reverseList(head);
			printList(head);
			system("pause");
			system("cls");
			break;
		case 0:
			printf("����\n");
			return 0;
		default:
			printf("������������������");
			system("pause");
			system("cls");
			break;
		
		}
	}
}