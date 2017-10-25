#pragma once
#include "splay_tree.h"

struct naive_splay_tree
{
public:

	node * root; 
	naive_splay_tree(size_t max_size) : root(nullptr), nodes(new node[max_size]),max_size(max_size)	{	}
	~naive_splay_tree() {}

	node * insert(int value); 
	node * find(int value); 
	void splay(node * x);
	double mean_depth_find = 0;
private:
	int nodes_free_index = 0;
	node * nodes; 
	size_t max_size;
	
	size_t number_of_finds = 0;

	node * l_rotate(node * x);
	node * r_rotate(node * x);
	

	inline node * addValue(node * parent, int value) {
		node * o = &nodes[nodes_free_index];
		o->parent = parent;
		o->left = nullptr;
		o->right = nullptr;
		o->value = value;
		nodes_free_index++;
		return o;
	}
	inline void add_find_depth(size_t depth)
	{
		mean_depth_find = mean_depth_find * (number_of_finds / (number_of_finds + 1)) + (depth / (number_of_finds + 1));
		number_of_finds++;
	}
};
