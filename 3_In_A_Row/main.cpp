//  3_In_A_Row
//
//  Created by Michael Bridges on 18/04/2018.
//  Copyright © 2018 Michael Bridges. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

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

//Global variables are bad practice - return from functions?
const int arraySize = 3;
int oddNumberArray[arraySize]; // consider list or un ordered set
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
    std::cout   << "Welcome to " << arraySize << " In A Row\n"
    << "A series of random numbers will now be shown\n"
    << "When you see " << arraySize << " UNIQUE odd numbers in a row, press Enter\n"
    << "Be quick, I'm timing you\n\n"
    << "Press ENTER to start the game\n\n";;
    std::cin.ignore(); // Waits for uder to press enter
}

void PlayGame()
{
    do
    {
        randomNumber =(rand() %arraySize
                       
                       + 1);
        std::cout << randomNumber << std::endl;
        PopulateArray();
    }
    while(countOddNumbers < arraySize);
    SortArrayElements();
    AreArrayElementsUnique();
    //DisplayOddNumberArray();
    
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
        std::cout << "NOT UNIQUE";
        PlayGame();
    }
    else
    {
        std::cout << "UNIQUE" ; // if all numbers in the array are unique
        
        
        //StartTimer();
        PlayGame();
    }
    
    //else trigger timer
}

void StartTimer()
{
    return;
}

void DisplayOddNumberArray()
{
    std::cout << "The odd numbers were: " << oddNumberArray [0] << ", " << oddNumberArray [1] << " and " << oddNumberArray [2] << std::endl;
}
