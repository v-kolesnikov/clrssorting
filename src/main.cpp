#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTime>
#include <iostream>
#include "multisorter.h"

using namespace CLRS;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("CLRS Sorting algoritms");

    const int size = 20;
    int *intArray = new int[size];
//    float *floatArray = new float[size];

    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    int top = 200;

    std::cout << "Unsort: ";
    for (int i = 0; i < size; ++i) {
        intArray[i] = qrand() % top - 100; //(float)(qrand() % top + 10) / 100;
        std::cout << intArray[i] << ' ';
    }
/*
    std::cout << std::endl << "Unsort: ";

    for (int i = 0; i < size; ++i) {
        floatArray[i] = (float)(qrand() % top) / 100;
        std::cout << floatArray[i] << ' ';
    }

    std::cout << std::endl;


    //    1. Insertion sort
    MultiSorter::insertionSort(sourceArray, size, Order::Ascend);

    std::cout << "InsertionSort\n" << "Ascend: ";
    for (int i = 0; i < size; ++i) {
        std::cout << sourceArray[i] << ' ';
    }

    std::cout << "\n";

    MultiSorter::insertionSort(sourceArray, size, Order::Descend);

    std::cout << "Descend:";
    for (int i = 0; i < size; ++i) {
        std::cout << sourceArray[i] << ' ';
    }

    std::cout << "\n";


    //    2. Selection sort
    MultiSorter::selectionSort(sourceArray, size, Order::Ascend);

    std::cout << "Selection sort\n" << "Ascend: ";
    for (int i = 0; i < size; ++i) {
        std::cout << sourceArray[i] << ' ';
    }

    std::cout << "\n";


    //    3. Bubble sort
    MultiSorter::bubbleSort(sourceArray, size, Order::Descend);

    std::cout << "Bubble sort\n" << "Descend:";
    for (int i = 0; i < size; ++i) {
        std::cout << sourceArray[i] << ' ';
    }


    //    4. Merge sort
    MultiSorter::mergeSort(floatArray, 0, size - 1, Order::Ascend);

    std::cout << "Merge sort\n" << "Ascend: ";
    for (int i = 0; i < size; ++i) {
        std::cout << floatArray[i] << ' ';
    }
*/
    std::cout << std::endl;
    return 0;
}
