#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PersonalRecord {
public:
    string name;
    string dob;  // Date of Birth
    string phoneNumber;

    // Constructor to initialize the personal record
    PersonalRecord(string n, string d, string p) : name(n), dob(d), phoneNumber(p) {}

    // Function to display record details
    void display() const {
        cout << "Name: " << name << ", DOB: " << dob << ", Phone: " << phoneNumber << endl;
    }
};

void addRecord(vector<PersonalRecord>& records) {
    string name, dob, phone;
    cout << "\nEnter Name: ";
    getline(cin, name);
    cout << "Enter DOB: ";
    getline(cin, dob);
    cout << "Enter Phone Number: ";
    getline(cin, phone);

    records.push_back(PersonalRecord(name, dob, phone));
}

void displayRecords(const vector<PersonalRecord>& records) {
    cout << "\nDisplaying all records:" << endl;
    for (int i = 0; i < records.size(); i++) {
        records[i].display();
    }
}

void sortRecords(vector<PersonalRecord>& records) {
    for (int i = 0; i < records.size() - 1; i++) {
        for (int j = i + 1; j < records.size(); j++) {
            if (records[i].name > records[j].name) {
                // Swap the records if they are in the wrong order
                PersonalRecord temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }
    cout << "\nRecords sorted by Name." << endl;
}

void searchRecord(const vector<PersonalRecord>& records) {
    string searchName;
    cout << "\nEnter name to search: ";
    getline(cin, searchName);

    for (int i = 0; i < records.size(); i++) {
        if (records[i].name == searchName) {
            cout << "\nRecord found:\n";
            records[i].display();
            return;
        }
    }

    cout << "\nRecord not found!" << endl;
}

int main() {
    vector<PersonalRecord> records;
    int choice;

    do {
        cout << "\nMenu:"
             << "\n1. Add Record"
             << "\n2. Display Records"
             << "\n3. Sort Records by Name"
             << "\n4. Search Record by Name"
             << "\n5. Exit"
             << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();  // To clear the newline character from input buffer

        switch (choice) {
            case 1:
                addRecord(records);
                break;
            case 2:
                displayRecords(records);
                break;
            case 3:
                sortRecords(records);
                break;
            case 4:
                searchRecord(records);
                break;
            case 5:
                cout << "\nExiting program." << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 5);

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
