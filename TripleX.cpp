#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    /* Letters in terminal */ 
    std::cout << "\n\nYou're a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number
    const int CodeA = rand();
    const int CodeB = rand();
    const int CodeC = rand();

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Sum and product in terminal 
    std::cout << "There're 3 numbers in the code:\n";
    std::cout << "-The codes add-up to: " << CodeSum << std::endl;
    std::cout << "-The codes mutliply to give : " << CodeProduct << std::endl;

    // Store Player Guess
    int GuessA, GuessB, GuessC; 
    std::cin >> GuessA >> GuessB >> GuessC;
    
    
     // Sum and Product to enter
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Win
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You completed this stage. Keep going.\n";
        std::cout << std::endl;
        return true;
        
    }
    // Lose
    else 
    {
        std::cout << "You're an idiot! Try again to find true answer.\n";
        std::cout << std::endl;
        return false;
        
    }
    
}
int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty) // Loop the game until all levels completed
    {
        std::cout << rand() << "\n";
        bool bLevelComplete = PlayGame(LevelDifficulty); 
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
             ++LevelDifficulty;
         }
        
    }
    std::cout << "\nYou completed all of the levels! Now get the fuck of there!";
    return 0;
}
