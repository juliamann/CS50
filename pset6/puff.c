/*********************************************************************************
 * puff.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Takes a huffed (compressed) infile and puffs (decompresses) it into an outfile.
 *********************************************************************************/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "forest.h"
#include "huffile.h"
#include "tree.h"

// // combine function prototype
// Tree* combine(Tree* a, Tree* b);

// combine function: takes two trees, combines their frequencies
// and returns a parent tree with their sum as it's frequency
Tree* combine(Tree* a, Tree* b)
{
    // make parent tree
    Tree* parent_tree = mktree();

    // set parent tree's freq. to the sum of it's children's freq.
    parent_tree->frequency = (a->frequency + b->frequency);

    // set parent tree's children
    parent_tree->left = a;
    parent_tree->right = b;

    // return combined 'parent' tree 
    return parent_tree;
}

// declare the root tree as a global variable
Tree* root = NULL;

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: %s input\n", argv[0]);
        return 1;
    }

    // open input
    Huffile* input = hfopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }

    // open outfile
    FILE* outfile = fopen(argv[2], "w");
    if (outfile == NULL)
    {
        fclose(outfile);
        fprintf(stderr, "Could not create outfile.\n");
        return 2;
    }

    // read in header
    Huffeader header;
    if (hread(&header, input) == false)
    {
        hfclose(input);
        printf("Could not read header.\n");
        return 1;
    }

    // check for magic number
    if (header.magic != MAGIC)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // check checksum
    int checksum = header.checksum;
    for (int i = 0; i < SYMBOLS; i++)
    {
        checksum -= header.frequencies[i];
    }
    if (checksum != 0)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // make forest
    Forest* forest = mkforest();

    // read in huffeader frequencies
    for (int i = 0; i < SYMBOLS; i++)
    {
         // ignore 0 frequencies
        if (header.frequencies[i] > 0)
        {
            // make new tree for every non-zero frequency occurance
            Tree* new_tree = mktree();
            new_tree->symbol = i;
            new_tree->frequency = header.frequencies[i];
            new_tree->left = NULL;
            new_tree->right = NULL;

            // plant every non-zero frequency tree in forest
            plant(forest, new_tree);
        }
    }

    // run loop until there is only one tree left
    bool done = false;
    while (!done)
    {
        // pick smallest tree from forest
        Tree* a = pick(forest);

        // pick second smallest tree from forest
        Tree* b = pick(forest);

        // if there is no second tree in forest...
        if (b == NULL)
        {
            // break loop
            done = true;
            // set root to tree 'a' (last remaining) tree
            root = a;
        }

        // else there are at least two remaining trees in the forest
        else
        {
            // combine the two trees into a parent tree
            Tree* parent_tree = combine(a, b);

            // plant combined tree in forest
            plant(forest, parent_tree);
        }
    }

    // write message to outfile
    int bit;
    Tree* ptr_location = root;
    while ((bit = bread(input)) != EOF)
    {
        // if bit is 0, go left, else go right
        if (bit == 0)
            ptr_location = ptr_location->left; 

        // if bit is 1, go right
        if (bit == 1)
            ptr_location = ptr_location->right;

        // leaf is found when both branchs are NULL
        if ((ptr_location->left == NULL) && (ptr_location->right == NULL))
        {
            // write leaf's symbol to outfile
            fprintf(outfile, "%c", ptr_location->symbol);

            // reset pointer location to root for next iteration of tree
            ptr_location = root;
        }
    }

    // free root
    rmtree(root);

    // close forest
    rmforest(forest);

    // close input & outfile
    hfclose(input);
    fclose(outfile);

    // that's all folks!
    return 0;
}



