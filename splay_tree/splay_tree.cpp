#include "splay_tree.h"


node* splay_tree::l_rotate(node* x) const
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

node* splay_tree::r_rotate(node* x) const
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

node* splay_tree::ll_rotate(node* x) const
{
	node * y = x->parent;
	node * z = y->parent;
	node * B = x->right;
	node * C = y->right;

	x->parent = z->parent;
	x->right = y;

	y->parent = x;
	y->right = z;
	y->left = B;

	z->parent = y;
	z->left = C;

	if (B != nullptr)
		B->parent = y;

	if (C != nullptr)
		C->parent = z;

	if (x->parent == nullptr)
		return x;
	else
	{
		if (x->parent->left == z)
			x->parent->left = x;
		else
			x->parent->right = x;
	}

	return this->root;
}

node* splay_tree::rr_rotate(struct node* x) const
{
	node * y = x->parent;
	node * z = y->parent;
	node * B = y->left;
	node * C = x->left;

	x->parent = z->parent;
	x->left = y;

	y->parent = x;
	y->left = z;
	y->right = C;

	z->parent = y;
	z->right = B;

	if (B != nullptr)
		B->parent = z;
	if (C != nullptr)
		C->parent = y;

	if (x->parent == nullptr)
		return x;
	else
	{
		if (x->parent->left == z)
			x->parent->left = x;
		else
			x->parent->right = x;
	}

	return this->root;
}

node* splay_tree::lr_rotate(node* x) const
{
	node * y = x->parent;
	node * z = y->parent;
	node * B = x->left;
	node * C = x->right;

	x->parent = z->parent;
	x->left = y;
	x->right = z;

	y->parent = x;
	y->right = B;

	z->parent = x;
	z->left = C;

	if (B != nullptr)
		B->parent = y;
	if (C != nullptr)
		C->parent = z;

	if (x->parent == nullptr)
		return x;
	else
	{
		if (x->parent->left == z)
			x->parent->left = x;
		else
			x->parent->right = x;
	}

	return this->root; 
}

node* splay_tree::rl_rotate(node* x) const
{
	node * y = x->parent;
	node * z = y->parent;
	node * B = x->left;
	node * C = x->right;

	x->parent = z->parent;
	x->left = z;
	x->right = y;

	y->parent = x;
	y->left = C;

	z->parent = x;
	z->right = B;

	if (B != nullptr)
		B->parent = z;
	if (C != nullptr)
		C->parent = y;

	if (x->parent == nullptr)
		return x;
	else
	{
		if (x->parent->left == z)
			x->parent->left = x;
		else
			x->parent->right = x;
	}

	return this->root;
}

node* splay_tree::find(const int value)
{
	node * n = root;
	size_t depth = 0; 
	while (n != nullptr && n->value != value)
	{
		depth++; 
		if (n->value > value)
			n = n->left;
		else
			n = n->right;
	}

	if (n != nullptr)
		splay(n);

	add_find_depth(depth);

	return n;
}

node* splay_tree::insert(const int value)
{
	if (root == nullptr)
	{
		root = add_value(nullptr, value);
	}
	node * n = root;

	while (n->value != value)
	{
		if (n->value > value)
		{
			if (n->left == nullptr)
				n->left = add_value(n, value);
			n = n->left;
		}
		else
		{
			if (n->right == nullptr)
				n->right = add_value(n, value);
			n = n->right; 
		}
	}

	splay(n);

	return n;
}

void splay_tree::splay(node* x)
{
	
	while (x->parent != nullptr)
	{
		if (x->parent->parent == nullptr)
		{
			if (x->parent->left == x)
				this->root = l_rotate(x);
			else
				this->root = r_rotate(x);
		}
		else
		{
			if (x->parent->left == x)
			{
				if (x->parent->parent->left == x->parent)
					this->root = ll_rotate(x);
				else
					this->root = rl_rotate(x);
			}
			else
			{
				if (x->parent->parent->right == x->parent)
					this->root = rr_rotate(x);
				else
					this->root = lr_rotate(x);
			}
		}
	}




}





