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

//    1. Sorting algoritms
    template<typename T>
    static void insertionSort( T *a, const int size, const Order flag = Order::Ascend ); // Θ(n^2)

    template<typename T>
    static void selectionSort( T *a, const int size, const Order flag = Order::Ascend ); // Θ(n^2)

    template<typename T>
    static void bubbleSort( T *a, const int size, const Order flag = Order::Ascend );    // Θ(n^2)
};

#include "multisorter.tpp"

}   // CLRS namespace

#endif // MULTISORTER_H
