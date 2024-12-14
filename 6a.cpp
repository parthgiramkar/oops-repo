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
