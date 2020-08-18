#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(int array[], int size)  
{
    cout << "Sorted Array: ";
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
    printArray(array, size);
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
    printArray(array, size);
}

void selectSortType(int array[], int size)
{
    int select;
    cout << "Select your choice of sorting: \n1: Bubble Sort \n2: Insertion sort \n3: Quick sort \n4: Merge sort\n";
    cin >> select;
    switch(select)
    {
        case 1:
            bubbleSort(array, size);
            break;
        case 2:
            insertionSort(array, size);
            break;
        default:
            cout << "Invalid Input" << endl;
    }
}

int main()
{
    int size;
    cout << "Enter the size of an Array: \n";
    cin >> size;
    int userArray[size];
    cout << "Enter elements of array: \n";
    for (int i = 0; i < size; i++)
    {
        cin >> userArray[i];
    }
    selectSortType(userArray, size);
}
