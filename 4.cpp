#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open file for writing
    fstream fs;
    fs.open("file.txt", ios::out);

    if (!fs) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;  // Exit the program with an error code
    }

    // Write data to the file
    fs << "Hello Everyone." << endl;
    fs << "How are you all?" << endl;

    fs.close();  // Close the file after writing

    // Open file for reading
    fs.open("file.txt", ios::in);
    if (!fs) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;  // Exit the program with an error code
    }

    // Read data from the file and display it
    string line;
    while (getline(fs, line)) {
        cout << line << endl;
    }

    fs.close();  // Close the file after reading
    return 0;
}














/*
Theory:
What is file handling in C++?
Files store data permanently in a storage device. With file handling, the output from a
program canbe stored in a file. Various operations can be performed on the datawhilein the file.  How to create a file.  How to Open file.  How to Write to file.  How to read from file.
How to Close Files in C++
It is considered good practice, and it can clean up unnecessary memory space.
// Close
the file
MyFile.c
lose();
How to create a file ???
  
To create a file, use either the ofstream or fstream class, and specify the name of the
file.
How to Open Files???
  
Before performing any operation on a file, you must first open it.
If you need to write to the file:
open it using fstream or ofstream objects.
If you only need to read from the file:
open it using the ifstream object.
The three objects, that is, fstream, ofstream, and ifstream, have the open() function
defined inthem.
The function takes this syntax:
open (file_name, mode);
How to read from file??
 You can read information from files into your C++ program. This is possible
using stream extraction operator (>>). You use the operator in the samewayyou use it to read user inputfrom the keyboard. However, instead of usingthe
cin object, you use the ifstream/ fstream object.

ios
├── istream (Input Stream)
│   └── ifstream (Input File Stream)
├── ostream (Output Stream)
│   ├── ofstream (Output File Stream)
│   └── clog (Log Stream)
└── iostream (Input/Output Stream)
    └── fstream (File Stream: Input + Output)
ostream:

Base class for output operations.
Used for writing data (e.g., cout writes to the console).
ofstream inherits ostream to handle file output.
istream:

Base class for input operations.
Used for reading data (e.g., cin reads from the keyboard).
ifstream inherits istream to handle file input.
fstream:
used to create file
Combines both istream and ostream.
Allows reading from and writing to the same file.


the fstream library -
  • ofstream– This class represents an output stream. It’s used for creating files and writing information to files.
  • ifstream– This class represents an input stream. It’s used for reading information from data files.
  • fstream– This class generally represents a file stream. It comes with ofstream/ifstream capabilities. This means it’s capable of creating files, writing to files, reading from data files.

*/
