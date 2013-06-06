/*****************
* Julia Mann     *
* CS50           *
* PSET 1         *
* Mario Project  *
******************/

# include <stdio.h>
# include <cs50.h>

int main(void)
{
    // ask user for pyramid height; check number
    printf("How tall, by number of blocks, do you want your pyramid to be?\n");
    int blocks = GetInt();
    
    while ((blocks <= 0) || (blocks > 23))
    {
        printf("That number won't work! Please pick a number greater than 0 and smaller than 24:\n");;
        blocks = GetInt();
    }
    
    // print pyramid
    printf("Your pyramid looks like:\n");
    int i;
    int total_pyramid = blocks + 1;
    for (i = 2; i <= total_pyramid; i++)
    {
        int space = total_pyramid - i;
        while (space > 0)
        {
            printf(" ");
            space--;
        }
        int hashtag = i;
        while (hashtag > 0)
        {
            printf("#");
            hashtag--;
        }
        printf("\n");
    }
}
