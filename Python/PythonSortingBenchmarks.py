#Caravana, Ana Maricris A.
#BSCpE 1-1

#VI - IX - Programming Exercises
#   Python
#   3. Sorting Benchmarks

import random

def main():    
    numbers = [random.randint(0, 100) for i in range(20)]
    print (" ")
    print("Benchmark Array: ", *numbers)

    bubbleSwap = bubbleSortSwapCount(numbers.copy())
    selectionSwap = selectionSortSwapCount(numbers.copy())
    insertionSwap = insertionSortSwapCount(numbers.copy())

    print(" ")
    print("Bubble Sort swap count: " + str(bubbleSwap))
    print(" ")
    print("Selection Sort swap count: " + str(selectionSwap))
    print(" ")
    print("Insertion Sort swap count: " + str(insertionSwap))

def bubbleSortSwapCount(numbers):
    swapCount = 0
    maxElement = len(numbers)-1
    while maxElement >= 0:
        index = 0
        while index <= maxElement-1:
            if numbers[index] > numbers[index+1]:
                temp = numbers[index]
                numbers[index] = numbers[index+1]
                numbers[index+1] = temp
                swapCount += 1
            index += 1
        maxElement -= 1
    return swapCount

def selectionSortSwapCount(numbers):
    swapCount = 0
    for i in range(len(numbers) - 1):
        minIndex = i
        for j in range(i + 1, len(numbers)):
            if numbers[j] < numbers[minIndex]:
                minIndex = j
        if i != minIndex:
            numbers[i], numbers[minIndex] = numbers[minIndex], numbers[i]
            swapCount += 1
    return swapCount

def insertionSortSwapCount(numbers):
    swapCount = 0
    index = 1
    while index < len(numbers):
        unsortedValue = numbers[index]
        scan = index
        while scan > 0 and numbers[scan-1] > unsortedValue:
            numbers[scan] = numbers[scan-1]
            swapCount += 1
            scan -= 1
        if scan != index:
            numbers [scan]= unsortedValue
        index += 1
    return swapCount

main()