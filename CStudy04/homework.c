#include <stdio.h>
// 题目1：冒泡排序并打印最小值和最大值
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
// 题目2：折半查找特定元素的下标
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int numArr[] = {13, 15, 27, 5, 25, 44};
    int n = sizeof(numArr) / sizeof(numArr[0]);


    bubbleSort(numArr, n);
    printf("最小值：%d\n", numArr[0]);
    printf("最大值：%d\n", numArr[n-1]);


    int key = 27;
    int index = binarySearch(numArr, n, key);
    if (index != -1)
        printf("元素 %d 的下标为：%d\n", key, index);
    else
        printf("元素 %d 不存在\n", key);

    return 0;


}
