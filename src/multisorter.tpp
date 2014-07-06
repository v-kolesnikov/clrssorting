
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
