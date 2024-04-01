#include"sort.h"

/*
	�����㷨ʵ��
*/

//��ӡ����
void printarr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int j = arr[i];
		printf("%d ", j);
	}
}


// ��������������Ԫ�ص�ֵ
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


//��������
void Insert_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) { // ������ĵڶ���Ԫ�ؿ�ʼ����
		int temp = arr[i];  // ��ǰ�������Ԫ��
		int j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp; // ���������Ԫ�ط�����ȷ��λ��
	}
}


//��������
void Quick_sort(int arr[], int start, int end) {
	//�ݹ�Ľ�������
	if (start >= end) {
		return;
	}

	int p = arr[start];
	int left = start, right = end;
	while (left < right) {
		//�ҵ����м�ֵС��
		while (arr[right] >= p && left < right) {
			right--;
		}

		//�ҵ����м�ֵ���
		while (arr[left] <= p && left < right) {
			left++;
		}


		//���ҵ��Ļ���
		swap(arr[left], arr[right]);
	}

	//���м�ֵ�Ż�����
	arr[start] = arr[left];
	arr[left] = p;

	//�ݹ�
	Quick_sort(arr, start, left - 1);
	Quick_sort(arr, left + 1, end);
}


//�鲢����
void merge(int arr[], int tempArr[], int left, int mid, int right) {
	int l_pos = left;//�������һ��
	int pos = left;//��ʱ������±�Ԫ��
	int r_pos = mid + 1;//�Ұ�����һ��

	//�ϲ�
	while (l_pos <= mid && r_pos <= right) {
		if (arr[l_pos] < arr[r_pos]) {
			tempArr[pos++] = arr[l_pos++];
		}
		else
		{
			tempArr[pos++] = arr[r_pos++];
		}
	}

	//��ʣ�µļӵ���ʱ������ȥ
	while (l_pos <= mid) {
		tempArr[pos++] = arr[l_pos++];
	}

	while (r_pos <= right) {
		tempArr[pos++] = arr[r_pos++];
	}

	//���Ѻϲ������ʱ����Ż�ԭ����������
	while (left <= right)
	{
		arr[left] = tempArr[left];
		left++;
	}
}
void msort(int arr[], int tempArr[], int left, int right) {
	//��ֻ��һ��Ԫ�أ�����Ҫ
	if (left < right) {
		int mid = (left + right) / 2;//�����е�
		//��ʼ�ݹ�
		msort(arr, tempArr, left, mid);
		msort(arr, tempArr, mid + 1, right);
		//�ϲ������򲿷�
		merge(arr, tempArr, left, mid, right);
	}
}
void Merge_sort(int arr[], int n) {//���
	int* tempArr = (int*)malloc(n * sizeof(int));
	if (tempArr) {
		msort(arr, tempArr, 0, n - 1);
		free(tempArr);
	}
	else
	{
		printf("��ȡʧ��");
	}
}


//��������
void Count_sort(int arr[], int n) {
	if (n < 2) {
		return;
	}

	//Ѱ������Ԫ��
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	//����һ������Ϊmax-1�����鴢����� ��ʼ��Ϊ0
	int* count = (int*)malloc(sizeof(int) * (max + 1));
	memset(count, 0, sizeof(int) * (max + 1));

	//����
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	//�����ۼ�ֵ
	for (int i = 1; i < max + 1; i++) {
		count[i] += count[i - 1];
	}

	//������ʱ���鱣����
	int* output = (int*)malloc(sizeof(int) * n);

	//��Ԫ�ط�����ȷ��λ��
	for (int i = 0; i < n; i++) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	//��������ƻ�ԭ����
	for (int i = 0; i < n; i++) {
		arr[i] = output[i];
	}

}


//��������
int Get_max(int arr[], int n) {
	int max = arr[0];

	for (int i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	return max;
}//ȡ���ֵ
int Get_count(int num) {
	int count = 1;

	while (num / 10) {
		count++;
		num /= 10;
	}

	return count;
}//�������λ��
int Get_num(int num, int pos) {
	int temp = 1;

	for (int i = 0; i < pos - 1; i++) {
		temp *= 10;
	}

	return (num / temp) % 10;
}//����Ҫ���ĳλ��
void Bucket_sort(int arr[], int n, int pos) {
	//��ÿ��Ͱ����ʼֵ
	int* bucketArray[10] = { NULL };
	for (int i = 0; i < 10; i++) {
		bucketArray[i] = (int*)calloc(n, sizeof(int));
		assert(bucketArray[i]);
	}

	//װͰ
	for (int i = 0; i < n; i++) {
		int index = Get_num(arr[i], pos);
		for (int j = 0; j < n; j++) {
			if (bucketArray[index][j] == 0) {
				bucketArray[index][j] = arr[i];
				break;
			}
		}
	}

	//��Ͱ
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



//ð�������Ż���
void Bubble_sort(int arr[], int n) {
	int i, j, k, up, down, temp, flag;
	up = n - 1;
	down = 0;
	for (i = n - 1; i > 0; i--) {
		for (j = down; j < up; j++) {//��ǰ������
			if (arr[j] > arr[j + 1]) {//�������
				swap(arr[j], arr[j + 1]);
				flag = j;//ȡ����ǩ
			}
		}

		if (flag == -1) {
			break;
		}

		up = flag;//�õ�flag��ֵ
		flag = -1;//����

		for (k = up; k > down; k--) {
			if (arr[k] < arr[k - 1]) {
				swap(arr[k], arr[k - 1]);
				flag = k;
			}
		}

		if (flag == -1) {
			break;
		}
		down = flag;//�õ�flag��ֵ
		flag = -1;
	}


}


//���ţ��ǵݹ飩
void Quick_sort2(int arr[], int start,int end) {
	// ����һ��ջ��ģ��ݹ����
	stack<int> s;
	s.push(end);
	s.push(start);

	while (!s.empty()) {
		int left = s.top();
		s.pop();
		int right = s.top();
		s.pop();

		// ���������Ч������������ѭ��
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

		// ����Ԫ�طŵ���ȷ��λ��
		arr[left] = arr[l];
		arr[l] = index;

		// �ֱ������������������ջ
		s.push(l - 1);
		s.push(left);
		s.push(right);
		s.push(l + 1);
	}
}


//���ţ��Ż���
int selectPivot(int arr[], int start, int end) {
	// ���ѡ����Ԫ������
	int index = start + rand() % (end - start + 1);
	return index;// ���ѡ��һ����Ԫ��
}
void Quick_sortPro(int arr[], int start,int end) {
	if (start >= end) {
		return;
	}

	// ���ѡ����Ԫ��
	int index = selectPivot(arr, start, end);
	int pivot = arr[index];

	// ����Ԫ�ؽ����������
	swap(arr[start], arr[index]);

	int left = start + 1, right = end;
	int i = left;

	// ����Ϊ��������С����Ԫ�ء�������Ԫ�ء�������Ԫ��
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

	// ����Ԫ�طŵ���ȷ��λ��
	swap(arr[start], arr[left - 1]);

	// �ݹ�������ߺ��ұߵ�������
	Quick_sortPro(arr, start, left - 2);
	Quick_sortPro(arr, right, end);
}


