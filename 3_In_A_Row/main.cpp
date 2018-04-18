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
void GenerateRandomNumber();
bool GameIsWon();

int main()
    {
        DisplayGameRules();
        GenerateRandomNumber();
        // If 3 in a row are odd, start timer- continue random numbers store 3 in a row values
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
    << "Press enter to start the game\n\n";;
}

void GenerateRandomNumber()
{
    auto systemTimeInSeconds = (int)time(0); // Do we use auto now??
    srand(systemTimeInSeconds); // set random seed
    
    do
    {
        std::cout << (rand() %100 +1 )<< std::endl;
        Sleep(1000);
    }
    while(true);
    //while (!GameIsWon());
}
