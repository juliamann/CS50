#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node
{
	// the value to store in this node
    int value;

    // the pointer to the left child
    struct node* left_child;

    // the pointer to the right child
    struct node* right_child;
}
node;

// declare the root node of our list as a global variable
node* root = NULL;

// returns a heap-allocated node initialized with the passed in value
// make sure to free this memory 
node* make_node(int value)
{
	node* inserted_node = malloc(sizeof(node));
	if (inserted_node != NULL)
	{
		inserted_node->value = value;
		inserted_node->left_child = NULL;
		inserted_node->right_child = NULL;
	}
	return inserted_node;
}

// function that inserts a node into the correct place in the tree
bool insert(int value, node** tree)
{
	if (tree == NULL)
		return false;

	// if no tree exists, create first node
	if(*tree == NULL)
	{	
		*tree = make_node(value);
		if (*tree == NULL)
			return false;
		return true;
	}

	return insert(value, value < (**tree).value ? &(**tree).left_child
									: &(**tree).right_child);
}

// function that checks to see if tree contains a certain value
bool contains(int value, node* root)
{
		// recursively loop until the value found or root == NULL
		return root != NULL && (value == root->value || 
			contains(value, value < root->value
					? root->left_child : root->right_child));
}

// function to free memory allocated when creating new nodes
void free_node(node* node)
{
	if (node != NULL)
	{
		free_node(node->left_child);
		free_node(node->right_child);
		free(node);
	}
}

int main(int argc, const char* argv[])
{
	// insert new nodes
	printf("insert(%d) = %s\n", 7, (insert(7, &root))? "true" : "false");
	printf("insert(%d) = %s\n", 6, (insert(6, &root))? "true" : "false");
	printf("insert(%d) = %s\n", 3, (insert(3, &root))? "true" : "false");
	printf("insert(%d) = %s\n", 9, (insert(9, &root))? "true" : "false");
	printf("insert(%d) = %s\n", 5, (insert(5, &root))? "true" : "false");
	printf("insert(%d) = %s\n", 8, (insert(8, &root))? "true" : "false");
	printf("insert(%d) = %s\n", 2, (insert(2, &root))? "true" : "false");

	printf("contains(%d) = %s\n", 6, (contains(6, root))? "true" : "false");
	printf("contains(%d) = %s\n", 1, (contains(1, root))? "true" : "false");
	printf("contains(%d) = %s\n", 10, (contains(10, root))? "true" : "false");
	printf("contains(%d) = %s\n", 5, (contains(5, root))? "true" : "false");
	printf("contains(%d) = %s\n", 2, (contains(2, root))? "true" : "false");
	printf("contains(%d) = %s\n", 8, (contains(8, root))? "true" : "false");
	
	// free the tree
	free_node(root);

	return 0;
}
