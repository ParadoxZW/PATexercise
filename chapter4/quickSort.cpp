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

void quickSort(int A[], int left, int right) {
    if(left < right) {
        int pos = Partition(A, left, right);
        quickSort(A, left, pos - 1);
        quickSort(A, pos+1, right);
    }
}