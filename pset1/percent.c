/*****************
* Julia Mann
* CS50
* PSET 1
* Percent project
******************/

# include <stdio.h>
# include <cs50.h>

int main(void)
{
    // ask user for non-negative numerator; check if valid 
    printf("Hello! I need a non-negative numerator:\n");
    float numerator = GetInt();
    
    while (numerator < 0)
    {
        printf("That's not a non-negtive numerator! Try again:\n");
        numerator = GetInt();
    }
    
    // ask user for a positive denominator; check if valid
    printf("Great, thanks! Now I need a positive denominator:\n");
    float denominator = GetInt();
    
    while (denominator <= 0)
    {
        printf("That's not a positive denominator! Please try again:\n");
        denominator = GetInt();
    }
    
    // display fraction as percentage
    float total = ((numerator / denominator)*100);
    printf("Thanks, your percentage is %.2f%%.\n", total); 
}
