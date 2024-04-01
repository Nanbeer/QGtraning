#include"sort.h"

/*
	排序算法实现
*/

//打印函数
void printarr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int j = arr[i];
		printf("%d ", j);
	}
}


// 交换数组中两个元素的值
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


//插入排序
void Insert_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) { // 从数组的第二个元素开始遍历
		int temp = arr[i];  // 当前待插入的元素
		int j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp; // 将待插入的元素放入正确的位置
	}
}


//快速排序
void Quick_sort(int arr[], int start, int end) {
	//递归的结束条件
	if (start >= end) {
		return;
	}

	int p = arr[start];
	int left = start, right = end;
	while (left < right) {
		//找到比中间值小的
		while (arr[right] >= p && left < right) {
			right--;
		}

		//找到比中间值大的
		while (arr[left] <= p && left < right) {
			left++;
		}


		//将找到的互换
		swap(arr[left], arr[right]);
	}

	//将中间值放回数组
	arr[start] = arr[left];
	arr[left] = p;

	//递归
	Quick_sort(arr, start, left - 1);
	Quick_sort(arr, left + 1, end);
}


//归并排序
void merge(int arr[], int tempArr[], int left, int mid, int right) {
	int l_pos = left;//左半区第一个
	int pos = left;//临时数组的下标元素
	int r_pos = mid + 1;//右半区第一个

	//合并
	while (l_pos <= mid && r_pos <= right) {
		if (arr[l_pos] < arr[r_pos]) {
			tempArr[pos++] = arr[l_pos++];
		}
		else
		{
			tempArr[pos++] = arr[r_pos++];
		}
	}

	//把剩下的加到临时数组里去
	while (l_pos <= mid) {
		tempArr[pos++] = arr[l_pos++];
	}

	while (r_pos <= right) {
		tempArr[pos++] = arr[r_pos++];
	}

	//最后把合并后的临时数组放回原来的数组中
	while (left <= right)
	{
		arr[left] = tempArr[left];
		left++;
	}
}
void msort(int arr[], int tempArr[], int left, int right) {
	//若只有一个元素，则不需要
	if (left < right) {
		int mid = (left + right) / 2;//划出中点
		//开始递归
		msort(arr, tempArr, left, mid);
		msort(arr, tempArr, mid + 1, right);
		//合并已排序部分
		merge(arr, tempArr, left, mid, right);
	}
}
void Merge_sort(int arr[], int n) {//入口
	int* tempArr = (int*)malloc(n * sizeof(int));
	if (tempArr) {
		msort(arr, tempArr, 0, n - 1);
		free(tempArr);
	}
	else
	{
		printf("获取失败");
	}
}


//计数排序
void Count_sort(int arr[], int n) {
	if (n < 2) {
		return;
	}

	//寻找最大的元素
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	//分配一个长度为max-1的数组储存计数 初始化为0
	int* count = (int*)malloc(sizeof(int) * (max + 1));
	memset(count, 0, sizeof(int) * (max + 1));

	//计数
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	//加上累计值
	for (int i = 1; i < max + 1; i++) {
		count[i] += count[i - 1];
	}

	//创建临时数组保存结果
	int* output = (int*)malloc(sizeof(int) * n);

	//把元素放在正确的位置
	for (int i = 0; i < n; i++) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	//将结果复制回原数组
	for (int i = 0; i < n; i++) {
		arr[i] = output[i];
	}

}


