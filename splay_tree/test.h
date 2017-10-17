#pragma once
#include <assert.h>
#include "splay_tree.h"


void test_l(); 
void test_r(); 
void test_ll(); 
void test_rr();
void test_rl(); 
void test_lr();
void test_insert();

inline void run_splay_tree_tests()
{
	test_l();
	test_r();
	test_ll();
	test_rr();
	test_rl();
	test_lr();
	test_insert();
}