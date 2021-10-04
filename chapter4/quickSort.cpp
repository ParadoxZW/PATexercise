/*
 * Version: 0.2
 * Author: Canopus - zw.shao@foxmail.com
 * Date: 2021/9/27
 * Description: quick sort
 */


/*
 * Modified by: Canopus - zw.shao@foxmail.com
 * old version
 * `A[right] > tmp` and `A[left] < tmp` is a bug.
 *

int Partition(int A[], int left, int right) {
    int tmp = A[left];
    while(left < right) {
        while (left < right && A[right] > tmp) right--;
        A[left] = A[right];
        while(left < right && A[left] < tmp) left++;
        A[right] = A[left];
    }
    A[left] = tmp;
    return left;
}
*/

#define LRP (left < right)

int Partition(int A[], int left, int right) {
    int tmp = A[left];
    while(LRP) {
        while (LRP && A[right] >= tmp) right--;
        if(LRP) A[left++] = A[right];
        while(LRP && A[left] <= tmp) left++;
        if(LRP) A[right--] = A[left];
    }
    A[left] = tmp;
    return left;
}

void quickSort(int A[], int left, int right) {
    if(LRP) {
        int pos = Partition(A, left, right);
        quickSort(A, left, pos - 1);
        quickSort(A, pos+1, right);
    }
}
