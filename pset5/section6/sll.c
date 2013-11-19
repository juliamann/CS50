/*************************************************************************
 * sll.c
 *
 * Implements a simple singly-linked list structure for ints.
 ************************************************************************/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// the size of our test list: feel free to adjust as you wish!
#define TEST_SIZE 10

typedef struct node
{
    // the value to store in this node
    int i;

    // the link to the next node in the list
    struct node* next;
}
node;

// declare the first node of our list (as a global variable)
node* first = NULL;

/**
 * Returns the length of the list.
 */
int length(void)
{
    // declare length variable
    int length = 0;

    // set a new node at first node's location then 
    // count the iterations until the last (null) node is reached
    for (node* n = first; n != NULL; n = n->next)
        length++;

    return length;
}

/**
 * Returns true if a node in the list contains the value i and false
 * otherwise.
 */
bool contains(int i)
{
    // set a new node at first node's location then 
    // iterate until the last (null) node is reached
    for (node* n = first; n != NULL; n = n->next)
    {
        // return true if value i is found in list
        if (n->i == i)
            return true;
    }

    // else return false
    return false;
}

/**
* HELPER FUNCTION: Creates a new node structure in memory.
*/
node* create_node(void)
{
    // allocate memory for new node
    node* n = malloc(sizeof(node));

    // check to make sure there is space in memory
    if (n == NULL)
    {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }

    return n;
}

/**
 * Puts a new node containing i at the front (head) of the list.
 */
void prepend(int i)
{
    // initalize new node 
    node* new_node = create_node();

    // set new node's i value
    new_node->i = i;

    // set new node's next pointer to first node in list
    new_node->next = first;

    // new node now becomes first/front/head node in list  
    first = new_node;
}

/**
 * HELPER FUNCTION: Inserts a new node immediately following another one. 
 */

void insert_node(node* new_node)
 {
    // if first node is NULL, set it's values to new_node's values
    if (first == NULL)
        first = new_node;

    else 
    {
        // initialize pred_node with same value's as first node's 
        node* pred_node = first;

        // infinite loop: 
        while (true)
        {
            // loop pred_node through until it's next ptr is NULL
            if (pred_node->next == NULL)
            {
                // when pred_node's next ptr is at NULL (last in list), set 
                // it's next ptr to the new node created, then break
                pred_node->next = new_node;
                break;
            }

            // in each loop, set pred_node to the next node in the linked list
            pred_node = pred_node->next;
        }
    }
}

/**
 * Puts a new node containing i at the end (tail) of the list.
 */
void append(int i)
{
    // initalize new node 
    node* new_node = create_node();

    // set new node's i value
    new_node->i = i;

    // set new node's next value to NULL
    new_node->next = NULL;

    // insert node immediately following previous node
    insert_node(new_node);
}

/**
 * Puts a new node containing i at the appropriate position in a list
 * sorted in ascending order.
 */
void insert_sorted(int i)
{
    // initalize new node 
    node* new_node = create_node();

    // set new node's i value
    new_node->i = i;

    // set new node's next value to NULL
    new_node->next = NULL;

    // check if list is empty
    if (first == NULL)
        first = new_node;

    // then check if i belongs at beginning of list
    else if (new_node->i < first->i)
    {
        new_node->next = first;
        first = new_node;
    }

    // else check if i belongs at end or middle of the list
    else
    {
        // initialize pred_node with same value's as first node's 
        node* pred_node = first;

        while (true)
        {
            // check for insertion at end of list
            if (pred_node->next == NULL)
            {
                pred_node->next = new_node;
                break;
            }

            // check for insertion in the middle of the list
            else if (pred_node->next->i > new_node->i)
            {
                new_node->next = pred_node->next;
                pred_node->next = new_node;
                break;
            }

            // in each loop, set pred_node to the next node in the linked list
            pred_node = pred_node->next;
        } 
    }
}

/**
 * Implements some simple test code for our singly-linked list.
 */
int main(void)
{
    printf("Prepending ints 0-%d onto the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        prepend(i);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in descending order...");
    node* n = first;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i == TEST_SIZE - i - 1);
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("Appending ints 0-%d to the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        append(i);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in ascending order...");
    n = first;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i == i);
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("Inserting %d random ints to the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        insert_sorted(rand() % TEST_SIZE);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in sorted order...");
    n = first;
    int prev = 0;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i >= prev);
        prev = n->i;
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("\n********\nSuccess!\n********\n");

    return 0;
}
