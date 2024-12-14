#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream fs;

    // Step 1: Open the file for writing
    fs.open("file.dat", ios::out);
    if (!fs) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    // Write data to the file
    fs << "Hello Everyone." << endl;
    fs << "How are you all?" << endl;
    fs.close(); // Close the file after writing

    // Step 2: Open the file for reading
    fs.open("file.dat", ios::in);
    if (!fs) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    // Read data from the file and display it
    string line;
    while (getline(fs, line)) {
        cout << line << endl;
    }
    fs.close(); // Close the file after reading

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

the fstream library -
  • ofstream– This class represents an output stream. It’s used for creating files and writing information to files.
  • ifstream– This class represents an input stream. It’s used for reading information from data files.
  • fstream– This class generally represents a file stream. It comes with ofstream/ifstream capabilities. This means it’s capable of creating files, writing to files, reading from data files.

*/
