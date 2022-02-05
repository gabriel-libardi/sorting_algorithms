#Change current directory.
current_dir=$(pwd)
cd ~/Documents/Programs/C/sorting_algorithms/src

#Compile object files.
gcc -g -W -Wextra -c -fPIC utils.c -o utils.o
gcc -g -W -Wextra -c -fPIC sorting_algorithms.c -o sorting_algorithms.o
make all

#Link the object files in a shared library and export its path.
gcc -shared -o sorting_algorithms.so utils.o sorting_algorithms.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

#Run automated tests.
pytest -vv test.py
valgrind --leak-check=full --track-origins=yes ./memory_test

#Go back to the previous directory.
cd $current_dir