#include"sort.h"

/*
    ����Ǹ��������ļ��������������ݵĺ�������ȡ�ļ�������������ݡ�������ʱ
*/


//�������ݵĺ��� ʹ�ö�̬����
int* createArray(int& size, int& inputCount) {
    cout << "�����������С��";
    cin >> size;

    // �ж������Ƿ�Ϊ�������ͣ������������������
    while (cin.fail() || size <= 0) {
        cout << "������Ч������������һ����������" << endl;
        cin.clear(); // ����������Ĵ����־
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Ի������еĴ����ַ�
        cin >> size;
    }

    // ������뻺�����еĻ��з�
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // ��̬�����ڴ�
    int* arr = new int[size];

    cout << "������" << size << "������������'exit'����ǰ�˳�������������ֵ�������ԣ���" << endl;

    // ѭ����������Ԫ�أ�ͬʱ������������
    inputCount = 0;
    while (inputCount < size) {
        string input;
        cin >> input;

        if (input == "exit") {
            // �����ǰ�Ѿ����������Ԫ��
            cout << "��ǰ�����������Ԫ��Ϊ��" << endl;
            for (int i = 0; i < inputCount; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;

            // ������뻺�����е�ʣ���ַ�
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "��ѡ������ǰ�˳���" << endl;
            delete[] arr; // �ͷŶ�̬������ڴ�
            return nullptr; // ���ؿ�ָ���ʾ������ǰ�˳�
        }


        try {
            // ����������Ƿ�����������ַ�
            if (input.find_first_not_of("0123456789") != string::npos) {
                throw invalid_argument("������ֵ"); // �׳��쳣
            }
            arr[inputCount] = stoi(input);
            ++inputCount;
        }
        catch (const invalid_argument& e) {
            cout << "������Ч������������һ��������������'exit'�˳���" << endl;
            cin.clear(); // ����������Ĵ����־
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ����������е���Ч����
        }
    }
    return arr;
}


//��ȡ�ļ�
const int MAX_SIZE = 10000; // ������󳤶ȣ�������Ҫ������ʹ�ö�̬�����������ڴ�����⣬����ֻ��ʹ�þ�̬�����ˣ�
int readNumbersFromFile(const string& filename, vector<int>& numbers) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "�޷����ļ�: " << filename << endl;
        return 0;
    }

    while (getline(file, line)) {
        istringstream iss(line);
        int num;
        while (iss >> num) {
            numbers.push_back(num);
        }
    }

    file.close();
    return numbers.size();
}
int* startRead() {//��ȡ�ļ������
    vector<int> numbers;
    string filename = "F:\\git\\clone\\QGtraning\\����\\week3\\sort\\�洢�����ļ�\\sort.txt"; // �޸�Ϊ�ļ�·��

    int length = readNumbersFromFile(filename, numbers);

    // ����ļ��Ƿ�Ϊ��
    if (length == 0) {
        cout << "�ļ�Ϊ�գ�������к���������" << endl;
        return 0;
    }

    // �������е����ָ��Ƶ�������
      // ʹ�þ�̬��������������������
    static int arr[MAX_SIZE];

    // �������е����ָ��Ƶ�������
    for (int i = 0; i < length; ++i) {
        arr[i] = numbers[i];
    }

    // ��������ָ��
    return arr;

  
   
}


// �������鳤�ȵĺ���
int calculateArrayLength(int* arr) {
    int length = 0;
    while (arr[length] != '\0') {
        length++;
    }
    return length;
}


//����������ݣ�0-100�������뵽�ļ���
void generateNumbers(const string& filename, int maxSize, int maxValue) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "�޷����ļ�: " << filename << endl;
        return;
    }

    srand(time(nullptr)); // �����������

    int size = rand() % (maxSize + 1); // ������������С

    for (int i = 0; i < size; ++i) {
        int randomNumber = rand() % (maxValue + 1); // ���������
        file << randomNumber << " "; // д���ļ�
    }

    file.close();
}
void startWrite() {
    string filename = "F:\\git\\clone\\QGtraning\\����\\week3\\sort\\�洢�����ļ�\\sort.txt";
    int maxSize = 100; // ��������С
    int maxValue = 100; // �������Χ���ֵ

    generateNumbers(filename, maxSize, maxValue);
    cout << "������������鲢д���ļ�: " << filename << endl;

}


