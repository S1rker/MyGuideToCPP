#include <iostream>
#include <cstdlib>
#include <ctime>
//rock = 1, paper = 2, scissor = 3

int RPS(int py_choice)
{  
    srand(time(0));
    int cp_choice = rand() % 4;
    /*
    if 1 is chosen then 1(ties) 2(wins) 3(loses)
    if 2 is chosen then 1(wins) 2(ties) 3(loses)
    if 3 is chosen then 1(loses) 2(wins) 3(ties)
    */
    int tie = 1;
    int win = 2;
    int lose = 3;
    if (py_choice == cp_choice) {
        return tie; // tie
    }
    // Rock beats Scissors, Paper beats Rock, Scissors beats Paper
    if ((py_choice == 1 && cp_choice == 3) ||
        (py_choice == 2 && cp_choice == 1) ||
        (py_choice == 3 && cp_choice == 2)) {
        return win; // win
    }
    return lose; // lose

}


bool vaild(int choice, int options[3])
{
    for (int i = 0; i < 3; i += 1)
    {
        if (choice == options[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{   
    int tie = 1;
    int win = 2;
    int lose = 3;

    int options[3] = {1,2,3};
    int choice;

    bool notdone = true;
    while (notdone){
        std::cout << "Choice Rock(1), Paper(2), or scissor(3): "; std::cin >> choice;
        while (vaild(choice, options))
        {
            std::cout << "Please choice Rock(1), Paper(2), or scissor(3): "; std::cin >> choice;
        }
        int outcome = RPS(choice);

        if (outcome == tie){
            std::cout << "Tied \n";
        }
        else if (outcome == win){
            std::cout << "Won \n";
        }
        else if (outcome == lose){
            std::cout << "Lost \n";
        }
        std::cout << "are you done true(1) or false(0)): "; std:: cin >> notdone;
    }   

}