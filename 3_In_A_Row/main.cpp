//  3_In_A_Row
//
//  Created by Michael Bridges on 18/04/2018.
//  Copyright © 2018 Michael Bridges. All rights reserved.
//

#include <iostream>

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
    
    do
    {
    std::cout << (rand() %100 +1 ) << std::endl; // notice it is the same random number everytime and lots of them!
    }
    while(true);
    //while (!GameIsWon());
}
