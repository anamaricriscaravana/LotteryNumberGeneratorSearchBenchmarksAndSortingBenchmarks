/***********************************
Caravana, Ana Maricris A.
BSCpE 1-1

VI - IX - Programming Exercises
    C++
    2. Search Benchmarks
**********************************/

#include <iostream>
#include <ctime>
using namespace std;

int sequentialSearch(int *numbers, int targetValue);
int binarySearch(int *numbers, int targetValue);

int main() 
{
    srand(time(0));

    int numbers[20];
    for (int i = 0; i < 20; i++) numbers[i] = rand() % 100;
    cout << " " << endl;
    cout << "Benchmark Array: ";
    for (int i = 0; i < 20; i++) cout << numbers[i] << " ";
    
    int targetIndex = rand() % 20;
    int targetValue = numbers[targetIndex];
    
    int sequentialComparisons = sequentialSearch(numbers, targetValue);
    int binaryComparisons = binarySearch(numbers, targetValue);
    
    cout << endl;
    cout << " " << endl;
    cout << "Target Value: " << targetValue << endl;
    cout << " " << endl;
    cout << "Sequential Search Algorithm Comparisons: " << sequentialComparisons << endl;
    cout << " " << endl;
    cout << "Binary Search Algorithm Comparisons: " << binaryComparisons << endl;
    cout << " " << endl;

    return 0;
}

int sequentialSearch(int *numbers, int targetValue) 
{
    int comparisons = -1;
    for (int i = 0; i < 20; i++) 
    {
        comparisons++;
        if (numbers[i] == targetValue) return comparisons;
    }
    return comparisons;
}

int binarySearch(int *numbers, int targetValue) 
{
    int comparisons = -1;
    int first = 0;
    int last = 19;
    bool found = false;
    while (!found && first <= last) 
    {
        int middle = (first + last) / 2;
        comparisons++;
        if (numbers[middle] == targetValue)
        {
            found = true;
            comparisons = middle;
        } else if (numbers[middle] > targetValue) 
        {
            last = middle - 1;
        } else 
        {
            first = middle + 1;
        }
    }
    return comparisons;
}