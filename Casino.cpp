#include <iostream>
#include <cstdlib>
#include <ctime>

class casino
{
    
    int comp_num;
    int player_num;
    int reward;
    int diffculty;

public: 

	int randnum()
    {
        
        switch(diffculty){
            case 1: //easy
                srand(time(0));
                comp_num = rand() % 11;
                reward = 1; //least reward
                break;
            case 2: // medium
                srand(time(0));
                comp_num = rand() % 51;
                reward = 2; // medium reward
                break;
            case 3: //hard
                srand(time(0));
                comp_num = rand() % 101;
                reward = 3; //most reward
                break;
        }
        return 0;
    }


    int numguessed()
    {   

        std::cout << "please select a diffculty(1-3): "; std::cin >> diffculty;
        switch(diffculty){
            case 1: //easy
                std::cout << "please guess a number 0 - 10: "; std::cin >> player_num;
                break;
            case 2: // medium
                std::cout << "please guess a number 0 - 50: "; std::cin >> player_num;
                break;
            case 3: //hard
                std::cout << "please guess a number 0 - 100: "; std::cin >> player_num;
                break;

        }
        return 0;
    }



    int game()
    {
        numguessed();
        randnum();

        if (comp_num == player_num)
        {
            switch (reward)
            {
            case 1:
                std::cout << "you win here your reward $10";
                break;
            case 2:
                std::cout << "you win here your reward $50";
                break;
            case 3:
                std::cout << "you win here your reward $100";
                break; 
            default:
                break;
            }
        }
        else{
            std::cout << "you lost \n";
        }
        return 0;
    }
};


int main()
{  
    casino myobj;
    int choice;
    bool notdone = true;

    while (notdone){
        myobj.game();

        std::cout << "are you done true(1) or false(0)): "; std:: cin >> choice;
        
        switch (choice)
        {
        case 1:
            notdone = true;
            break;
        case 2:
            notdone = false;
            break;
        default:
            exit(0);
        }
    }
    return 0;
}