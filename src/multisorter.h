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
    static void insertionSort( T *a, const int size, const Order flag = Order::Ascend ); // Θ(n^2)

    template<typename T>
    static void selectionSort( T *a, const int size, const Order flag = Order::Ascend ); // Θ(n^2)

    template<typename T>
    static void bubbleSort( T *a, const int size, const Order flag = Order::Ascend );    // Θ(n^2)

    template<typename T>
    static void mergeSort( T *a, const int begin, const int end, const Order flag = Order::Ascend );    // Θ(nlgn)

    template<typename T>
    static void merge( T *a, const int p, const int q, const int r, const Order flag = Order::Ascend ); // Θ(n)

    template<typename T>
    static void findMaxSubarray( T *a, const int begin, const int end,
                                 int &lMax, int &rMax, T &sum);

    template<typename T>
    static void findMaxCrossSubarray( T *a, const int begin, const int mid, const int end,
                                      int &lMax, int &rMax, T &sum);
};

#include "multisorter.tpp"

}   // CLRS namespace

#endif // MULTISORTER_H
