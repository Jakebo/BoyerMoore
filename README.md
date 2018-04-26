# BoyerMoore
Boyer–Moore string search algorithm
A very simple code that implements the "bad char rule" to search string. And "Good suffix rule" has not implemented yet.

# Build
```sh
$ git clone https://github.com/Jakebo/BoyerMoore.git
$ cd BoyerMoore
$ make
```
# Usage
Run with two arguments, for example:
```sh
jakebo@jakebo-PC:~/work/boyermoore$ ./boyermoore "Search a string with boyermoore" "string"
Search a string with boyermoore
string

Search a string with boyermoore
------string

Search a string with boyermoore
---------string

string found at 9
```
