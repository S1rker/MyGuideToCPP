#include <iostream>

class calculator
{
    float firstnum;
    float secnum;
    float result;

    public:
        int addtion()
        {
            result = firstnum + secnum;
            return 0;
        }

        int subtraction()
        {
            result = firstnum - secnum;
            return 0;
        }
        int mulitplcation()
        {
            result = firstnum * secnum;
            return 0;
        }
        int division()
        {
            result = firstnum / secnum;
            return 0;
        }
        int module()
        {
            result = static_cast<int>(firstnum) % static_cast<int>(secnum);
            return 0;
        }
        int start()
        {
            int option;
            int x;
            int y;
            int temp;
            int temp2;
            std::cout << "please select a add(1), sub(2), multiply(3), divide(4) module(5): "; 
            std::cin >> option;
            switch (option)
            {
            case 1:
                std::cout << "first number to add"; std::cin >> firstnum;
                std::cout << "secound number to add"; std::cin >> secnum;
                addtion();
                std::cout << result;
                break;
            
            case 2:
                std::cout << "first number to sub"; std::cin >> firstnum;
                std::cout << "secound number to sub"; std::cin >> secnum;
                subtraction();
                std::cout << result;
                break;
                
            case 3:
                std::cout << "first number to mulitply"; std::cin >> firstnum;
                std::cout << "secound number to mulitply"; std::cin >> secnum;
                subtraction();
                std::cout << result;
                break;
            
            case 4:
                std::cout << "first number to divide"; std::cin >> firstnum;
                std::cout << "secound number to divide"; std::cin >> secnum;
                subtraction();
                std::cout << result;
                break;

            case 5:
                std::cout << "first number to module"; std::cin >> firstnum;
                std::cout << "secound number to module"; std::cin >> secnum;

                x = firstnum;
                y = secnum;

                temp = firstnum - x;
                temp2 = secnum - y;
                
                while (temp > 0 && temp2 > 0)
                {
                    std::cout << "first number to module"; std::cin >> firstnum;
                    std::cout << "secound number to module"; std::cin >> secnum;
                }
                module();
                std::cout << result;

            default:
                break;


            }
        return 0;
        }
};



int main()
{
    return 0;
}
