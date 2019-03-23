#include "simple_table.hpp"
#include "preprocessing.hpp"
#include <iostream>

template<class C>
void test(std::ifstream &input)
{
    C table(input);
    table.fillTable(input);
    std::cout << table;
}

int main()
{
    std::ifstream input("input.txt");

    test<PreProcessing<int>>(input);
}