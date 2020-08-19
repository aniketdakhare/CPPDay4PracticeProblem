#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printResult(int index, int element)
{
    if (index == -1)
        cout << "Given element is not present" << endl; 
    else
        cout << element << " is present at index " << index << endl;
}

void linearSearch(int array[], int size, int element)
{
    for (int n = 0; n < size; ++n) 
    {
        cout << array[n] << "  ";
    }
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element) 
        {
            index = i;
            break;
        }
        else
        {
            index = -1;
        }
    }
    cout << index << endl;
    printResult(index, element);
}

void searchType(int array[], int size, int element)
{
    int select;
    cout << "\nSelect your choice of searching: \n1: linear search \n2: Binary search\n";
    cin >> select;
    switch(select)
    {
        case 1:
            linearSearch(array, size, element);
            break;
        case 2:
            // binarySearch(array, size);
            break;
    }        
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
    int element;
    cout << "\nEnter the element to be searched: \n";
    cin >> element;
    searchType(userArray, size, element);
}