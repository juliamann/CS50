#include <stdio.h>
#include <cs50.h>

int fact(int input_number)
{
    int num1, num2;
    
    num1 = 1;
    for (num2 = 2; num2<=input_number; num2++)
        num1 = num1 * num2;
    return num1;
}

int main()
{
    printf("Give me an integer: ");
    int user_number = GetInt();
    printf("The factorial of %d is %d.\n", user_number, fact(user_number));
    
}


