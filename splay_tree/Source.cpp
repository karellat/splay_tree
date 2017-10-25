#pragma once
#include <iostream>
#include <string>
#include "test.h"
#include "splay_tree.h"
#include  <ctime>
#include <fstream>

void run_tests();
void read_file(const char * path);

int main(int argc, const char * argv[])
{
	if (argc == 2 && strcmp(argv[1], "test") == 0)
		run_tests();
	else if (argc > 2 && strcmp(argv[1], "file") == 0)
	{
		for (size_t t = 2; t < argc; t++)
		{
			std::cout << "Reading file: " << argv[t] <<  " started. "<< std::endl; 
			clock_t begin = clock();
			read_file(argv[2]);
			clock_t end = clock();
			std::cout << "Reading file: " << argv[t] << " finnished. Time: " << ((end-begin)/CLOCKS_PER_SEC)/1000 << " ms" << std::endl;
		}
	}

	std::string s;
	std::getline(std::cin, s);

	return 0;

}

void run_tests()
{
	std::cout << "Standard splay tree tests!" << std::endl; 
	run_splay_tree_tests();
	std::cout << "Standard splay tree tests finnished!" << std::endl; 


	std::cout << "All tests finnished!" << std::endl; 

	
}

void read_file(const char * path)
{
	std::ifstream file{ path };
	int v = -1; 
	char c = ' ';

	splay_tree * tree = nullptr;
	std::string line; 
	while (std::getline(file,line))
	{
		sscanf_s(line.c_str() +2 , "%d", &v);
		switch (line[0])
		{
			case '#':
			{
				if (tree != nullptr) {
					std::cout << "Testing tree ends, find Mean Depth: " << tree->mean_depth_find() << std::endl;
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
	std::cout << "Testing tree ends, find Mean Depth: " << tree->mean_depth_find() << std::endl;

}
