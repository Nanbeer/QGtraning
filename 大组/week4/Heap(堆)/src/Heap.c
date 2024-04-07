#include"heap.h"

//��ʼ��
void HeapInit(HP* php)
{
	assert(php != NULL);//����Ƿ����
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

//����
void HeapDestory(HP* php)
{
	assert(php != NULL);

	free(php->a);
	php->capacity = 0;
	php->size = 0;
}

//��ӡ
void HeapPrint(HP* php)
{
	assert(php != NULL);
	for (int i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

//����
void Swap(int* child, int* parent)
{
	int temp = *parent;
	*parent = *child;
	*child = temp;
}

//���ϵ���
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;//���ڵ�

	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);  //�������׺ͺ�����������Ӧ��ֵ
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//���µ���
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)       //���������nΪԪ�صĸ�������child���Ϊn-1 
	{
		if ((child + 1 < n) && (a[child] > a[child + 1]))  //������������ӱ��Һ���
		{
			++child;
		}

		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//���в�������
void HeapPush(HP* php, int child)
{
	assert(php != NULL);
	if (php->size == php->capacity)  //�����������������
	{
		//����
		int newCapacity = ((php->capacity == 0) ? 4 : sizeof(php->a) * 2);
		HPDataType* ptr = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newCapacity);
		if (ptr == NULL)
		{
			perror("�����ڴ�ʧ��");
			exit(-1);
		}
		php->a = ptr;
		php->capacity = newCapacity;
	}

	php->a[php->size] = child;   //��������
	php->size++;
	AdjustUp(php->a, php->size - 1);     //���ϵ����Ƕ����е�����ͨ�����������ҵ���Ӧ��ֵ���е���������ֻ��Ҫ����php->a�Լ�β�����ݵ�����ֵ
}

//pop�Ѷ�����
void HeapPop(HP* php)
{
	assert(php != NULL);

	if (php->size == 0) {
		printf("����Ϊ�գ�����ɾ��\n");
		return;
	}

	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	--php->size;

	AdjustDown(php->a, php->size, 0);

	printf("ɾ���ɹ�\n");
}

//�ж��Ƿ�Ϊ��
bool HpEmpty(HP* pHp)
{
	assert(pHp);

	return pHp->size == 0;
}

// ȡ�Ѷ�������
void HpTop(HP* pHp)
{
	assert(pHp);

	printf("�Ѷ�������: %d\n",pHp->a[0]);
}

// �ѵ����ݸ���
void HpSize(HP* pHp)
{
	assert(pHp);

	 printf("�������ݸ�����: %d\n",pHp->size);
}





