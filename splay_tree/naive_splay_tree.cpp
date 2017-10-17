#include "naive_splay_tree.h"

node* naive_splay_tree::insert(int value)
{
	if (root == nullptr)
	{
		root = addValue(nullptr, value);
	}
	node * n = root;

	while (n->value != value)
	{
		if (n->value > value)
		{
			if (n->left == nullptr)
				n->left = addValue(n, value);
			n = n->left;
		}
		else
		{
			if (n->right == nullptr)
				n->right = addValue(n, value);
			n = n->right;
		}
	}

	splay(n);

	return n;
}

node* naive_splay_tree::find(int value)
{
	node * n = root;

	while (n != nullptr && n->value != value)
	{
		if (n->value > value)
			n = n->left;
		else
			n = n->right;
	}

	if (n != nullptr)
		splay(n);

	return n;
}

void naive_splay_tree::splay(node* x)
{
	while (x->parent != nullptr)
	{
		node * v = x->parent->parent; 
		if(x->parent->left == x)
		{
			if (v != nullptr)
			{
				if (x->parent == x->parent->parent->left)
					v->left = l_rotate(x);
				else
					v->right = l_rotate(x);
			}
			else
				root = l_rotate(x);
		}
		else
		{
			if (v != nullptr)
			{
				if (x->parent == x->parent->parent->left)
					v->left = r_rotate(x);
				else
					v->right = r_rotate(x);
			}
			else
				root = r_rotate(x);
		}

	}
}


node* naive_splay_tree::l_rotate(node* x) 
{
	node * y = x->parent;
	node * B = x->right;

	x->parent = y->parent;
	x->right = y;

	y->parent = x;
	y->left = B;

	if (B != nullptr)
		B->parent = y;

	return x;
}

node* naive_splay_tree::r_rotate(node* x) 
{
	node * y = x->parent;
	node * B = x->left;

	x->parent = y->parent;
	x->left = y;

	y->parent = x;
	y->right = B;

	if (B != nullptr)
		B->parent = y;

	return x;
}