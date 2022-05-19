#!/usr/bin/python3
import itertools as iter

my_row = [0,1,2,3,4]
my_column = [5,6,7,8,9]

new = list(iter.product(my_row,my_column))
print(new)