#include  <ctime>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

#include "test.h"
#include "splay_tree.h"
#include "naive_splay_tree.h"
using namespace std;


void run_tests();
void read_file(const char * path);
void read_std_naive_input();
void read_std_standard_input();

int main(int argc, const char * argv[])
{
	if (argc == 2 && strcmp(argv[1], "test") == 0)
		run_tests();

	else if (argc >= 2 && strcmp(argv[1], "cin") == 0 && strcmp(argv[2], "naive") == 0)
	{
		//DEBUG
		//std::cout << "Reading std::cin by naive tree" << std::endl;
		//std::chrono::high_resolution_clock clock;
		//auto begin = clock.now();
		
		read_std_naive_input();
		
		//auto end = clock.now();
		//auto s = std::chrono::duration_cast<std::chrono::seconds>(end - begin).count();
		//std::cout << "Reading std::cin by naive tree finnished. Time: " << s << " s" << std::endl;
	}
	else if (strcmp(argv[1],"cin") == 0 && strcmp(argv[2], "stand") == 0) 
	{
		//DEBUG
		//std::cout << "Reading std::cin by standard tree" << std::endl; 
		//std::chrono::high_resolution_clock clock;
		//auto begin = clock.now();
		
		read_std_standard_input();
		
		//auto end = clock.now();
		//auto s = std::chrono::duration_cast<std::chrono::seconds>(end - begin).count();
		//std::cout << "Reading std::cin by standard tree finnished. Time: " << s << " s" << std::endl;
	}
	return 0;
}

void run_tests()
{
	std::cout << "Standard splay tree tests!" << std::endl; 
	run_splay_tree_tests();
	std::cout << "Standard splay tree tests finnished!" << std::endl; 

	std::cout << "All tests finnished!" << std::endl; 
}


void read_std_naive_input()
{
	int v = -1;
	char c = ' ';

	naive_splay_tree * tree = nullptr;
	std::string line;
	while (std::getline(std::cin, line))
	{
		sscanf_s(line.c_str() + 2, "%d", &v);
		switch (line[0])
		{
		case '#':
		{
			if (tree != nullptr) {
				std::cout << tree->max_size << "|" << tree->mean_depth_find() << std::endl;
				delete tree;
			}
			tree = new naive_splay_tree(v);
			break;
		}
		case 'I':
		{
			assert(tree != nullptr);
			tree->insert(v);
			break;
		}
		case 'F':
		{
			assert(tree != nullptr);
			tree->find(v);
			break;
		}
		default:
		{
			assert(false);
		}
		}
	}
	std::cout << tree->max_size << "|" << tree->mean_depth_find() << std::endl;
}

void read_std_standard_input()
{
	int v = -1;
	char c = ' ';

	splay_tree * tree = nullptr;
	std::string line;
	while (std::getline(std::cin, line))
	{
		sscanf_s(line.c_str() + 2, "%d", &v);
		switch (line[0])
		{
		case '#':
		{
			if (tree != nullptr) {
				std::cout << tree->max_size << "|" << tree->mean_depth_find() << std::endl;

				delete tree;
			}
			tree = new splay_tree(v);
			break;
		}
		case 'I':
		{
			assert(tree != nullptr);
			tree->insert(v);
			break;
		}
		case 'F':
		{
			assert(tree != nullptr);
			tree->find(v);
			break;
		}
		default:
		{
			assert(false);
		}
		}
	}
	std::cout << tree->max_size << "|" << tree->mean_depth_find() << std::endl;
}