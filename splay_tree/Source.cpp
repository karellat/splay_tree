#pragma once
#include <iostream>
#include <string>
#include "test.h"
#include "splay_tree.h"


void run_tests();


int main(int argc, const char * argv[])
{
	if (argc == 2)
	{
		std::string param = argv[1];
		if (param == "test")
			run_tests(); 
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
