#include "simple_table.hpp"
#include "preprocessing.hpp"
#include "block_partition.hpp"
#include <iostream>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    //method designation
    SimpleTable<int> table(input);

    table.fillTable(input);

    int query_num = 0;
    input >> query_num;

    size_t i=0,j=0;
    for(size_t count = 0; count < query_num; count++)
    {
        input >> i >> j;
        output << table.answer(i,j) << ' ';
    }
    
    return 0;
}