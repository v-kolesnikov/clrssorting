#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTime>
//#include <QDebug>

#include <iostream>
#include "multisorter.h"

using namespace CLRS;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    const int size = 20;
    int *sourceArray = new int[size];
    int *sortedArray = nullptr;

    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    int top = 90;

    std::cout << "Unsort: ";
    for (int i = 0; i < size; ++i) {
        sourceArray[i] = qrand() % top + 10;
        std::cout << sourceArray[i] << ' ';
    }

    std::cout << "\n";

    //    1. Insertion sort
    sortedArray = MultiSorter::insertionSort(sourceArray, size, Order::Ascend);

    std::cout << "InsertionSort\n" << "Ascend: ";
    for (int i = 0; i < size; ++i) {
        std::cout << sortedArray[i] << ' ';
    }

//    delete [] sortedArray;

//    std::cout << "\n";

//    sortedArray = MultiSorter::insertionSort(sourceArray, size, Order::Descend);

//    std::cout << "Descend:";
//    for (int i = 0; i < size; ++i) {
//        std::cout << sortedArray[i] << ' ';
//    }

//    delete [] sortedArray;

    //    2. Selection sort

//    sortedArray = MultiSorter::selectionSort(sourceArray, size, Order::Ascend);

//    std::cout << "\nSelection sort\n" << "Ascend: ";
//    for (int i = 0; i < size; ++i) {
//        std::cout << sortedArray[i] << ' ';
//    }


//    3. Bubble sort

//    sortedArray = MultiSorter::bubbleSort(sourceArray, size, Order::Descend);

//    debug << endl << "Bubble sort" << endl << "Descend:";
//    for (int i = 0; i < size; ++i) {
//        debug << sortedArray[i] << ' ';
//    }

    //    4. Testing clone template

    //    sortedArray = MultiSorter::clone(sourceArray, size);

    //    for (int i = 0; i < size; ++i) {
    //        debug << sortedArray[i] << ' ';
    //    }

    return 0; //app.exec();
}
