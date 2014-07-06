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

    static int * insertionSort(const int *a, const int size, const Order flag = Order::Ascend); // Θ(n^2)
    static int * selectionSort(const int *a, const int size, const Order flag = Order::Ascend); // Θ(n^2)
    static int * bubbleSort(const int *a, const int size, const Order flag = Order::Ascend);    // Θ(n^2)

private:

    static int * createArray(const int size);
    static int * cloneArray(const int *a, const int size);

    static void deleteArray(const int *a, const int size);
    static void printArray(const int *a, const int size);
};
}
#endif // MULTISORTER_H
