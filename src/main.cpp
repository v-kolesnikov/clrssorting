#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTime>
#include <QDebug>

#include <iostream>
#include "multisorter.h"

using namespace CLRS;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QDebug debug(QtDebugMsg);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    const int size = 20;
    int *sourceArray = new int[size];
    int *sortedArray = nullptr;

    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    int top = 90;

    for (int i = 0; i < size; ++i) {
        sourceArray[i] = qrand() % top + 10;
        debug << sourceArray[i] << ' ';
    }

    debug << endl << endl;

//    1. Insertion sort
//    sortedArray = MultiSorter::insertionSort(sourceArray, size, Order::Ascend);

//    for (int i = 0; i < size; ++i) {
//        debug << sortedArray[i] << ' ';
//    }

//    debug << endl << endl;

//    sortedArray = MultiSorter::insertionSort(sourceArray, size, Order::Descend);

//    for (int i = 0; i < size; ++i) {
//        debug << sortedArray[i] << ' ';
//    }


//    2. Selection sort

//    sortedArray = MultiSorter::selectionSort(sourceArray, size, Order::Descend);

//    for (int i = 0; i < size; ++i) {
//        debug << sortedArray[i] << ' ';
//    }


//    3. Bubble sort

    sortedArray = MultiSorter::bubbleSort(sourceArray, size, Order::Descend);

    for (int i = 0; i < size; ++i) {
        debug << sortedArray[i] << ' ';
    }

    return 0; //app.exec();
}
