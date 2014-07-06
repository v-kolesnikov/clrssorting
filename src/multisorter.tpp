
template<typename T>
T *MultiSorter::insertionSort(const T *a, const int size, const Order flag)
{
    T * sortedArray = clone(a, size);

    for (int i = 1; i < size; ++i) {
        int key = sortedArray[i];
        int j = i - 1;
        while (j >= 0 && (flag == Order::Ascend ? sortedArray[j] > key : sortedArray[j] < key)) {
            sortedArray[j+1] = sortedArray[j];
            --j;
        }
        sortedArray[j+1] = key;
    }

    return sortedArray;
}


template<typename T>
T* MultiSorter::clone(const T *a, const int size)
{
    if (!a || size <= 0) {
        return 0;
    }

    T * array = new T(size);

    for (int i = 0; i < size; ++i) {
        array[i] = a[i];
    }

    return array;
}
