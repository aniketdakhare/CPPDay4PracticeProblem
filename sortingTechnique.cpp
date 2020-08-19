#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(int array[], int size)
{
    cout << "\nSorted Array: ";
    for (int n = 0; n < size; ++n)
    {
        cout << array[n] << "  ";
    }
}

void bubbleSort(int array[], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        int flag = 0;
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int number = array[i];
        int vacantIndex = i;

        while (vacantIndex > 0 && array[vacantIndex - 1] > number)
        {
            array[vacantIndex] = array[vacantIndex - 1];
            vacantIndex = vacantIndex - 1;
        }
        array[vacantIndex] = number;
    }
}

void merge(int leftArray[], int leftArraySize, int rightArray[], int rightArraySize, int completeArray[])
{
    int i = 0, j = 0 , k = 0;
    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            completeArray[k] = leftArray[i];
            i++;
        }
        else
        {
            completeArray[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftArraySize)
    {
        completeArray[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightArraySize)
    {
        completeArray[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int size)
{
    if (size > 1)
    {
        int mid = size / 2;
        int leftArray[mid], rightArray[size - mid];

        for (int i = 0; i < mid; i++)
        {
            leftArray[i] = array[i];
        }

        for (int i = mid; i < size; i++)
        {
            rightArray[i - mid] = array[i];
        }
        mergeSort(leftArray, mid);
        mergeSort(rightArray, (size - mid));
        merge(leftArray, mid, rightArray, (size -mid), array);
    }
}

int partition(int array[], int start, int end)
{
    int partitionElement = array[end];
    int partitionIndex = start;

    for (int i = start; i < end; i++)
    {
        if (array[i] <= partitionElement)
        {
            swap(array[i], array[partitionIndex]);
            partitionIndex++;
        }
    }

    swap(array[partitionIndex], array[end]);
    return partitionIndex;
}

void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition (array, start, end);
        quickSort(array, start, (partitionIndex - 1));
        quickSort(array, (partitionIndex + 1), end);
    }
}

void selectSortType(int array[], int size)
{
    int select;
    cout << "\nSelect your choice of sorting: \n1: Bubble Sort \n2: Insertion sort \n3: Quick sort \n4: Merge sort\n";
    cin >> select;

    switch(select)
    {
        case 1:
            bubbleSort(array, size);
            break;
        case 2:
            insertionSort(array, size);
            break;
        case 3:
            quickSort(array, 0, (size - 1));
            break;
        case 4:
            mergeSort(array, size);
            break;
        default:
            cout << "\nInvalid Input" << endl;
    }

    printArray(array, size);
}

int main()
{
    int size;
    cout << "\nEnter the size of an Array: \n";
    cin >> size;

    int userArray[size];
    cout << "\nEnter elements of array: \n";

    for (int i = 0; i < size; i++)
    {
        cin >> userArray[i];
    }

    selectSortType(userArray, size);
}
