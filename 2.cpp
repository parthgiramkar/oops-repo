#include <iostream>
#include <string>
using namespace std;

class Student;

// Friend class
class Display {
public:
    void showDetails(const Student& s);
};

class Student {
private:
    string *rollNo, *name, *dob, *bloodGroup, *cls, *div, *address, *telephone, *licenseNo;

public:
    // Constructor to initialize data using dynamic memory allocation
    Student() {
        rollNo = new string;
        name = new string;
        dob = new string;
        bloodGroup = new string;
        cls = new string;
        div = new string;
        address = new string;
        telephone = new string;
        licenseNo = new string;
    }

    // Inline function to input details
    inline void inputDetails() {
        cout << "Enter Roll No: ";
        getline(cin, *rollNo); // using getline to handle spaces
        cout << "Enter Name: ";
        getline(cin, *name); // using getline to handle spaces
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        getline(cin, *dob); // using getline to handle spaces
        cout << "Enter Blood Group: ";
        getline(cin, *bloodGroup); // using getline to handle spaces
        cout << "Enter Class: ";
        getline(cin, *cls); // using getline to handle spaces
        cout << "Enter Division: ";
        getline(cin, *div); // using getline to handle spaces
        cout << "Enter Contact Address: ";
        getline(cin, *address); // using getline to handle spaces
        cout << "Enter Telephone Number: ";
        getline(cin, *telephone); // using getline to handle spaces
        cout << "Enter Driving License Number: ";
        getline(cin, *licenseNo); // using getline to handle spaces
    }

    // Destructor to release allocated memory
    ~Student() {
        delete rollNo;
        delete name;
        delete dob;
        delete bloodGroup;
        delete cls;
        delete div;
        delete address;
        delete telephone;
        delete licenseNo;
    }

    // Friend function to display details
    friend void Display::showDetails(const Student& s);
};

// Member function of friend class to display student details
void Display::showDetails(const Student& s) {
    cout << "\nStudent Details:" << endl;
    cout << "Roll No: " << *s.rollNo << endl;
    cout << "Name: " << *s.name << endl;
    cout << "Date of Birth: " << *s.dob << endl;
    cout << "Blood Group: " << *s.bloodGroup << endl;
    cout << "Class: " << *s.cls << endl;
    cout << "Division: " << *s.div << endl;
    cout << "Contact Address: " << *s.address << endl;
    cout << "Telephone: " << *s.telephone << endl;
    cout << "Driving License No: " << *s.licenseNo << endl;
}

int main() {
    Student s1;
    Display d1;

    // Input and display student details
    s1.inputDetails();
    d1.showDetails(s1);

    return 0;
}





/*
Title: Student Database using constructor, friend class, this pointer, inline code and
dynamic memory allocation.
Theory:
Friend functions:
In principle, private and protected members of a class cannot be accessed from outside the
same class in which they are declared. However, this rule does not affect friends. Friends are
functions or classes declared as such. If we want to declare an external function as friend of a
class, thus allowing this function to have access to the private and protected members of this
class, we do it by declaring a prototype of this external function within the class, and
preceding it with the keyword friend.
Properties of friend function:
• It is not in the scope of the class to which it has been declared as friend.
• Since it is not in the scope of the class , it cannot be called using the object of that
class
• It can be invoked like a normal function w/o the help of any object.
• It can be declared in private or in the public part of the class.
• Unlike member functions, it cannot access the member names directly and has to
use an object name and dot operator with each member name.
A pointer is a derived data type that refers to another data variable by storing the variables
memory address rather than data.
Declaration of pointer variable is in the following form-
  Data_type * ptr_var;
*/


