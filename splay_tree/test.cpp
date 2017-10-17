#include "test.h"

void tree_consistency_test(node * n)
{
	if (n->left != nullptr)
	{
		assert(n->value > n->left->value);
		assert(n->left->parent == n);
		tree_consistency_test(n->left);
	}

	if (n->right != nullptr)
	{
		assert(n->value < n->right->value);
		assert(n->right->parent == n);
		tree_consistency_test(n->right);
	}

}

node* l_tree()
{
	node* r = new node(5, nullptr);

	r->left = new node(3, r);
	r->left->left = new node(2, r->left);
	r->left->right = new node(4, r->left);

	r->right = new node(6, r);

	tree_consistency_test(r);
	return r; 
}
node* r_tree()
{
	node* r = new node(4, nullptr); 

	r->left = new node(3, r); 

	r->right = new node(6, r);
	r->right->left = new node(5, r->right);
	r->right->right = new node(7, r->right);

	tree_consistency_test(r);

	return r;
}

void test_l()
{
	splay_tree *  t = new splay_tree();
	t->root = l_tree();
	t->find(3);

	tree_consistency_test(t->root);
	
	assert(t->root->value == 3);
	assert(t->root->left->value == 2);
	assert(t->root->right->value == 5);
	assert(t->root->right->left->value == 4);
	assert(t->root->right->right->value == 6);
}

void test_r()
{
	splay_tree * t = new splay_tree(); 
	t->root = l_tree(); 
	t->find(6); 

	tree_consistency_test(t->root);
	
	assert(t->root->value == 6);
	assert(t->root->right == nullptr);
	assert(t->root->left->value == 5);
	assert(t->root->left->right == nullptr);
	assert(t->root->left->left->value == 3);
	assert(t->root->left->left->left->value == 2);
	assert(t->root->left->left->right->value == 4);
}

void test_ll()
{
	splay_tree * t = new splay_tree(); 
	t->root = l_tree(); 
	t->find(2);

	tree_consistency_test(t->root);

	assert(t->root->value == 2); 
	assert(t->root->left == nullptr); 
	assert(t->root->right->value == 3);
	assert(t->root->right->left == nullptr); 
	assert(t->root->right->right->value == 5); 
	assert(t->root->right->right->left->value == 4);
	assert(t->root->right->right->right->value == 6); 
}

void test_rr()
{
	splay_tree * t = new splay_tree(); 
	t->root = r_tree(); 
	t->find(7); 

	tree_consistency_test(t->root);

	assert(t->root->value == 7);
	assert(t->root->right == nullptr);
	assert(t->root->left->value == 6);
	assert(t->root->left->right == nullptr);
	assert(t->root->left->left->value == 4); 
	assert(t->root->left->left->right->value == 5); 
	assert(t->root->left->left->left->value == 3);
}

void test_lr()
{
	splay_tree * t = new splay_tree(); 
	t->root = l_tree(); 
	t->find(4); 

	tree_consistency_test(t->root);

	assert(t->root->value == 4);
	assert(t->root->left->value == 3); 
	assert(t->root->right->value == 5);

	assert(t->root->left->right == nullptr);
	assert(t->root->left->left->value == 2);

	assert(t->root->right->left == nullptr); 
	assert(t->root->right->right->value == 6);
}

void test_insert()
{
	splay_tree* tree = new splay_tree(1000);

	tree->insert(4);

	tree_consistency_test(tree->root); 
	assert(tree->root->value == 4); 
	assert(tree->root->left == nullptr);
	assert(tree->root->right == nullptr);

	tree->insert(2); 
	tree_consistency_test(tree->root);
	assert(tree->root->value == 2);
	assert(tree->root->left == nullptr);
	assert(tree->root->right->value == 4);
	assert(tree->root->right->left == nullptr);
	assert(tree->root->right->right == nullptr);


	tree->insert(3); 
	tree_consistency_test(tree->root);
	assert(tree->root->value == 3);
	assert(tree->root->left->value == 2);
	assert(tree->root->right->value == 4);

}

void test_rl()
{
	splay_tree *t = new splay_tree();
	t->root = r_tree();
	t->find(5);

	tree_consistency_test(t->root);

	assert(t->root->value == 5);
	assert(t->root->left->value == 4);
	assert(t->root->right->value == 6);

	assert(t->root->left->right == nullptr);
	assert(t->root->left->left->value == 3);

	assert(t->root->right->left== nullptr);
	assert(t->root->right->right->value == 7);
}

