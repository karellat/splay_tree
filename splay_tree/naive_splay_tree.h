#pragma once
#include "splay_tree.h"

using namespace std;

struct naive_splay_tree
{
public:

	node * root; 
	naive_splay_tree(size_t max_size) : root(nullptr), nodes(new node[max_size]),max_size(max_size)	{	}
	~naive_splay_tree()
	{
		delete nodes; 
	}
	size_t max_size;

	node * insert(int value); 
	node * find(int value); 
	void splay(node * x);
	double mean_depth_find()
	{
		if (number_of_finds == 0) return 0;
		return sum / (double) number_of_finds;
	}

private:
	int nodes_free_index = 0;
	node * nodes; 


	std::int64_t number_of_finds = 0;
	std::int64_t sum = 0;
	
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
		sum += depth;
		number_of_finds++;
	}
};
