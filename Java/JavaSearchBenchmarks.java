/***********************************
Caravana, Ana Maricris A.
BSCpE 1-1

VI - IX - Programming Exercises
    Java
    2. Search Benchmarks
**********************************/

import java.util.Random;

public class JavaSearchBenchmarks 
{
    public static void main(String[] args) 
    {
        Random randomNumbers = new Random();
        
        int[] numbers = getNumbers(randomNumbers);
        System.out.println(" ");
        System.out.print("Benchmark Array: ");
        for (int i = 0; i < 20; i++) 
        {
            System.out.print(numbers[i] + " ");
        }
        System.out.println(" ");

        int index = randomNumbers.nextInt(numbers.length);
        int targetValue = numbers[index];
        
        int sequentialComparisons = sequentialSearch(numbers, targetValue);
        int binaryComparisons = binarySearch(numbers, targetValue);
        System.out.println(" ");
        System.out.println("Target Value: " + targetValue);
        System.out.println(" ");
        System.out.println("Sequential Search Algorithm Comparisons: " + sequentialComparisons);
        System.out.println(" ");
        System.out.println("Binary Search Algorithm Comparisons: " + binaryComparisons);
        System.out.println(" ");
    }
    public static int[] getNumbers(Random randomNumbers) 
    {
        int[] numbers = new int[20];
        for (int i = 0; i < 20; i++) 
        {
            numbers [i] = randomNumbers.nextInt(100);
        }
        
        return numbers;
    }
    public static int sequentialSearch(int[] numbers, int targetValue) 
    {
        int comparisons = -1;
        for (int i = 0; i < numbers.length; i++) 
        {
            comparisons++;
            if (numbers[i] == targetValue) return comparisons;
        }
        return comparisons;
    }
    public static int binarySearch(int[] numbers, int targetValue) 
    {
        int comparisons = -1;
        int first = 0;
        int last = numbers.length - 1;
        boolean found = false;
        
        while (!found && first <= last) 
        {
            int middle = (first + last) / 2;
            comparisons++;
            if (numbers[middle] == targetValue) 
            {
                found = true;
                comparisons = middle;
            } else if (numbers [middle] < targetValue) 
            {
                first = middle + 1;
            } else 
            {
                last = middle - 1;
            }
        }
        return comparisons;
    }
}