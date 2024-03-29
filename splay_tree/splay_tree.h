#pragma once
#include <cstdint>

using namespace std;

struct node {
	node * parent;
	node * left;
	int value;
	node * right;
	node(){}
	node(const int value, node * parent) : parent(parent), left(nullptr), value(value), right(nullptr) {}
};
struct nodes_array
{
public:
	nodes_array(size_t max_size) : nodes(new node[max_size]),max_size(max_size) {}
	~nodes_array() { delete[] nodes; }
	size_t max_size;
private:
	node * nodes;
	size_t free_index = 0;
	node * Add(int value, node * parent)
	{
		node * n = &nodes[free_index];
		free_index++;
		n->value = value;
		n->parent = parent;
		n->left = nullptr;
		n->right = nullptr;

		return n;
	}
};
struct splay_tree
{ 
	splay_tree() : nodes(new node[1000]), max_size(1000) {};
	splay_tree(size_t max_size) : nodes(new node[max_size]), max_size(max_size),root(nullptr) {};
	~splay_tree()
	{
		delete[]nodes;
	}
	node * root;
	node* l_rotate(node * x) const;
	node* r_rotate(node * x) const;
	node* ll_rotate(node * x) const;
	node* rr_rotate(node * x) const;
	node* lr_rotate(node * x) const;
	node* rl_rotate(node * x) const;

	node * insert(int value);
	node * find(int value);
	void splay(node * x);
	double mean_depth_find()
	{
		if (number_of_finds == 0) return 0;
		return sum / (double) number_of_finds;
	}
	size_t max_size;

private:

	size_t nodes_free_index = 0;
	node* nodes;

	std::int64_t number_of_finds = 0; 
	std::int64_t sum = 0; 
	
	inline node* add_value(node * parent, int value)
	{
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


