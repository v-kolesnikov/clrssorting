#include "multisorter.h"

using namespace CLRS;

MultiSorter::MultiSorter()
{
}

//int *MultiSorter::insertionSort(const int *a, const int size, const Order flag)
//{
//    int * sortedArray = cloneArray(a, size);

//    for (int i = 1; i < size; ++i) {
//        int key = sortedArray[i];
//        int j = i - 1;
//        while (j >= 0 && (flag == Order::Ascend ? sortedArray[j] > key : sortedArray[j] < key)) {
//            sortedArray[j+1] = sortedArray[j];
//            --j;
//        }
//        sortedArray[j+1] = key;
//    }

//    return sortedArray;
//}

//int *MultiSorter::selectionSort(const int *a, const int size, const Order flag)
//{
//    int * sortedArray = cloneArray(a, size);

//    for (int i = 0; i < size; ++i) {
//        int idx = i;
//        int buffer = sortedArray[i] ;
//        for (int j = i + 1; j < size; ++j) {
//            if (flag == Order::Ascend ? sortedArray[j] < buffer : sortedArray[j] > buffer) {
//                idx = j;
//                buffer = sortedArray[j];
//            }
//        }
//        sortedArray[idx] = sortedArray[i];
//        sortedArray[i] = buffer;
//    }

//    return sortedArray;
//}

//int *MultiSorter::bubbleSort(const int *a, const int size, const Order flag)
//{
//    int * sortedArray = cloneArray(a, size);

//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (flag == Order::Ascend ? sortedArray[j] > sortedArray[j+1] : sortedArray[j] < sortedArray[j+1]) {
//                int bubble = sortedArray[j];
//                sortedArray[j] = sortedArray[j+1];
//                sortedArray[j+1] = bubble;
//            }
//        }
//    }

//    return sortedArray;
//}

// PRIVATE

int *MultiSorter::createArray(const int size)
{
    if (size <= 0) {
        return 0;
    }

    return new int[size];
}

int *MultiSorter::cloneArray(const int *a, const int size)
{
    if (!a || size <= 0) {
        return 0;
    }

    int * array = createArray(size);

    for (int i = 0; i < size; ++i) {
        array[i] = a[i];
    }

    return array;
}

void MultiSorter::printArray(const int *a, const int size)
{
    if (!a || size <= 0)
        return;
//    QDebug debug(QtDebugMsg);
    for (int i = 0; i < size; ++i) {
//        debug << a[i] << ' ';
    }
}
