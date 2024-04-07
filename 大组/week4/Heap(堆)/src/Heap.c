#include"heap.h"

//初始化
void HeapInit(HP* php)
{
	assert(php != NULL);//检测是否存在
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

//销毁
void HeapDestory(HP* php)
{
	assert(php != NULL);

	free(php->a);
	php->capacity = 0;
	php->size = 0;
}

//打印
void HeapPrint(HP* php)
{
	assert(php != NULL);
	for (int i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

//交换
void Swap(int* child, int* parent)
{
	int temp = *parent;
	*parent = *child;
	*child = temp;
}

//向上调整
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;//父节点

	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);  //交换父亲和孩子索引所对应的值
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//向下调整
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)       //由于这里的n为元素的个数所以child最大为n-1 
	{
		if ((child + 1 < n) && (a[child] > a[child + 1]))  //如果大于则左孩子变右孩子
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

//堆中插入数据
void HeapPush(HP* php, int child)
{
	assert(php != NULL);
	if (php->size == php->capacity)  //如果容量已满，扩容
	{
		//扩容
		int newCapacity = ((php->capacity == 0) ? 4 : sizeof(php->a) * 2);
		HPDataType* ptr = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newCapacity);
		if (ptr == NULL)
		{
			perror("申请内存失败");
			exit(-1);
		}
		php->a = ptr;
		php->capacity = newCapacity;
	}

	php->a[php->size] = child;   //插入数据
	php->size++;
	AdjustUp(php->a, php->size - 1);     //向上调整是对已有的数据通过其索引来找到对应的值进行调整，所有只需要传入php->a以及尾插数据的索引值
}

//pop堆顶数据
void HeapPop(HP* php)
{
	assert(php != NULL);

	if (php->size == 0) {
		printf("堆中为空，不可删除\n");
		return;
	}

	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	--php->size;

	AdjustDown(php->a, php->size, 0);

	printf("删除成功\n");
}

//判断是否为空
bool HpEmpty(HP* pHp)
{
	assert(pHp);

	return pHp->size == 0;
}

// 取堆顶的数据
void HpTop(HP* pHp)
{
	assert(pHp);

	printf("堆顶数据是: %d\n",pHp->a[0]);
}

// 堆的数据个数
void HpSize(HP* pHp)
{
	assert(pHp);

	 printf("堆中数据个数是: %d\n",pHp->size);
}





