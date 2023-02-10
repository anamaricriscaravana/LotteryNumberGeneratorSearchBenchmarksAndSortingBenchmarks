#Caravana, Ana Maricris A.
#BSCpE 1-1

#VI - IX - Programming Exercises
#   Python
#   2. Search Benchmarks

import random

def main():
    numbers = [random.randint(0, 100) for i in range(20)]
    print (" ")
    print("Benchmark Array:", *numbers)

    targetIndex = random.randint(0, len(numbers))
    targetValue = numbers[targetIndex]
    
    sequentialComparisons = sequentialSearch(numbers, targetValue)
    binaryComparisons = binarySearch(numbers, targetValue)
    
    print (" ")
    print("Target Value:", targetValue)
    print (" ")
    print("Sequential Search Algorithm Comparisons: ", sequentialComparisons)
    print (" ")
    print("Binary Search Algorithm Comparisons: ", binaryComparisons)
    print (" ")

def sequentialSearch(numbers, targetValue):
    comparisons = -1
    for i in numbers:
        comparisons += 1
        if i == targetValue:
            return comparisons
    return comparisons

def binarySearch(numbers, targetValue):
    comparisons = -1
    first = 0 
    last = len(numbers) - 1
    found = False
    while not found and first <= last:
        middle = (first + last) // 2
        comparisons += 1
        if numbers[middle] == targetValue:
            found = True
            comparisons = middle
        elif numbers[middle] > targetValue:
            last = middle - 1
        else: first = middle + 1
    return comparisons

main()