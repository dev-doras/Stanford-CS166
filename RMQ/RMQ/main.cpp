#include "simple_table.hpp"
#include <iostream>

int main()
{
	std::ifstream input("input.txt");

	SimpleTable<int> table(input);
	table.fillTable();

	std::cout << table;
}