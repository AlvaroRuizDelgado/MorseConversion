# Containers speed comparison

This repository uses text-to-morse conversion as a simple example to test the search performance of different data structures. I tested multiple ways to store the morse translation table, and measured the efficiency of each of them by checking how long it takes them to translate the original version of "Don Quixote" ([downloaded from gutenberg.org](http://www.gutenberg.org/ebooks/2000) and stored in "long.txt") from Spanish to Morse.

To measure the time it takes for the operation to complete I use a simple structure Timer (defined in "timer.hpp") that uses RAII principles to compute the execution time through the \<chrono\> library.

## Methods and comparison

The first data structure that comes to mind when building a dictionary is a map. However, given that the code is small and unlikely to change, storing the data in an array may prove to be more efficient, especially when thinking of this library as a part of a larger program, where the small size of a pair of arrays may make it more likely that the data stays in the cache memory.

In addition to maps and arrays, I wanted to try storing the information in vectors, which seemed like a good compromise between the flexibility of maps and the small footprint of arrays, and also in unordered_maps, which I reckon may give a faster search time than maps in this case, even if at the cost of a larger memory footprint.

| Data structure | Don Quixote to morse in ms |
| --- | --- |
| Arrays (ASCII subtraction search) | ~65 ms |
| Arrays (binary search) | ~115 ms |
| Arrays (brute force search) | ~170 ms |
| Unordered map | ~370 ms |
| Map | ~540 ms |
| Vectors (hard-code init) | ~570 ms |
| Vectors (load from file) | ~590 ms |

_Note: the above times will vary depending on the machine, but their ratio should remain similar._

As expected the double array method is the fastest, and unordered_map is indeed faster than map for this application.

For the double array method I tried a few different search methdos. The fastest method was to take advantage of the proximity of numbers and alphabet characters in the ASCII table and simply subtract the ASCII for '0' from the requested character. In this case the array needs to have a few dummy entries to fill the gap between '9' and 'A', so it becomes a bit larger (7 extra characters -> 19% larger). In other data sets without this convenient ordering, binary search and brute force can still perform well with few enough entries.

I was surprised to see the poor performance of the vector method in the above experiment. In the end the search of the element in vector form is not as straightforward as I thought. The search I do in both the double array and the double vector methods is to find the position of the requested character in the alphabet container and return the string in that position in the other container (morse). As std::vector<char>::iterator is not the same as std::vector<std::string>::iterator there is an extra conversion step that may impact performance.

In the double array method I have the morse code hard-coded directly in the initialization, while in the other methods the data is loaded from a file in the constructor. The data could be loaded from memory in the arrays method if the member variables were pointers instead of arrays, taking care to free them in the destructor. However, the difference in terms of speed between hard-coding and loading from a file was around 20 ms in the vectors case, hardly a big factor (the code is left commented out). Considering that the morse code is well established and unlikely to change in this particular case I think it's fair to keep the initialization hard-coded in the case of the double array.

There was another curious thing happening with the vector case. Ordering the data in 'morse.dat' giving first the numbers and then the letters would take significantly longer (around 0.7 s in total) than writing the letters before the numbers. I couldn't figure out what's going on in there, but it may be worth it to try different data orders when using vectors in conjunction with std::find.

In conclusion, for a simple application with a static dictionary that doesn't get elements added or removed, an implementation using a pair of arrays with hard-coded initialization gives the best results in both speed and memory footprint. If, on the contrary, we expect addtions and removals, unordered_maps would be the best next thing, even if it results in a larger memory cost.

## Morse conversion table

![](International_Morse_Code.png)

## Compilation

Compilation and execution of each example:
```bash
g++ *.cpp -o test.exe
./test.exe
```
