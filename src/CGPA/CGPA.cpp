#include <iostream>

float CGPA(float scores[4], int credits[4])
{
    int sum_credits = credits[0] + credits[1] + credits[2] + credits[3];

    float quality_credits[4];

    for (int i = 0; i < 4; i++){
        quality_credits[i] = scores[i] * credits[i];
    }
    float total_quality_credits = quality_credits[0] + quality_credits[1] + quality_credits[2] + quality_credits[3];

    float total = total_quality_credits / sum_credits;

    return total;
}

int main()
{
    float class_Scores[4];
    int credits_taken[4];

    std::cout << "type the final grades for 4 classes and number of credits taken for each class. \n";
    for (int i = 0; i < 4; i++) {
        std::cout << "class score: "; std::cin  >> class_Scores[i];
        std::cout << "credits taken: "; std::cin  >> credits_taken[i];
    }

    float result = CGPA(class_Scores, credits_taken);

    printf("%f", result);

}