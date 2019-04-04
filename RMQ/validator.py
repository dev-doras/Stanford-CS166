import sys
import os
import random
import filecmp

def make_input_file(outfile_name):
    arr_len = random.randint(500, 1000)
    arr = [random.randint(0, 1000) for _ in range(arr_len)]
    query_len = random.randint(500, 1000)
    queries = []
    for _ in range(query_len):
        start = random.randint(0, arr_len - 1)
        end = random.randint(start, arr_len - 1)
        queries.append((start, end))
    with open(outfile_name,'w') as f:
        f.write(
            str(arr_len) + '\n' + 
            ' '.join(str(x) for x in arr) + '\n' + 
            str(query_len) + '\n' +
            ' '.join(' '.join(str(y) for y in x) for x in queries))

if __name__ == "__main__":
    make_input_file("input.txt")
    os.system("src/build/RMQ")
