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
    int *sourceArray = new int[size];

    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    int top = 90;

    std::cout << "Unsort: ";
    for (int i = 0; i < size; ++i) {
        sourceArray[i] = qrand() % top + 10;
        std::cout << sourceArray[i] << ' ';
    }

    std::cout << "\n";


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

    return 0;
}
