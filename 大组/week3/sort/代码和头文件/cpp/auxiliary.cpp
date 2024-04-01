#include"sort.h"

/*
    这个是辅助函数文件，包括输入数据的函数、读取文件、随机生成数据、测试用时
*/


//输入数据的函数 使用动态数组
int* createArray(int& size, int& inputCount) {
    cout << "请输入数组大小：";
    cin >> size;

    // 判断输入是否为整数类型，如果不是则重新输入
    while (cin.fail() || size <= 0) {
        cout << "输入无效，请重新输入一个正整数：" << endl;
        cin.clear(); // 清除输入流的错误标志
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略缓冲区中的错误字符
        cin >> size;
    }

    // 清除输入缓冲区中的换行符
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // 动态分配内存
    int* arr = new int[size];

    cout << "请输入" << size << "个整数（输入'exit'可提前退出，其他非整数值将被忽略）：" << endl;

    // 循环输入数组元素，同时检查输入的数量
    inputCount = 0;
    while (inputCount < size) {
        string input;
        cin >> input;

        if (input == "exit") {
            // 输出当前已经输入的数组元素
            cout << "当前已输入的数组元素为：" << endl;
            for (int i = 0; i < inputCount; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;

            // 清除输入缓冲区中的剩余字符
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "您选择了提前退出。" << endl;
            delete[] arr; // 释放动态分配的内存
            return nullptr; // 返回空指针表示程序提前退出
        }


        try {
            // 检查输入中是否包含非数字字符
            if (input.find_first_not_of("0123456789") != string::npos) {
                throw invalid_argument("非整数值"); // 抛出异常
            }
            arr[inputCount] = stoi(input);
            ++inputCount;
        }
        catch (const invalid_argument& e) {
            cout << "输入无效，请重新输入一个整数或者输入'exit'退出：" << endl;
            cin.clear(); // 清除输入流的错误标志
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除缓冲区中的无效输入
        }
    }
    return arr;
}


//读取文件
const int MAX_SIZE = 10000; // 数组最大长度，根据需要调整（使用动态数组解决不了内存的问题，所以只能使用静态数组了）
int readNumbersFromFile(const string& filename, vector<int>& numbers) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "无法打开文件: " << filename << endl;
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
int* startRead() {//读取文件的入口
    vector<int> numbers;
    string filename = "F:\\git\\clone\\QGtraning\\大组\\week3\\sort\\存储数据文件\\sort.txt"; // 修改为文件路径

    int length = readNumbersFromFile(filename, numbers);

    // 检查文件是否为空
    if (length == 0) {
        cout << "文件为空，无需进行后续操作。" << endl;
        return 0;
    }

    // 将容器中的数字复制到数组中
      // 使用静态数组来接收容器的数字
    static int arr[MAX_SIZE];

    // 将容器中的数字复制到数组中
    for (int i = 0; i < length; ++i) {
        arr[i] = numbers[i];
    }

    // 返回数组指针
    return arr;

  
   
}


// 计算数组长度的函数
int calculateArrayLength(int* arr) {
    int length = 0;
    while (arr[length] != '\0') {
        length++;
    }
    return length;
}


//随机生成数据（0-100）并输入到文件中
void generateNumbers(const string& filename, int maxSize, int maxValue) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "无法打开文件: " << filename << endl;
        return;
    }

    srand(time(nullptr)); // 设置随机种子

    int size = rand() % (maxSize + 1); // 随机生成数组大小

    for (int i = 0; i < size; ++i) {
        int randomNumber = rand() % (maxValue + 1); // 生成随机数
        file << randomNumber << " "; // 写入文件
    }

    file.close();
}
void startWrite() {
    string filename = "F:\\git\\clone\\QGtraning\\大组\\week3\\sort\\存储数据文件\\sort.txt";
    int maxSize = 100; // 数组最大大小
    int maxValue = 100; // 随机数范围最大值

    generateNumbers(filename, maxSize, maxValue);
    cout << "已生成随机数组并写入文件: " << filename << endl;

}


//测试用时（大数据量）
// 生成随机数组
void generateArray1(int arr[], int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000000;  // 生成 0 到 999999 之间的随机数
    }
}
// 测试排序算法的运行时间
void testSortingAlgorithm1(void (*sortFunction)(int[], int), int size) {
    int* arr = new int[size];
    generateArray1(arr, size);

    auto start = high_resolution_clock::now();//记录开始时间
    sortFunction(arr, size);
    auto stop = high_resolution_clock::now();//结束时间

    auto duration = duration_cast<milliseconds>(stop - start);//过程的时间

    cout << "排序时间: " << size << ": " << duration.count() << " ms." << endl;

    delete[] arr;
}
// 测试快速排序算法的运行时间
void testQuickSort1(int arr[], int size) {
    auto start = high_resolution_clock::now();
    Quick_sort(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "排序时间" << size << ": " << duration.count() << " ms." << endl;
}
// 测试不同大小数据集下的排序算法运行时间
void startTest1() {
    cout << "Insert_sort:" << endl;
    testSortingAlgorithm1(Insert_sort, 10000);
    testSortingAlgorithm1(Insert_sort, 50000);
    testSortingAlgorithm1(Insert_sort, 200000);

    // 测试快速排序算法
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


//测试用时（大量小数据）
// 生成随机数组
void generateArray2(int arr[], int arrSize) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);
    for (int i = 0; i < arrSize; ++i) {
        arr[i] = dis(gen);
    }
}
// 测试排序算法的运行时间
void testSortingAlgorithm2(void (*sortFunction)(int[], int), int arrSize, int iterations) {
    auto* arr = new int[arrSize];
    generateArray2(arr, arrSize);

    auto start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        sortFunction(arr, arrSize);
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "对大小为" << arrSize << "的数组进行 " << iterations << " 次排序的时间: " << duration.count() << " ms." << endl;

    delete[] arr;
}
// 测试快速排序算法的运行时间
void testQuickSort2(int arr[], int arrSize, int iterations) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        sort(arr, arr + arrSize);
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "对大小为" << arrSize << "的数组进行 " << iterations << " 次排序的时间:  " << duration.count() << " ms." << endl;
}
// 测试不同大量的小数据集下的排序算法运行时间
void startTest2() {
    int iterations = 100000;

    // 测试不同大小数据集下的排序算法运行时间
    cout << "Insertion Sort:" << endl;
    testSortingAlgorithm2(Insert_sort, 100, iterations);
    testSortingAlgorithm2(Insert_sort, 500, iterations);
    testSortingAlgorithm2(Insert_sort, 1000, iterations);

    cout << "\nMerge Sort:" << endl;
    testSortingAlgorithm2(Merge_sort, 100, iterations);
    testSortingAlgorithm2(Merge_sort, 500, iterations);
    testSortingAlgorithm2(Merge_sort, 1000, iterations);

    // 测试快速排序算法
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