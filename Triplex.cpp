#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Player will read this as first statement
    std::cout << "You are 007 breaking into NASA's Servers...Level " << Difficulty;
    std::cout << " \nYou need to enter the correct codes to continue...\n";
}

bool PlayGame(int Difficulty)

{
    PrintIntroduction(Difficulty);
    //Declaring 3 Number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Printing CodeSum and Product to Terminal
    std::cout << "\n+There are 3 numbers in the code";
    std::cout << "\n+The codes add up to: " << CodeSum;
    std::cout << "\n+The codes multiply to: " << CodeProduct;
    std::cout << std::endl;

    //Stores Players Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    //Check if players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
       std::cout << "\nCongratz Big Brain you won!\n\n";
       std::cout << "\nGreat job Mr.Bond. Keep going we need the files the world depends on it!\n\n";
       return true;
       
    }
    else
    {
        std::cout << "Try again! We need those files Bond!\n";
        return false;
    }        
} 

int main() 
{   
    srand(time(NULL)); //Creates new random sequence based on time of day
    
    int LevelDifficulty = 1;
    int const MaxLevel = 5;
    
    while (LevelDifficulty <= MaxLevel) //Loops Game Until Your Reach Max Level
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)  
        {
            ++LevelDifficulty;
        }
    }
        std::cout << "Amazing work Mr Bond now get out of there before the place blows!";
        return 0;
}