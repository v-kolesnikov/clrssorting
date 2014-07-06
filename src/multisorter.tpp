
template<typename T>
T *MultiSorter::insertionSort(const T *a, const int size, const Order flag)
{
    T* sortedArray = clone(a, size);

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
T *MultiSorter::selectionSort(const T *a, const int size, const Order flag)
{
    T* sortedArray = clone(a, size);

    for (int i = 0; i < size; ++i) {
        int idx = i;
        int buffer = sortedArray[i] ;
        for (int j = i + 1; j < size; ++j) {
            if (flag == Order::Ascend ? sortedArray[j] < buffer : sortedArray[j] > buffer) {
                idx = j;
                buffer = sortedArray[j];
            }
        }
        sortedArray[idx] = sortedArray[i];
        sortedArray[i] = buffer;
    }

    return sortedArray;
}

template<typename T>
T *MultiSorter::bubbleSort(const T *a, const int size, const Order flag)
{
    T * sortedArray = clone(a, size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (flag == Order::Ascend ? sortedArray[j] > sortedArray[j+1] : sortedArray[j] < sortedArray[j+1]) {
                int bubble = sortedArray[j];
                sortedArray[j] = sortedArray[j+1];
                sortedArray[j+1] = bubble;
            }
        }
    }

    return sortedArray;
}


// HELPER FUNCTIONS

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
