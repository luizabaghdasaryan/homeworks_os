#2. напечатать абсолютный путь всех файлов содержащие подстроку “test”
#!bin/bash

grep -r -l "test" | awk -v p="$PWD" '{print p"/"$1}'
