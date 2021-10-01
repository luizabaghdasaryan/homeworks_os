#!/bin/bash

echo -e "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\na\nb" > f1

echo -e  "c\nd\ne\n11\n12\n13\n14\n15" > f2

head -n 10 f1 > f3

tail -n 5 f2 >> f3

cat f3

tail -n 2 f1; head -n 3 f2 > f4

cat f4

