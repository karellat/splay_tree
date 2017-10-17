#pragma once
#include "splay_tree.h"

struct naive_splay_tree
{
public:

	node * root; 
	naive_splay_tree() {}
	~naive_splay_tree() {}

	node * insert(int value); 
	node * find(int value); 
	void splay(node * x);

private:
	node * l_rotate(node * x); 
	node * r_rotate(node * x); 
	inline node * addValue(node * parent, int value) {}
};
