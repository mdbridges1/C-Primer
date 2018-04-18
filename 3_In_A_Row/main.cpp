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
void GenerateAndDisplayRandomNumber();
void DisplayRandomNumber();
bool GameIsWon();
void DisplayOddNumberArray();
void IsOddNumber();

//Global variables are bad practice- return from functions?

int oddNumberArray[3]; // consider list or un ordered set
int countOddNumbers = 0;
int randomNumber;

int timeBetweenNumbers = 200; //time in ms

int main()
    {
        DisplayGameRules();
        
        GenerateAndDisplayRandomNumber();
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

void GenerateAndDisplayRandomNumber()
{
    auto systemTimeInSeconds = (int)time(0);
    srand(systemTimeInSeconds); // set random seed
    
    do
    {
        randomNumber =(rand() %10 + 1);
        std::cout << randomNumber;
        DisplayRandomNumber();
        std::cout << "Number of odd numbers so far: " << countOddNumbers << std::endl << std::endl;
    }
    while(countOddNumbers < 3);
    return;
}

void DisplayRandomNumber() {
    
    // is the number odd?
    
    if(randomNumber % 2 != 0)
    {
        //std::cout << " odd";
        //oddNumberArray[0] = randomNumber;
        //std::cout << std::endl;
        oddNumberArray[countOddNumbers] = randomNumber;
        countOddNumbers ++;
        Sleep(timeBetweenNumbers);
        
    }
    else
    {
        //std::cout << " even";
        Sleep(timeBetweenNumbers);
        countOddNumbers = 0;
    }
}

void DisplayOddNumberArray()
{
    std::cout << "The odd numbers were: " << oddNumberArray [0] << ", " << oddNumberArray [1] << " and " << oddNumberArray [2] << std::endl;
}
