/******************
* Julia Mann      *
* CS50            *
* PSET1           *
* Greedy Project  *
******************/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

    //***** round function example *****//
        // float x = 5.49;
        // float y = round(x);
        // printf("%.10f\n", y); = 5.00
        // printf("%.10f\n", x); = 5.48999999

int main(void)
{
    // ask user for amount of change
    printf("Hello. How much change do I own you?\n");
    float change = GetFloat();
    
    // check to make sure positive number
    while (change <= 0)
    {
        printf("That is not a valid amount. How much change is owed?\n");
        change = GetFloat();
    }
     
    // round function and change from dollar amount to all cents amount
    // float round = roundf(change);
    int cents = change * 100;
    
    // printf("I owe you %.2f much in float change.\n", round);
    // printf("I owe you %.2d cents in int cents.\n", cents);
    
    int coins = 0;
    while (cents >= 25)
    {    
        coins++;
        cents = cents - 25;
    }
    while (cents >= 10)
    {
        coins++;
        cents = cents - 10;
    }
    while (cents >= 5)
    {
        coins++;
        cents = cents - 5;
    }
    while (cents > 0)
    {
        coins++;
        cents = cents -1;
    }
    printf("I used %d coins.\n", coins);
}
