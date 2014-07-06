#ifndef MULTISORTER_H
#define MULTISORTER_H

namespace CLRS {
enum Order {
    Ascend = 0x1,
    Descend = 0x2
};

class MultiSorter
{
public:
    MultiSorter();

    template<typename T>
    static T *insertionSort(const T *a, const int size, const Order flag = Order::Ascend);

//    static int *insertionSort(const int *a, const int size, const Order flag = Order::Ascend); // Θ(n^2)
    static int *selectionSort(const int *a, const int size, const Order flag = Order::Ascend); // Θ(n^2)
    static int *bubbleSort(const int *a, const int size, const Order flag = Order::Ascend);    // Θ(n^2)

    template<typename T>
    static T *clone(const T *a, const int size);

private:

    static int * createArray(const int size);
    static int * cloneArray(const int *a, const int size);

    static void deleteArray(const int *a, const int size);
    static void printArray(const int *a, const int size);
};

#include "multisorter.tpp"

}   // CLRS namespave

#endif // MULTISORTER_H
