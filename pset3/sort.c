#include <stdio.h>
#include <cs50.h>

//#define SIZE 8

void sort(int array[], int size)
{
    // TO DO: sort array using any [bubblesort] algorithm
    for (int x = 0; x < size - 1; x++)
    {
        for (int y = 0; y < size - x - 1; y++)
            if (array[y] > array[y + 1])
            {
                int temp = array[y];
                array[y] = array[y + 1];
                array[y + 1] = temp;
            }
    } 
}

int main(void)
{
    printf("How many numbers do you want to sort?\n");
    int SIZE = GetInt();
    int numbers[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter number %d: \n", i + 1);
        numbers[i] = GetInt();
    }
    //int numbers[SIZE] = {4, 15, 16, 50, 8, 23, 42, 108};
    
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    sort(numbers, SIZE);
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    return 0; 
}
