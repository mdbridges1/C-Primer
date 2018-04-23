//  3_In_A_Row
//
//  Created by Michael Bridges on 18/04/2018.
//  Copyright © 2018 Michael Bridges. All rights reserved.
//

#include <iostream>
#include <cstdlib> // use std:rand instead
#include <chrono> // for timer display
typedef std::chrono::high_resolution_clock Clock;

// Instead of ifdef, implement:  std::this_thread::sleep_for()
#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

void DisplayGameRules();
void PlayGame();
void SetRandomSeed();
void PopulateArray();
void SortArrayElements();
void AreArrayElementsUnique();
void DisplayOddNumberArray();
void IsOddNumber();
void StartTimer();

//TODO Remove Global variables are bad practice - return from functions? - Pass things around NOT global!!
// Global is lazy and with catchup with you later on.
const int arraySize = 3;
int oddNumberArray[arraySize]; // consider list or un ordered set --std::vectors variable length array
int countOddNumbers = 0;
int randomNumber;

int timeBetweenNumbers = 100; //time in ms

int main()
    {
        DisplayGameRules();
        SetRandomSeed();
        PlayGame();
        
    return 0;
    }

void DisplayGameRules()
{
    //SAM: Is this style OK, if not why not, what is prefered?
    std::cout   << "Welcome to " << arraySize << " In A Row\n" //TODO replace \n with endl for consistency
                << "A series of random numbers will now be shown\n"
                << "When you see " << arraySize << " UNIQUE odd numbers in a row, press Enter\n"
                << "Be quick, I'm timing you\n\n"
                << "Press ENTER to start the game\n\n";
    std::cin.ignore(); // Waits for user to press enter, TODO, Are you ready? in do while loop waiting for Y/N input  cin getline
}

void PlayGame()
{
    do
    {
        randomNumber =(rand() %9 +1);   //std:random_device?  // std::mt19937  ?  Options options  uniformly distribution required
        std::cout << randomNumber << std::endl;
        PopulateArray();
    }
    while(countOddNumbers < arraySize);
    SortArrayElements(); //Functions are factions, give them input, make some output.
    AreArrayElementsUnique();
    DisplayOddNumberArray();
    
    // TODO odd needs to be unique
    // When user presses enter - display win or lose
    // Lose Screen - Show reason for losing - Play Again?
    // Win Screen - Play again
    // Quit
}

void SetRandomSeed()
{
    auto systemTimeInSeconds = (int)time(0);
    srand(systemTimeInSeconds); // set random seed
    return;
}

void PopulateArray() {
    
    // is the number odd?
    
    if(randomNumber % 2 != 0)
    {
        oddNumberArray[countOddNumbers] = randomNumber;
        countOddNumbers ++;
        Sleep(timeBetweenNumbers);
        }
    else
    {
        Sleep(timeBetweenNumbers);
        countOddNumbers = 0;
    }
}

void SortArrayElements()
{
    std::sort( oddNumberArray, oddNumberArray + arraySize);
}

void AreArrayElementsUnique()
{
    int origVal = 0, compVal = 0, a, b;
    
    for(a = 0 ; a < arraySize ; a++)//starting point in array
    {
        origVal = oddNumberArray[a];
        
        for (b = a+ 1 ; b < arraySize ; b++) //step through array any two consecutive numbers same?
        {
            if(origVal == oddNumberArray[b])
            {
                compVal = 1; // If number are the same, assign a value of 1 to the compVal
            }
        }
    }
    if (compVal == 1) // If compVal is 1 , then continue the game.
    {
        std::cout << "NOTUNIQUE";
        PlayGame();
    }
    else
    {
        std::cout << "UNIQUE" ; // if all numbers in the array are unique
        
        
        //StartTimer();
        PlayGame();
    }
    
}

void StartTimer()
{
    
    auto tStart = Clock::now();  //std duration<float>  duration<cast>
    auto tEnd = Clock::now();
    //asana
    //std::out << std::chrono::duration_cast<<#class _ToDuration#>>(<#const duration<_Rep, _Period> &__fd#>) // Need to work this out
    return;   // what happen when you don't return from a function, but the code still runs anyway, what is it assuming?
}

void DisplayOddNumberArray()
{
    std::cout << "The odd numbers were: " << oddNumberArray [0] << ", " << oddNumberArray [1] << " and " << oddNumberArray [2] << std::endl;
}