//������ʱ������������
// �����������
void generateArray1(int arr[], int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000000;  // ���� 0 �� 999999 ֮��������
    }
}
// ���������㷨������ʱ��
void testSortingAlgorithm1(void (*sortFunction)(int[], int), int size) {
    int* arr = new int[size];
    generateArray1(arr, size);

    auto start = high_resolution_clock::now();//��¼��ʼʱ��
    sortFunction(arr, size);
    auto stop = high_resolution_clock::now();//����ʱ��

    auto duration = duration_cast<milliseconds>(stop - start);//���̵�ʱ��

    cout << "����ʱ��: " << size << ": " << duration.count() << " ms." << endl;

    delete[] arr;
}
// ���Կ��������㷨������ʱ��
void testQuickSort1(int arr[], int size) {
    auto start = high_resolution_clock::now();
    Quick_sort(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "����ʱ��" << size << ": " << duration.count() << " ms." << endl;
}
// ���Բ�ͬ��С���ݼ��µ������㷨����ʱ��
void startTest1() {
    cout << "Insert_sort:" << endl;
    testSortingAlgorithm1(Insert_sort, 10000);
    testSortingAlgorithm1(Insert_sort, 50000);
    testSortingAlgorithm1(Insert_sort, 200000);

    // ���Կ��������㷨
    cout << "\nQuick_sort:" << endl;
    int* arr_10000 = new int[10000];
    int* arr_50000 = new int[50000];
    int* arr_200000 = new int[200000];

    generateArray1(arr_10000, 10000);
    generateArray1(arr_50000, 50000);
    generateArray1(arr_200000, 200000);

    testQuickSort1(arr_10000, 10000);
    testQuickSort1(arr_50000, 50000);
    testQuickSort1(arr_200000, 200000);

    delete[] arr_10000;
    delete[] arr_50000;
    delete[] arr_200000;

    cout << "\nMerge_sort:" << endl;
    testSortingAlgorithm1(Merge_sort, 10000);
    testSortingAlgorithm1(Merge_sort, 50000);
    testSortingAlgorithm1(Merge_sort, 200000);

    cout << "\nCounting_sort:" << endl;
    testSortingAlgorithm1(Count_sort, 10000);
    testSortingAlgorithm1(Count_sort, 50000);
    testSortingAlgorithm1(Count_sort, 200000);

    cout << "\nRadix_sort:" << endl;
    testSortingAlgorithm1(RadixCount_sort, 10000);
    testSortingAlgorithm1(RadixCount_sort, 50000);
    testSortingAlgorithm1(RadixCount_sort, 200000);

    cout << "\nBubble_sort:" << endl;
    testSortingAlgorithm1(Bubble_sort, 10000);
    testSortingAlgorithm1(Bubble_sort, 50000);
    testSortingAlgorithm1(Bubble_sort, 200000);
}


//������ʱ������С���ݣ�
// �����������
void generateArray2(int arr[], int arrSize) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);
    for (int i = 0; i < arrSize; ++i) {
        arr[i] = dis(gen);
    }
}
// ���������㷨������ʱ��
void testSortingAlgorithm2(void (*sortFunction)(int[], int), int arrSize, int iterations) {
    auto* arr = new int[arrSize];
    generateArray2(arr, arrSize);

    auto start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        sortFunction(arr, arrSize);
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "�Դ�СΪ" << arrSize << "��������� " << iterations << " �������ʱ��: " << duration.count() << " ms." << endl;

    delete[] arr;
}
// ���Կ��������㷨������ʱ��
void testQuickSort2(int arr[], int arrSize, int iterations) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        sort(arr, arr + arrSize);
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "�Դ�СΪ" << arrSize << "��������� " << iterations << " �������ʱ��:  " << duration.count() << " ms." << endl;
}
// ���Բ�ͬ������С���ݼ��µ������㷨����ʱ��
void startTest2() {
    int iterations = 100000;

    // ���Բ�ͬ��С���ݼ��µ������㷨����ʱ��
    cout << "Insertion Sort:" << endl;
    testSortingAlgorithm2(Insert_sort, 100, iterations);
    testSortingAlgorithm2(Insert_sort, 500, iterations);
    testSortingAlgorithm2(Insert_sort, 1000, iterations);

    cout << "\nMerge Sort:" << endl;
    testSortingAlgorithm2(Merge_sort, 100, iterations);
    testSortingAlgorithm2(Merge_sort, 500, iterations);
    testSortingAlgorithm2(Merge_sort, 1000, iterations);

    // ���Կ��������㷨
    cout << "\nQuick Sort:" << endl;
    int* arr_100 = new int[100];
    int* arr_500 = new int[500];
    int* arr_1000 = new int[1000];

    generateArray2(arr_100, 100);
    generateArray2(arr_500, 500);
    generateArray2(arr_1000, 1000);

    testQuickSort2(arr_100, 100, iterations);
    testQuickSort2(arr_500, 500, iterations);
    testQuickSort2(arr_1000, 1000, iterations);

    delete[] arr_100;
    delete[] arr_500;
    delete[] arr_1000;

    cout << "\nCount_sort:" << endl;
    testSortingAlgorithm2(Merge_sort, 100, iterations);
    testSortingAlgorithm2(Merge_sort, 500, iterations);
    testSortingAlgorithm2(Merge_sort, 1000, iterations);

    cout << "\nBubble_sort:" << endl;
    testSortingAlgorithm2(Merge_sort, 100, iterations);
    testSortingAlgorithm2(Merge_sort, 500, iterations);
    testSortingAlgorithm2(Merge_sort, 1000, iterations);

    cout << "\nRadix_sort:" << endl;
    testSortingAlgorithm2(Merge_sort, 100, iterations);
    testSortingAlgorithm2(Merge_sort, 500, iterations);
    testSortingAlgorithm2(Merge_sort, 1000, iterations);

}