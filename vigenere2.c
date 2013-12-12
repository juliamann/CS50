#include <stdio.h>
//#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    //make sure user enters one command line argument
    if (argc != 2)
        return 1;
        
    //make sure command line argument is only letters
    char* key = argv[1];
    int length = strlen(key);
    bool error = false;
    for (int i = 0; i < length; i++)
    {
        bool alpha = isalpha(key[i]); 
        if (alpha == false)
        {
            error = true;
            break;
        }
    } 
    
    if (error == true)
        return 1;
                 
    //ask user for text
    char text[256];
    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);
        
    //encrypt the text
    int n = strlen(text);
    int key_counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (key_counter > length - 1)
        {
            key_counter = 0;
        }
        //check for alpha, upper and lower
        bool alpha = isalpha(text[i]); 
        if (alpha == true)
        {
            if (isupper(text[i]))
            {
                // A-Z = 65-90
                int plaintext_ascii = text[i];
                int ascii_key = key[key_counter];
                if (ascii_key > 96)
                {
                    ascii_key = ascii_key - 97;
                }
                else
                {
                    ascii_key = ascii_key - 65;
                }
                int ciphertext_ascii = plaintext_ascii + ascii_key;
                if (ciphertext_ascii > 90)
                {
                    ciphertext_ascii = ((((plaintext_ascii - 65) + ascii_key) % 26) + 65);
                }
                char ciphertext_letter = ciphertext_ascii;
                printf("%c", ciphertext_letter);
            }
            else
            {
                // a-z = 97-122
                
                int plaintext_ascii = text[i];
                int ascii_key = key[key_counter];
                if (ascii_key > 96)
                {
                    ascii_key = ascii_key - 97;
                }
                else
                {
                    ascii_key = ascii_key - 65;
                }
                int ciphertext_ascii = plaintext_ascii + ascii_key;
                if (ciphertext_ascii > 122)
                {
                    ciphertext_ascii = ((((plaintext_ascii - 97) + ascii_key) % 26) + 97);
                }
                char ciphertext_letter = ciphertext_ascii;
                printf("%c", ciphertext_letter);
            }
            key_counter = key_counter + 1;
        }
        else 
        {
            printf("%c", text[i]);
        }   
    }
    printf("\n");
}
