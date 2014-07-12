
template<typename T>
void MultiSorter::insertionSort(T *a, const int size, const Order flag)
{
    for (int i = 1; i < size; ++i) {
        T key = a[i];
        int j = i - 1;
        while (j >= 0 && (flag == Order::Ascend ? a[j] > key : a[j] < key)) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
}

template<typename T>
void MultiSorter::selectionSort(T *a, const int size, const Order flag)
{
    for (int i = 0; i < size; ++i) {
        int idx = i;
        T buffer = a[i] ;
        for (int j = i + 1; j < size; ++j) {
            if (flag == Order::Ascend ? a[j] < buffer : a[j] > buffer) {
                idx = j;
                buffer = a[j];
            }
        }
        a[idx] = a[i];
        a[i] = buffer;
    }
}

template<typename T>
void MultiSorter::bubbleSort(T *a, const int size, const Order flag)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (flag == Order::Ascend ? a[j] > a[j+1] : a[j] < a[j+1]) {
                T bubble = a[j];
                a[j] = a[j+1];
                a[j+1] = bubble;
            }
        }
    }
}

template<typename T>
void MultiSorter::mergeSort( T *a, const int begin, const int end, const Order flag)
{
    if (begin < end) {
        int mid = (begin + end) / 2;
        MultiSorter::mergeSort(a, begin, mid, flag);
        MultiSorter::mergeSort(a, mid + 1, end, flag);
        MultiSorter::merge(a, begin, mid, end, flag);
    }
}

template<typename T>
void MultiSorter::merge(T *a, const int p, const int q, const int r, const Order flag)
{
    int lSize = q - p + 1;
    int rSize = r - q;

    T* leftSide = new T[lSize];
    T* rightSide = new T[rSize];

    for (int i = 0; i < lSize; ++i) {
        leftSide[i] = a[p + i];
    }

    for (int i = 0; i < rSize; ++i) {
        rightSide[i] = a[q + i + 1];
    }

    int lIdx = 0;   // Current index for leftSide array
    int rIdx = 0;   // Current index for rightSide array

    for (int i = p; i <= r; ++i) {
        if (lIdx < lSize && rIdx < rSize) {
            if (flag == Order::Ascend ?
                    leftSide[lIdx] <= rightSide[rIdx] : leftSide[lIdx] >= rightSide[rIdx]) {
                a[i] = leftSide[lIdx];
                ++lIdx;
            } else {
                a[i] = rightSide[rIdx];
                ++rIdx;
            }
        } else if (lIdx < lSize) {
            a[i] = leftSide[lIdx];
            ++lIdx;
        } else if (rIdx < rSize) {
            a[i] = rightSide[rIdx];
            ++rIdx;
        }
    }
}

template<typename T>
void MultiSorter::findMaxSubarray( T *a, const int begin, const int end,
                                   int &lMax, int &rMax, T &sum)
{
    if (begin == end) {
        lMax = begin;
        rMax = end;
        sum = T(a[begin]);
    } else {
        int mid = (begin + end) / 2;

        int leftLow; int leftHight; T leftSum;
        MultiSorter::findMaxSubarray(a, begin, mid, leftLow, leftHight, leftSum);

        int rightLow; int rightHight; T rightSum;
        MultiSorter::findMaxSubarray(a, mid + 1, end, rightLow, rightHight, rightSum);

        int crossLow; int crossHight; T crossSum;
        MultiSorter::findMaxCrossSubarray(a, begin, mid, end, crossLow, crossHight, crossSum);

        if (leftSum >= rightSum && leftSum >= crossSum) {
            lMax = leftLow;
            rMax = leftHight;
            sum = leftSum;
        } else if (rightSum >= leftSum && rightSum >= crossSum) {
            lMax = rightLow;
            rMax = rightHight;
            sum = rightSum;
        } else {
            lMax = crossLow;
            rMax = crossHight;
            sum = crossSum;
        }
    }
}

template<typename T>
void MultiSorter::findMaxCrossSubarray( T *a, const int begin, const int mid, const int end,
                                        int &lMax, int &rMax, T &sum)
{
    T currentLeftSum = T();
    T leftSum = T();
    int maxLeft = mid;

    for (int i = mid; i >= begin; --i) {
        currentLeftSum += a[i];
        if (i == mid) {
            leftSum = currentLeftSum;
            maxLeft = i;
        } else if (currentLeftSum > leftSum) {
            leftSum = currentLeftSum;
            maxLeft = i;
        }
    }

    T currentRightSum = T();
    T rightSum = T();
    int maxRight = mid + 1;

    for (int i = mid + 1; i <= end; ++i) {
        currentRightSum += a[i];
        if (i == mid + 1) {
            rightSum = currentRightSum;
            maxRight = i;
        } else if (currentRightSum > rightSum) {
            rightSum = currentRightSum;
            maxRight = i;
        }
    }

    lMax = maxLeft;
    rMax = maxRight;
    sum = leftSum + rightSum;
}
