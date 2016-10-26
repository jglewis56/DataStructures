//binary tree with recursion
#include<iostream>
using namespace std;
struct node
{ int key_value; node*p_left; node*p_right;};
//Algortihms
node *insert(node*p_tree, int key);
node *search(node*p_tree, int key);
node *remove(node* p_tree, int key);
node *find_max(node*p_tree);
void destroy_tree(node*p_tree);

node *find_max(node*p_tree)
{
	if (p_tree == NULL)// if the tree is empty
		return NULL;
	if (p_tree->p_right == NULL)// if the the right side of the tree is empty
		return p_tree;
	return find_max(p_tree->p_right);// recursion part: this makes the function keep searching for the maximum value
}


/*insertion using a recursive algorithm. This function will take a key and an existing tree and return a new tree containg the inserted value.
p_tree is a pointer to the tree*/

/* The logic behind this is if we have an empty tree, create a new one. otherwise, if the value being inserted
is less than the current node, insert it into the left subtree(p_left) and replace the left subtree with the new one.
Otherwise insert to the right subtree.*/
node*insert(node*p_tree, int key)
{
	//base case--we have reached an empty tree and need to insert our new node here
	if (p_tree == NULL)
	{
		node*p_new_tree = new node;
		p_new_tree->p_left = NULL;
		p_new_tree->p_right = NULL;
		p_new_tree->key_value = key;
		return p_new_tree;
	}
	//decide wether to insert into the left subtree or the right subtree
	if (key < p_tree->key_value)
		// build a new tree based on p_tree->left by adding the key
		//Then replace the existing p_tree->left pointer with a pointer to the new tree
		//We also need to set the p_tree->left pointer in case p_tree->left is NULL
		p_tree->p_left = insert(p_tree->p_left, key);
	else
		p_tree->p_right = insert(p_tree->p_right, key);
	return(p_tree);
}

node*search(node*p_tree, int key)
{
	if (p_tree == NULL) // if the tree is empty
		return NULL;
	else if (p_tree->key_value == key)// if we find the key
		return p_tree;
	if (key < p_tree->key_value)// if the key is less than the trees key value
		return search(p_tree->p_left, key);
	else
		return search(p_tree->p_right, key);
	
}
void destroy_tree(node*p_tree) //recursive
{
	if (p_tree != NULL)
	{
		destroy_tree(p_tree->p_left);
		destroy_tree(p_tree->p_right);
		cout << "Deleting node:" << p_tree->key_value;
		delete p_tree;
	}
}

//removing from a tree. Its a little more complex

node *remove(node* p_tree, int key)
{
	if (p_tree == NULL)// if the tree is empty
		return NULL;
	if (p_tree->key_value == key)
	{
		//what to do
		/* 3 conditions to consider
		  1.) if the node being removed has no children
		      a.) just need to return NULL
		  2.) the node being removed has one child
		      a.) just need to return the child
		  3.) the node being removed has two children
		      a.) we can either find the largest value  to the left of the node
			  b.) we can find the smallest value to the right of the node

		*/
		if (p_tree->p_left == NULL)// the first case handles having zero
		{
			node*p_right_subree = p_tree->p_right;
			delete p_tree;
			//This will return NULL if there are zero child nodes
			return p_right_subree;
		}
		if (p_tree->p_right == NULL)
		{
			node*p_left_subtree = p_tree->p_left;
			delete p_tree;
		}

	}
	else if (key < p_tree->key_value)// value less than the tree value
		p_tree->p_left = remove(p_tree->p_left, key);
	else
		p_tree->p_right = remove(p_tree->p_right, key); //key greater than the tree value

}
