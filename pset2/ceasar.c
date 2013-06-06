#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //make sure user enters one command line argument
    if (argc != 2)
        return 1;
    
    //change string in command line argument to an int
    int key = atoi(argv[1]);
    printf("The number of the key is %d.\n", key);
    
    //ask user for text
    printf("Enter some text: ");
    string text = GetString();
        
    //encrypt the text
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        //check for alpha, not number or symbol
        bool alpha = isalpha(text[i]); 
        if (alpha == true)
        {
            if (isupper(text[i]))
            {
                // A-Z = 65-90
                int plaintext_ascii = text[i];
                int ciphertext_ascii = plaintext_ascii + key;
                if (ciphertext_ascii > 90)
                {
                    ciphertext_ascii = ((((plaintext_ascii - 65) + key) % 26) + 65);
                }
                char ciphertext_letter = ciphertext_ascii;
                printf("%c", ciphertext_letter);
            }
            else
            {
                // a-z = 97-122
                int plaintext_ascii = text[i];
                int ciphertext_ascii = plaintext_ascii + key;
                if (ciphertext_ascii > 122)
                {
                    ciphertext_ascii = ((((plaintext_ascii - 97) + key) % 26) + 97);
                }
                char ciphertext_letter = ciphertext_ascii;
                printf("%c", ciphertext_letter);
            }
        }
        else 
        {
            printf("%c", text[i]);
        }   
    }
    printf("\n");
}
