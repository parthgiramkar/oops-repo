#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dob;
    string bloodGroup;
    string address;
    string telephoneNumber;
    string drivingLicenseNo;

    static int StudentCount; // Static member to track total students

public:
    // Default Constructor
    Student() : name(""), rollNumber(0), className(""), division(' '), dob(""), bloodGroup(""), address(""), telephoneNumber(""), drivingLicenseNo("") {
        StudentCount++;
    }

    // Parameterized Constructor
    Student(string n, int roll, string c, char div, string dob, string bg, string addr, string tel, string dl)
        : name(n), rollNumber(roll), className(c), division(div), dob(dob), bloodGroup(bg), address(addr), telephoneNumber(tel), drivingLicenseNo(dl) {
        StudentCount++;
    }

    // Destructor
    ~Student() {
        StudentCount--;
    }

    // Static function to get the total student count
    static int getStudentCount() {
        return StudentCount;
    }

    // Function to input student details
    void setValues() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter Class: ";
        getline(cin, className);
        cout << "Enter Division: ";
        cin >> division;
        cin.ignore();
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        getline(cin, dob);
        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Telephone Number: ";
        getline(cin, telephoneNumber);
        cout << "Enter Driving License No: ";
        getline(cin, drivingLicenseNo);
    }

    // Inline function to display student details
    inline void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
    }
};

int Student::StudentCount = 0; // Initialize static member

int main() {
    int no;
    cout << "Enter the number of Students: ";
    cin >> no;

    Student* students = new Student[no]; // Dynamic memory allocation

    for (int i = 0; i < no; i++) {
        cout << "\nEntering details for Student " << (i + 1) << ":" << endl;
        students[i].setValues();
    }

    cout << "\nStudent Details:\n";
    for (int i = 0; i < no; i++) {
        cout << "\nStudent " << (i + 1) << " Details:" << endl;
        students[i].display();
    }

    cout << "\nTotal Number of Students: " << Student::getStudentCount() << endl;

    delete[] students; // Free dynamically allocated memory

    return 0;
}

   

   







/* 
  Title: Student Database using constructor, destructor, static member functions, friend
class, this pointer, inline code and dynamic memory allocation.
Constructor:
A special method of the class that will be automatically invoked when an instance of the class is created
is called as constructor. Following are the most useful features of constructor.
1) Constructor is used for Initializing the values to the data members of the Class.
2) Constructor is that whose name is same as name of class.
3) Constructor gets Automatically called when an object of class is created.
Constructors can be classified into 3 types
1. Default Constructor
2. Parameterized Constructor
3. Copy Constructor
1. Default Constructor: - Default Constructor is also called as Empty Constructor which has
no arguments and It is Automatically called when we create the object of class but
Remember name of Constructor is same as name of class and Constructor never declared
with the help of Return Type. Means we can’t declare a Constructor with the help of void
Return Type., if we never Pass or declare any Arguments then this called as the Copy
Constructors.
2. Parameterized Constructor: - This is another type constructor which has some Arguments
and same name as class name but it uses some Arguments So For this, we have to create
object of Class by passing some Arguments at the time of creating object with the name of
class. When we pass some Arguments to the Constructor then this will automatically pass
the Arguments to the Constructor and the values will retrieve by the Respective Data
Members of the Class.
3. Copy Constructor: - This is also another type of Constructor. In this Constructor we pass
the object of class into the Another Object of Same Class. As name Suggests you Copy,
means Copy the values of one Object into the another Object of Class.
Destructor:
As we know that Constructor is that which is used for Assigning Some Values to
data Members and For Assigning Some Values this May also used Some Memory so that to
free up the Memory which is Allocated by Constructor, destructor is used which gets
Automatically Called at the End of Program and we doesn’t have to Explicitly Call a
Destructor and Destructor Can’t be Parameterized or a Copy This can be only one Means
Default Destructor which Have no Arguments. For Declaring a Destructor, we have to use
~tiled Symbol in front of Destructor.
Static members
A class can contain static members, either data or functions. A static member variable has
following properties:
• It is initialized to zero when the first object of its class is created. No other
initialization is permitted.
• Only one copy of that member is created for the entire class and is shared by all the
objects of that class.
• It is the visible only within the class but its lifetime is the entire program

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

