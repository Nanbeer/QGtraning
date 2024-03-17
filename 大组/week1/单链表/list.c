#include"list.h"

//菜单
void showMenu() {
	printf("+---------------------------+\n");
	printf("|                           |\n");
	printf("|    1.录入链表数据         |\n");
	printf("|    2.展示录入数组         |\n");
	printf("|    3.单链表奇偶调换       |\n");
	printf("|    4.找到单链表中点       |\n");
	printf("|    5.判断链表是否成环     |\n");
	printf("|    6.反转链表             |\n");
	printf("|    0.退出                 |\n");
	printf("|                           |\n");
	printf("+---------------------------+\n");
}

//打印
void printList(List* head) {
	List* move = head->next;
	printf("录入的数据为：");
	while (move!=NULL) {
		printf("%d ",move->number);
		move = move->next;
	}
	printf("\n");
}

//输入数据
void inputList(List* head) {
	List* fresh = malloc(sizeof(List));
	fresh->next = NULL;
	printf("请输入数字：");
	scanf("%d", &fresh->number);

	List* move = head;
	while (move->next != NULL) {
		move = move->next;
	}
	move->next = fresh;
	system("pause");
	system("cls");
}

//找链表中间节点
void findMidpoint(List* head) {
	List* slow, * fast;
	slow = head;
	fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("链表的中间节点是：%d\n", slow->number);
}

//判断链表是否成环
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

//反转链表（非递归）
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

//奇偶调换
void ParitySwap(List* head) {
	List* p = (List*)malloc(sizeof(List));//辅助节点
	p->next = head->next;
	head->next = head->next->next;

	while (p->next != NULL && p->next->next != NULL) {
		//node1为奇数节点 node2为偶数节点 p做标记节点
		List* node1 = p->next;
		List* node2 = p->next->next;
		//调换
		p->next = node2;
		node1->next = node2->next;
		node2->next = node1;
		//把标记节点移动到后面
		p = node1;
	}
	printf("奇偶调换成功！\n");
}

int main() {
	List* head = malloc(sizeof(List));
	head->next = NULL;

	int choice = 0;
	while (true) {
		showMenu();
		printf("请选择要实现的功能：");
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
			printf("加纳\n");
			return 0;
		default:
			printf("输入有误，请重新输入");
			system("pause");
			system("cls");
			break;
		
		}
	}
}