#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //ask user for text
    printf("Enter some text: \n");
    string text = GetString();
    
    //change text to half caps
    int i;
    for (i = 0; i < strlen(text); i += 2)
    {
        int ascii = text[i];
        char uppercase_letter;
        if (ascii != 32)
        {
            ascii = ascii - 32;
            uppercase_letter = ascii;
            text[i] = uppercase_letter;
        }
        
        else
        i--;
    }
    printf("%s\n", text);
}
