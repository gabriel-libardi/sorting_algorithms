#Change current directory.
current_dir=$(pwd)
cd $current_dir/src

#Compile object files.
gcc -g -W -Wextra -c -fPIC utils.c -o utils.o
gcc -g -W -Wextra -c -fPIC sorting_algorithms.c -o sorting_algorithms.o

#Link the object files in a shared library and export its path.
gcc -shared -o sorting_algorithms.so utils.o sorting_algorithms.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

#Run automated tests.
pytest -vv test.py

#Go back to the previous directory.
cd $current_dir