//基数排序
int Get_max(int arr[], int n) {
	int max = arr[0];

	for (int i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	return max;
}//取最大值
int Get_count(int num) {
	int count = 1;

	while (num / 10) {
		count++;
		num /= 10;
	}

	return count;
}//返回最大位数
int Get_num(int num, int pos) {
	int temp = 1;

	for (int i = 0; i < pos - 1; i++) {
		temp *= 10;
	}

	return (num / temp) % 10;
}//返回要求的某位数
void Bucket_sort(int arr[], int n, int pos) {
	//给每个桶赋初始值
	int* bucketArray[10] = { NULL };
	for (int i = 0; i < 10; i++) {
		bucketArray[i] = (int*)calloc(n, sizeof(int));
		assert(bucketArray[i]);
	}

	//装桶
	for (int i = 0; i < n; i++) {
		int index = Get_num(arr[i], pos);
		for (int j = 0; j < n; j++) {
			if (bucketArray[index][j] == 0) {
				bucketArray[index][j] = arr[i];
				break;
			}
		}
	}

	//出桶
	int k = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < n; j++) {
			if (bucketArray[i][j] != 0) {
				arr[k] = bucketArray[i][j];
				bucketArray[i][j] = 0;
				k++;
			}
		}
	}

}
void RadixCount_sort(int arr[], int n) {
	int max = Get_max(arr, n);
	int loogth = Get_count(max);

	for (int i = 1; i <= loogth; i++) {
		Bucket_sort(arr, n, i);
	}


}



//冒泡排序（优化）
void Bubble_sort(int arr[], int n) {
	int i, j, k, up, down, temp, flag;
	up = n - 1;
	down = 0;
	for (i = n - 1; i > 0; i--) {
		for (j = down; j < up; j++) {//从前往后排
			if (arr[j] > arr[j + 1]) {//大的往后
				swap(arr[j], arr[j + 1]);
				flag = j;//取出标签
			}
		}

		if (flag == -1) {
			break;
		}

		up = flag;//拿到flag的值
		flag = -1;//重置

		for (k = up; k > down; k--) {
			if (arr[k] < arr[k - 1]) {
				swap(arr[k], arr[k - 1]);
				flag = k;
			}
		}

		if (flag == -1) {
			break;
		}
		down = flag;//拿到flag的值
		flag = -1;
	}


}


//快排（非递归）
void Quick_sort2(int arr[], int start,int end) {
	// 创建一个栈来模拟递归过程
	stack<int> s;
	s.push(end);
	s.push(start);

	while (!s.empty()) {
		int left = s.top();
		s.pop();
		int right = s.top();
		s.pop();

		// 如果区间无效，则跳过本次循环
		if (left >= right) {
			continue;
		}

		int index = arr[left];
		int l = left, r = right;

		while (l < r) {
			while (arr[r] >= index && l < r) {
				r--;
			}
			while (arr[l] <= index && l < r) {
				l++;
			}
			if (l < r) {
				swap(arr[l], arr[r]);
			}
		}

		// 将主元素放到正确的位置
		arr[left] = arr[l];
		arr[l] = index;

		// 分别将左右子数组的区间入栈
		s.push(l - 1);
		s.push(left);
		s.push(right);
		s.push(l + 1);
	}
}


//快排（优化）
int selectPivot(int arr[], int start, int end) {
	// 随机选择主元素索引
	int index = start + rand() % (end - start + 1);
	return index;// 随机选择一个主元素
}
void Quick_sortPro(int arr[], int start,int end) {
	if (start >= end) {
		return;
	}

	// 随机选择主元素
	int index = selectPivot(arr, start, end);
	int pivot = arr[index];

	// 将主元素交换到最左边
	swap(arr[start], arr[index]);

	int left = start + 1, right = end;
	int i = left;

	// 划分为三个区域：小于主元素、等于主元素、大于主元素
	while (i <= right) {
		if (arr[i] < pivot) {
			swap(arr[i], arr[left]);
			left++;
			i++;
		}
		else if (arr[i] > pivot) {
			swap(arr[i], arr[right]);
			right--;
		}
		else {
			i++;
		}
	}

	// 将主元素放到正确的位置
	swap(arr[start], arr[left - 1]);

	// 递归排序左边和右边的子数组
	Quick_sortPro(arr, start, left - 2);
	Quick_sortPro(arr, right, end);
}


