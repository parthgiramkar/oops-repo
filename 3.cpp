#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    Publication() : title(""), price(0.0) {}

    void setData() {
        cout << "Enter title: ";
        getline(cin >> ws, title);  // Use `cin >> ws` to discard leading whitespace, including newlines
        cout << "Enter price: ";
        cin >> price;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;
public:
    Book() : pageCount(0) {}

    void setData() {
        Publication::setData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void display() {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;
public:
    Tape() : playingTime(0.0) {}

    void setData() {
        Publication::setData();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }

    void display()  {
        Publication::display();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter details for Book:" << endl;
    book.setData();

    cout << "\nEnter details for Tape:" << endl;
    tape.setData();to you

    cout << "\nDetails of Book:" << endl;
    book.display();

    cout << "\nDetails of Tape:" << endl;
    tape.display();

    return 0;
}








/*
cin >> ws:

The ws manipulator skips any leading whitespace, including newlines left in the input buffer.
This ensures getline works correctly to read the full title after a numeric input.
Inheritance:
Inheritance in Object Oriented Programming can be described as a process of
creating new classes from existing classes. New classes inherit some of the properties
and behavior of the existing classes. An existing class that is "parent" of a new class is
called a base class. New class that inherits properties of the base class is called a
derived class. Inheritance is a technique of code reuse. It also provides possibility to
extend existing classes by creating derived classes.
    There are 3 access specifiers:
Namely public, private and
protected.
public:
This inheritance mode is used mostly. In this the protected member of
Base classbecomes protected members of Derived class and public
becomes public.
protected:
In protected mode, the public and protected members of Base class becomes
protectedmembers of Derived class.
private:
In private mode the public and protected members of Base class become privatemembersof Derived class.
    1. Single Inheritance
2. Multiple Inheritance
3. Hierarchical Inheritance
4. Multilevel Inheritance
5. Hybrid Inheritance
Single Inheritance:
In this type of inheritance one derived class inherits from only one base class.
It is themost simplest form of Inheritance.

    Multiple Inheritance: In this type of inheritance a single derived class may inherit from two or more than two base classes.
    Hierarchical Inheritance:
In this type of inheritance, multiple derived classes inherits from a single base class.
    */




