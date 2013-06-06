/*************************
* Julia Mann
* CS50
* temp converter project
* 5/13/13
**************************/

#include <stdio.h>
#include <cs50.h>

float convert_to_c(float temp)
{
    // convert temp from f to c
    float c = (((temp - 32)*5)/9);
    return c;
}

float convert_to_f(float temp)
{
    // convert temp from c to f
    float f = (((temp * 9)/5)+32);
    return f;
}

int main(void)
{
    // ask user for temp in f
    printf("What is the temperature in Fahrenheit? \n");
    int d = GetInt();
    
    // use function and reply to user with the temp
    float penis = convert_to_c(d);
    printf("That's %.1f degrees in Celsius. \n", penis);
}



