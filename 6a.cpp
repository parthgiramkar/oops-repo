#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Define a class to hold Item records
class Item {
private:
    string itemCode;
    string itemName;
    double cost;
    int quantity;

public:
    // Constructor to initialize an item
    Item(string code, string name, double c, int qty) : itemCode(code), itemName(name), cost(c), quantity(qty) {}

    // Function to display item details
    void display() const {
        cout << "Item Code: " << itemCode << ", Item Name: " << itemName
             << ", Cost: " << cost << ", Quantity: " << quantity << endl;
    }

    // Getter for item code (for searching and deleting)
    string getItemCode() const {
        return itemCode;
    }

    // Getter for item name (for sorting)
    string getItemName() const {
        return itemName;
    }

    // Getter for item cost
    double getCost() const {
        return cost;
    }

    // Getter for item quantity
    int getQuantity() const {
        return quantity;
    }
};

// Function to insert a new item
void insertItem(vector<Item>& items) {
    string code, name;
    double cost;
    int quantity;

    cout << "Enter Item Code: ";
    getline(cin, code);
    cout << "Enter Item Name: ";
    getline(cin, name);
    cout << "Enter Item Cost: ";
    cin >> cost;
    cout << "Enter Item Quantity: ";
    cin >> quantity;
    cin.ignore();  // Clear the newline character left in the input buffer

    items.push_back(Item(code, name, cost, quantity));
    cout << "Item inserted successfully.\n";
}

// Function to display all items
void displayItems(const vector<Item>& items) {
    if (items.empty()) {
        cout << "No items available.\n";
    } else {
        for (size_t i = 0; i < items.size(); ++i) {
            items[i].display();
        }
    }
}

// Function to search for an item by item code
void searchItem(const vector<Item>& items) {
    string searchCode;
    cout << "Enter Item Code to search: ";
    getline(cin, searchCode);

    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getItemCode() == searchCode) {
            cout << "Item found:\n";
            items[i].display();
            return;
        }
    }

    cout << "Item not found.\n";
}

// Function to sort items by item name
void sortItems(vector<Item>& items) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.getItemName() < b.getItemName();
    });
    cout << "Items sorted by name.\n";
}

// Function to delete an item by item code
void deleteItem(vector<Item>& items) {
    string deleteCode;
    cout << "Enter Item Code to delete: ";
    getline(cin, deleteCode);

    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getItemCode() == deleteCode) {
            items.erase(items.begin() + i);
            cout << "Item deleted successfully.\n";
            return;
        }
    }

    cout << "Item not found.\n";
}

// Main function with menu
int main() {
    vector<Item> items;
    int choice;

    do {
        cout << "\n***** Menu *****\n";
        cout << "1. Insert Item\n";
        cout << "2. Display Items\n";
        cout << "3. Search Item\n";
        cout << "4. Sort Items\n";
        cout << "5. Delete Item\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Consume newline character left in the buffer

        switch (choice) {
            case 1:
                insertItem(items);
                break;
            case 2:
                displayItems(items);
                break;
            case 3:
                searchItem(items);
                break;
            case 4:
                sortItems(items);
                break;
            case 5:
                deleteItem(items);
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
