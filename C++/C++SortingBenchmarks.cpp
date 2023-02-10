/***********************************
Caravana, Ana Maricris A.
BSCpE 1-1

VI - IX - Programming Exercises
    C++
    3. Sorting Benchmarks
**********************************/

#include <iostream>
#include <ctime>
using namespace std;

void swap(int &a, int &b);
int bubbleSortSwapCount(int *bubbleSortArray);
int selectionSortSwapCount(int *selectionSortArray);
int insertionSortSwapCount(int *insertionSortArray);

int main() 
{
    srand(time(0));
    int SIZE = 20;
    int bubbleSortArray[SIZE], selectionSortArray[SIZE], insertionSortArray[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        bubbleSortArray[i] = rand() % 100;
        selectionSortArray[i] = bubbleSortArray[i];
        insertionSortArray[i] = bubbleSortArray[i];
    }
    cout << " " << endl; 
    cout << "Benchmark Array: ";
    for (int i = 0; i < 20; i++)
        cout << bubbleSortArray[i] << " ";
    cout << endl;
    
    cout << " " << endl; 
    int bubbleSwaps = bubbleSortSwapCount(bubbleSortArray);
    cout << "Bubble Sort swap count: " << bubbleSwaps << endl;
    
    cout << " " << endl; 
    int selectionSwaps = selectionSortSwapCount(selectionSortArray);
    cout << "Selection Sort swap count: " << selectionSwaps << endl;
    
    cout << " " << endl; 
    int insertionSwaps = insertionSortSwapCount(insertionSortArray);
    cout << "Insertion Sort swap count: " << insertionSwaps << endl;
    cout << " " << endl; 

    return 0;
}
void swap(int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}
int bubbleSortSwapCount(int *bubbleSortArray) 
{
    int swapCount = 0;
    int maxElement, index, temp;
    for (maxElement = 20-1; maxElement >= 0; maxElement--) {
        for (index = 0; index <= maxElement -1; index++) {
            if (bubbleSortArray[index] > bubbleSortArray[index +1]) 
            {
                temp = bubbleSortArray[index];
                bubbleSortArray[index] = bubbleSortArray[index +1];
                bubbleSortArray[index +1] = temp;
                swapCount++;
            }
        }
    }
    return swapCount;
}
int selectionSortSwapCount(int *selectionSortArray) 
{
    int swapCount = 0;
    int startScan, index, minIndex, minValue;
    for (startScan = 0; startScan < (20-1); startScan++) 
    {
        minIndex = startScan;
        minValue = selectionSortArray[startScan];
        for (index = startScan+1; index < 20; index++) 
        {
            if (selectionSortArray[index] < minValue) 
            {
                minValue = selectionSortArray[index];
                minIndex = index;
            }
        }
        if (minIndex != startScan) {
            swap(selectionSortArray[minIndex], selectionSortArray[startScan]);
            swapCount++;
        }
    }
    return swapCount;
}
int insertionSortSwapCount(int *insertionSortArray) 
{
    int swapCount = 0;
    int unsortedValue, scan;
    for (int index = 1; index < 20; index++) 
    {
        unsortedValue = insertionSortArray[index];
        scan = index;
        while (scan > 0 && insertionSortArray[scan-1] > unsortedValue) 
        {
            insertionSortArray[scan] = insertionSortArray[scan-1];
            scan--;
            swapCount++;
        }
        insertionSortArray[scan] = unsortedValue;
    }
    return swapCount;
}