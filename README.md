# Stanford-CS166

## [RMQ(Range Minimum Query)](RMQ)

RMQ is implemented in three ways:

1. [Using simple table](RMQ/src/simple_table.hpp)
2. [Using preprocessing](RMQ/src/preprocessing.hpp)
3. [Using block partition](RMQ/src/block_partition.hpp)


### How to Use

There is an example code [main.cpp](RMQ/src/main.cpp) and [input](RMQ/input.txt)/[output](RMQ/output.txt) files.

Include the header file you want, use the class in it.

The input consists of 4 lines, the number of data, data, the number of queries, queries.

You can initialize the class with an input stream, and call `fillTable` method with the input stream.  
The method `answer` give you the answer of query.
