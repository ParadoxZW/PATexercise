const int maxn = 100;
// 左孩子2i, 右孩子(2i+1)
int heap[maxn], n = 10;

void downAdjust(int low, int high) {
    // low为欲调整节点, high为堆的最后一个元素
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && heap[j+1] > heap[j]) {
            j++;
        }
        if (heap[j] > heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

void createHeap() {
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
}

void deleteTop() {
    heap[1] = heap[n--];
    downAdjust(1, n);
}

void upAdjust(int low, int high) {
    // low为1, high为欲调整节点
    int i = high, j = i / 2;
    while (j >= low) {
        if (heap[j] < heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i / 2;
        } else {
            break;
        }
    }
}

void insert (int x) {
    heap[++n] = x;
    upAdjust(1, n);
}

void heapSort() {
    createHeap();
    for (int i = n; i > 1; i--) {
        swap(heap[i], heap[1]);
        downAdjust(1, i - 1);
    }
}