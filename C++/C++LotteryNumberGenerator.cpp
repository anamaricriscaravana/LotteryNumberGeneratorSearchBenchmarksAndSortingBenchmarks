/**********************************
Caravana, Ana Maricris A.
BSCpE 1-1

VI - IX - Programming Exercises
    C++
    1. Lottery Number Generator
**********************************/

#include <iostream>
using namespace std;

int main() 
{
    srand(time(NULL));
    int lotteryNumbers[7];

    for (int i = 0; i < 7; i++) 
    {
        lotteryNumbers[i] = rand() % 10;
    }

    cout << " " << endl;
    cout << "Lottery numbers: ";
    cout << " " << endl;
    for (int i = 0; i < 7; i++) 
    {
        cout << lotteryNumbers[i] << " ";
    }
    cout << " " << endl;
    cout << endl;

    return 0;
}