#include <iostream>

using namespace std;

bool isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return originalNum == reversedNum;
}

void fillArrayWithPalindromes(int arr[], int size) {
    int num = 1;
    for (int i = 0; i < size; ++i) {
        while (!isPalindrome(num)) {
            ++num;
        }
        arr[i] = num;
        ++num;
    }
}

int interpolationSearch(const int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == key) {
            return pos;
        }
        if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    const int size = 25;
    int arr[size];
    fillArrayWithPalindromes(arr, size);

    int key;
    cout << "Enter the number to search: ";
    cin >> key;

    int index = interpolationSearch(arr, size, key);
    if (index != -1) {
        cout << "Number " << key << " found at index " << index << endl;
    } else {
        cout << "Number " << key << " not found in the array" << endl;
    }

    return 0;
}
