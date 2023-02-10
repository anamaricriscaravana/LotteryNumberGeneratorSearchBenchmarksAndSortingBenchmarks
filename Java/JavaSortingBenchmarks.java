/***********************************
Caravana, Ana Maricris A.
BSCpE 1-1

VI - IX - Programming Exercises
    Java
    3. Sorting Benchmarks
**********************************/

import java.util.Random;

public class JavaSortingBenchmarks 
{
    public static void main(String[] args) 
    {
        Random randomNumbers = new Random();
        
        int[] numbers = new int[20];
        for (int i = 0; i < 20; i++) numbers[i] = randomNumbers.nextInt(100);
        System.out.println(" ");
        System.out.print("Benchmark Array: ");
        for (int i = 0; i < 20; i++) System.out.print(numbers[i] + " ");
        System.out.println();

        int[] bubbleSortArray = numbers.clone();
        int bubbleSwapCount = bubbleSortSwapCount(bubbleSortArray);
        int[] selectionSortArray = numbers.clone();
        int selectionSwapCount = selectionSortSwapCount(selectionSortArray);
        int[] insertionSortArray = numbers.clone();
        int insertionSwapCount = insertionSortSwapCount(insertionSortArray);

        
        System.out.println(" ");
        System.out.println("Bubble Sort swap count: " + bubbleSwapCount);
        System.out.println(" ");
        System.out.println("Selection Sort swap count: " + selectionSwapCount);
        System.out.println(" ");
        System.out.println("Insertion Sort swap count: " + insertionSwapCount);
        System.out.println(" ");

    }
    public static int bubbleSortSwapCount(int[] numbers) 
    {
        int swapCount = 0;
        int maxComponent, index, temp;
        for (maxComponent = numbers.length -1; maxComponent >= 0; maxComponent--) 
        {
            for (index = 0; index <= maxComponent -1; index++) 
            {
                if (numbers[index] > numbers[index +1]) 
                {
                    temp = numbers[index];
                    numbers[index] = numbers[index +1];
                    numbers[index +1] = temp;
                    swapCount++;
                }
            }
        }
        return swapCount;
    }
    public static int selectionSortSwapCount(int[] numbers) 
    {
        int swapCount = 0;
        int startScan, index, minIndex, minValue;
        for (startScan = 0; startScan < (numbers.length -1); startScan++) 
        {
            minIndex = startScan;
            minValue = numbers[startScan];
            for (index = startScan +1; index < numbers.length; index++) 
            {
                if (numbers[index] < minValue) {
                    minValue = numbers[index];
                    minIndex = index;
                }
            }
        if (startScan != minIndex) 
        {
            numbers[minIndex] = numbers[startScan];
            numbers[startScan] = minValue;
            swapCount++;
        }
        }
        return swapCount;
    }
    public static int insertionSortSwapCount(int[] numbers) 
    {
        int swapCount = 0;
        int unsortedValue, scan;
        for (int index = 1; index < numbers.length; index++) 
        {
            unsortedValue = numbers[index];
            scan = index;
            while (scan > 0 && numbers[scan-1] > unsortedValue) 
            {
                numbers[scan] = numbers[scan -1];
                scan--;
                swapCount++;
            }
        numbers[scan] = unsortedValue;
        }
        return swapCount;
    }
}