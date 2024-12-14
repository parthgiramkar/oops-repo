#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Define a class to hold personal records
class PersonalRecord {
private:
    string name;
    string dob;   // Date of Birth in YYYY-MM-DD format
    string phoneNumber;

public:
    // Constructor for ease of record creation
    PersonalRecord(string n, string d, string p) : name(n), dob(d), phoneNumber(p) {}

    // Function to display record details
    void display() const {
        cout << "Name: " << name << ", DOB: " << dob << ", Phone: " << phoneNumber << endl;
    }

    // Getter for name (for searching and deleting)
    string getName() const {
        return name;
    }
};

// Function to insert a record
void insertRecord(vector<PersonalRecord>& records) {
    string name, dob, phone;
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Date of Birth (YYYY-MM-DD): ";
    getline(cin, dob);
    cout << "Enter Phone Number: ";
    getline(cin, phone);

    records.push_back(PersonalRecord(name, dob, phone));
    cout << "Record inserted successfully.\n";
}

// Function to display all records
void displayRecords(const vector<PersonalRecord>& records) {
    if (records.empty()) {
        cout << "No records available.\n";
    } else {
        for (size_t i = 0; i < records.size(); ++i) {
            records[i].display();  // No error now, because display() is const
        }
    }
}

// Function to search for a record by name
void searchRecord(const vector<PersonalRecord>& records) {
    string searchName;
    cout << "Enter name to search: ";
    getline(cin, searchName);

    for (size_t i = 0; i < records.size(); ++i) {
        if (records[i].getName() == searchName) {
            cout << "Record found:\n";
            records[i].display();  // No error now, because display() is const
            return;
        }
    }

    cout << "Record not found.\n";
}

// Function to sort records by name
void sortRecords(vector<PersonalRecord>& records) {
    sort(records.begin(), records.end(), [](const PersonalRecord& a, const PersonalRecord& b) {
        return a.getName() < b.getName();
    });
    cout << "Records sorted by name.\n";
}

// Function to delete a record by name
void deleteRecord(vector<PersonalRecord>& records) {
    string deleteName;
    cout << "Enter name to delete: ";
    getline(cin, deleteName);

    for (size_t i = 0; i < records.size(); ++i) {
        if (records[i].getName() == deleteName) {
            records.erase(records.begin() + i);
            cout << "Record deleted successfully.\n";
            return;
        }
    }

    cout << "Record not found.\n";
}

// Main function with menu
int main() {
    vector<PersonalRecord> records;
    int choice;

    do {
        cout << "\n***** Menu *****\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Search\n";
        cout << "4. Sort\n";
        cout << "5. Delete\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Consume newline character left in the buffer

        switch (choice) {
            case 1:
                insertRecord(records);
                break;
            case 2:
                displayRecords(records);
                break;
            case 3:
                searchRecord(records);
                break;
            case 4:
                sortRecords(records);
                break;
            case 5:
                deleteRecord(records);
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}






/*
STL:
The Standard Template Library (STL) is a set of C++ template classes to provide commonprogramming data structures and functions such as lists, stacks, arrays, etc. It is a library
of containerclasses, algorithms, and iterators. It is a generalized library and so, its
components are parameterized.A working knowledge of template classes is a
prerequisite for working with STL.
STL has four components
• Algorithms
• Containers
• Functions
• Iterators
Algorithms
• The algorithm defines a collection of functions especially designed to be used
on ranges of elements.They act on containers and provide means for various
operations for the contents ofthe containers. • Algorithm
• Sorting
• Searching
• Important STL Algorithms
• Useful Array algorithms
• Partition Operations
• Numeric

Containers
• Containers or container classes store objects and data. There are in total seven standard“firstclass” containerclasses and three container adaptor classes and only seven header files thatprovide access to these containers or container adaptors. • Sequence Containers: implement data structures which can be accessed in a sequential manner.• vector
• list • deque
• arrays
• forward_list( Introduced in C++11)
• Container Adaptors : provide a different interface for sequential containers. • queue
• priority_queue
• stack
• Associative Containers : implement sorted data structures that can be quickly
searched (O(logn) complexity). • set • multiset • map
• multimap
• Unordered Associative Containers : implement unordered data structures that canbequicklysearched
• unordered_set • unordered_multiset • unordered_map
• unordered_multimap
•Functions
The STL includes classes that overload the function call operator. Instances of suchclasses are calledfunction objects or functors. Functors allow the working of the
associated function to be customized with the help of parameters to be passed.
Iterators
• As the name suggests, iterators are used for working upon a sequence of values.
They are themajor feature that allow generality in STL.
Utility Library
• Defined in header <utility>. • Pair
Sorting
It is one of the most basic functions applied to data. It means arranging the data in a particular 
fashion,which can be increasing or decreasing. There is a builtin function in C++ STLbythenameof sort().
This function internally uses IntroSort. In more details it is implemented using hybrid of
QuickSort, HeapSort and InsertionSort.
By default, it uses QuickSort but if QuickSort is doing unfair partitioningand taking morethan
N*logN time, it switches to HeapSort and when the array size becomes really small, it switchestoInsertionSort.
The prototype for sort is :
sort(startaddress, endaddress)
startaddress: the address of the first element of the array
endaddress: the address of the next contiguous location of the last element
Searching:
It is a widely used searching algorithm that requires the array to be sorted before searchis
applied. The main idea behind this algorithm is to keep dividing the array in half (divide
and conquer) until theelement is found, or all the elements are exhausted.

*/
