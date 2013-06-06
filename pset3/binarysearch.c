#include <stdio.h>
#include <cs50.h>

#define SIZE 8

bool search (int needle, int haystack[], int size)
{
    // TO DO: return true if needle is in haystack using binary search
    int first, middle, last;
    first = 0;
    last = (size - 1);
    middle = (first + last) / 2;
    
    while (first <= last)
    {
        if (haystack[middle] < needle)
        {
            first = middle + 1;
            middle = (first + last) / 2;
        }
        else if (haystack[middle] == needle)
        {
            printf("Your number, %d, was found in the haystack!\n", needle);  
            break;   
        }
        else 
        {
            last = middle - 1;
            middle = (first + last) / 2;
        }
    } 
      
    if (first > last)
    {
        printf("Your number, %d, was not found in the haystack!\n", needle);
        return false; 
    }
    else
        return true;
}

int main(void)
{
    int numbers[SIZE] = {4, 8, 15, 16, 23, 42, 50, 108};
    printf("> ");
    int n = GetInt();
    if (search(n, numbers, SIZE))
        printf("YES\n");
    return 0;    
}
