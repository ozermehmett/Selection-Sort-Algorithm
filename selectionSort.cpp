#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int importNumbersFromFile(const string& filePath, int arr[], int maxSize) {
    ifstream file(filePath);
    int num, i = 0;
    
    while (file >> num && i < maxSize) {
        arr[i++] = num;
    }

    return i;
}

void measureTime(const string& filePath) {
    const int maxSize = 1000000;
    int numbers[maxSize];
    int size = importNumbersFromFile(filePath, numbers, maxSize);

    clock_t startTime = clock();

    selectionSort(numbers, size);

    clock_t endTime = clock();

    double diff = double(endTime - startTime) / CLOCKS_PER_SEC;
    
    cout << fixed << setprecision(5);
    cout << "processing time: " << diff << " second" << endl;

    cout << "Sorted list (first 5): ";
    for (int i = 0; i < 10 && i < size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main() {
    string filePath = "dataset.txt";
    measureTime(filePath);
    return 0;
}
