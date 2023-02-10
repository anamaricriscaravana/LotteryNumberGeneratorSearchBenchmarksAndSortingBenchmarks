#Caravana, Ana Maricris A.
#BSCpE 1-1

#VI - IX - Programming Exercises
#   Python
#   1. Lottery Number Generator

import random

def main():
    lotteryNumbers = [random.randint(0, 9) for i in range(7)]
    print (" ")
    print("Lottery numbers:") 
    print (" ")
    print (*lotteryNumbers)
    print (" ")
main()