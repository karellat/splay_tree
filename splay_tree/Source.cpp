
#include <iostream>

int main()
{
	std::cout << "Hello World";

	return 1; 
}


struct node{
	node * parent; 
	node * left;
	int value; 
	node * right;

	node(const int value, node * parent) : parent(parent),left(nullptr),value(value),right(nullptr){}
};

struct splay_tree
{
	node * root; 
	node * insert(int value);
	node * find(int value);
	void splay(node * x);
private:
	node* l_rotate(node * x);
	node* r_rotate(node * x); 
	node* ll_rotate(node * x);
	node* rr_rotate(node * x); 
	node* lr_rotate(node * x);
	node* rl_rotate(node * x);
};

node* splay_tree::l_rotate(node* x)
{
	node * y = x->parent;
	node * B = x->right;
	
	x->parent = y->parent;
	x->right = y;

	y->parent = x;
	y->left = B; 

	if(B != nullptr)
		B->parent = y;

	return x;
}

node* splay_tree::r_rotate(node* x)
{
	node * y = x->parent;
	node * B = x->left;

	x->parent = y->parent;
	x->left = y;

	y->parent = x; 
	y->right = B;

	if(B != nullptr)
		B->parent = y;

	return x; 
}

node* splay_tree::ll_rotate(node* x)
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

	return x; 
}

node* splay_tree::rr_rotate(struct node* x)
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

	return x; 
}

node* splay_tree::lr_rotate(node* x)
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

	return x; 
}

node* splay_tree::rl_rotate(node* x)
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

	return x;
}



node* splay_tree::find(const int value)
{
	node * n = root; 

	while(n != nullptr && n->value != value)
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

node* splay_tree::insert(const int value)
{
	node * n = root; 

	while(n->value != value)
	{
		if (n->value > value)
		{
			if (n->left == nullptr)
				n->left = new node(value,n);
			n = n->left;
		}
		else
			if (n->right == nullptr)
				n->right = new node(value,n);
			n = n->right;
	}

	splay(n);

	return n;
}

void splay_tree::splay(node* x)
{
	if (x->parent == nullptr)
		return; 
	
	else if(x->parent->parent == nullptr)
	{
		if (x->parent->left == x)
			l_rotate(x);
		else
			r_rotate(x);
	}
	else
	{
		if(x->parent->left == x)
		{
			if (x->parent->parent->left == x->parent)
				ll_rotate(x); 
			else
				rl_rotate(x);
		}
		else
		{
			if (x->parent->parent->right == x->parent)
				rr_rotate(x);
			else
				lr_rotate(x);
		}

	}

	


}
