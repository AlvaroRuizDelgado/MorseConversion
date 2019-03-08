# Morse library

This repository is a simple example to perform the conversion from text to morse. I tested multiple ways to store the morse translation table, and measured the efficiency of each of them by checking how long it takes them to translate the original version of "Don Quixote" ([downloaded from gutenberg.org](http://www.gutenberg.org/ebooks/2000) and stored in "long.txt") from Spanish to Morse.

## Methods and comparison

The first data structure that comes to mind when building a morse dictionary is a map. However, given that the code is small and unlikely to change, storing the data in an array may prove to be more efficient, especially when thinking of this library as a part of a larger program, where the small size of a pair of arrays may make it more likely that the data stays in the cache memory.

In addition to maps and arrays, I want to try storing the information in vectors, which seem a good compromise between the flexibility of maps and the small footprint of arrays, and unordered_maps, which I reckon may give a faster search time than maps in this case.

| Data structure | Don Quixote to morse in seconds |
| --- | --- |
| Arrays | ~0.170 s |
| Unordered map | ~0.370 s |
| Map | ~0.540 s |
| Vectors | ~0.590 s |

Note: the above times will vary depending on the machine, but their ratio should remain similar.

As expected the double array method is the fastest, and unordered_map is indeed faster than map for this application.

I was surprised to see the poor performance of the vector method in the above experiment. In the end the search of the element in vector form is not as straightforward as I thought. The search I do in both the double array and the double vector methods is to find the position in the alphabet array/vector that corresponds to the requested character and return the string in that position in the morse array/vector. The conversion from the alphabet vector to int is probably having an impact on performance as well.

It is true that in the double array method I hard code the morse code directly in the initialization of the arrays, while I load that data from a file in the rest of the methods. The data could be loaded from memory in the arrays method if the member variables were pointers instead of arrays, taking care to free them in the destructor. However, the difference in terms of speed between hard coding and loading from a file was around 20 ms in the vectors case, hardly a big factor. Considering that the morse code is well established and unlikely to change in this particular case I think it's fair to keep the initialization hard coded in the case of the double array.

## Morse conversion table

![](International_Morse_Code.png)

## Compilation

Compilation and execution of each example:
```bash
g++ *.cpp -o test.exe
./test.exe
```
