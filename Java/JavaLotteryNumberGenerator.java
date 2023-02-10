/***********************************
Caravana, Ana Maricris A.
BSCpE 1-1

VI - IX - Programming Exercises
    Java
    1. Lottery Number Generator
**********************************/

import java.util.Random;

public class JavaLotteryNumberGenerator
{
    public static void main(String[] args) 
    {
        int[] lotteryNumbers = new int[7];
        Random randomNumbers = new Random();
        
        for (int i = 0; i < 7; i++)
        {
            lotteryNumbers[i] = randomNumbers.nextInt(10);
        } 

        System.out.println("Lottery Numbers: ");
        System.out.print(" ");
        for (int i = 0; i < 7; i++)
        {
            System.out.print(lotteryNumbers[i] + " ");
        }
    }
}