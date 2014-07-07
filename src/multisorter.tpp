
template<typename T>
void MultiSorter::insertionSort(T *a, const int size, const Order flag)
{
    for (int i = 1; i < size; ++i) {
        T key = a[i];
        int j = i - 1;
        while (j >= 0 && (flag == Order::Ascend ? a[j] > key : a[j] < key)) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
}

template<typename T>
void MultiSorter::selectionSort(T *a, const int size, const Order flag)
{
    for (int i = 0; i < size; ++i) {
        int idx = i;
        T buffer = a[i] ;
        for (int j = i + 1; j < size; ++j) {
            if (flag == Order::Ascend ? a[j] < buffer : a[j] > buffer) {
                idx = j;
                buffer = a[j];
            }
        }
        a[idx] = a[i];
        a[i] = buffer;
    }
}

template<typename T>
void MultiSorter::bubbleSort(T *a, const int size, const Order flag)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (flag == Order::Ascend ? a[j] > a[j+1] : a[j] < a[j+1]) {
                T bubble = a[j];
                a[j] = a[j+1];
                a[j+1] = bubble;
            }
        }
    }
}

template<typename T>
void MultiSorter::merge(T *a, const int p, const int q, const int r, const Order flag)
{
    int lSize = q - p + 1;
    int rSize = r - q;

    T* leftSide = new T[lSize];
    T* rightSide = new T[rSize];

    for (int i = 0; i < lSize; ++i) {
        leftSide[i] = a[p + i];
    }

    for (int i = 0; i < rSize; ++i) {
        rightSide[i] = a[q + i + 1];
    }

    int lIdx = 0;   // Current index for leftSide array
    int rIdx = 0;   // Current index for rightSide array

    for (int i = p; i <= r; ++i) {
        if (leftSide[lIdx] <= rightSide[rIdx]) {
            a[i] = leftSide[lIdx];
            ++lIdx;
        } else {
            a[i] = rightSide[rIdx];
            ++rIdx;
        }
    }

}
