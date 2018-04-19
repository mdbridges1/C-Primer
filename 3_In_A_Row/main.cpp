//  3_In_A_Row
//
//  Created by Michael Bridges on 18/04/2018.
//  Copyright © 2018 Michael Bridges. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

void DisplayGameRules();
void SetRandomSeed();
void DisplayRandomNumber();
void AreArrayElementsUnique();
void DisplayOddNumberArray();
void IsOddNumber();

//Global variables are bad practice- return from functions?
const int arraySize = 3;
int oddNumberArray[arraySize]; // consider list or un ordered set
int countOddNumbers = 0;
int randomNumber;

int timeBetweenNumbers = 10; //time in ms

int main()
    {
        DisplayGameRules();
        SetRandomSeed();
        do
        {
            randomNumber =(rand() %100 + 1);
            std::cout << randomNumber << std::endl;
            DisplayRandomNumber();
        }
        while(countOddNumbers < arraySize);
        AreArrayElementsUnique();
        DisplayOddNumberArray();
        
        
        // TODO odd needs to be unique
        // When user presses enter - display win or lose
        // Lose Screen - Show reason for losing - Play Again?
        // Win Screen - Play again
        // Quit
    return 0;
    }

void DisplayGameRules()
{
    std::cout   << "Welcome to 3 In A Row\n"
    << "A series of random numbers will now be shown\n"
    << "When you nseen 3 odd numbers in a row, press Enter\n"
    << "Be quick, I'm timing you\n\n"
    << "Press ENTER to start the game\n\n";;
    std::cin.ignore()
    ;
}

void SetRandomSeed()
{
    auto systemTimeInSeconds = (int)time(0);
    srand(systemTimeInSeconds); // set random seed
    return;
}

void DisplayRandomNumber() {
    
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

void AreArrayElementsUnique()
{
    std::sort( oddNumberArray, oddNumberArray + arraySize);
}

void DisplayOddNumberArray()
{
    std::cout << "The odd numbers were: " << oddNumberArray [0] << ", " << oddNumberArray [1] << " and " << oddNumberArray [2] << std::endl;
}
