#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string rollNo;
    string name;
    string dob;
    string bloodGroup;
    string studentClass;
    char division;
    string contactAddress;
    string phoneNumber;
    string drivingLicense;
    static int studentCount; // Static member to count number of students

public:
    // Default constructor
    Student() {
        rollNo = "N/A";
        name = "N/A";
        dob = "N/A";
        bloodGroup = "N/A";
        studentClass = "N/A";
        division = 'N';
        contactAddress = "N/A";
        phoneNumber = "N/A";
        drivingLicense = "N/A";
        studentCount++;
    }

    // Parameterized constructor
    Student(string r, string n, string d, string bg, string sc, char div, string ca, string ph, string dl) {
        rollNo = r;
        name = n;
        dob = d;
        bloodGroup = bg;
        studentClass = sc;
        division = div;
        contactAddress = ca;
        phoneNumber = ph;
        drivingLicense = dl;
        studentCount++;
    }

    // Copy constructor
    Student(const Student &s) {
        rollNo = s.rollNo;
        name = s.name;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        studentClass = s.studentClass;
        division = s.division;
        contactAddress = s.contactAddress;
        phoneNumber = s.phoneNumber;
        drivingLicense = s.drivingLicense;
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Static member function
    static int getStudentCount() {
        return studentCount;
    }

    // Function to display student details
    void display() {
        cout << "\nStudent Details:" << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Driving License: " << drivingLicense << endl;
    }
};

// Initialize static member
int Student::studentCount = 0;

int main() {
    // Default constructor
    Student student1;

    // Parameterized constructor
    Student student2("101", "John Doe", "01-01-2000", "O+", "12th", 'A', "123 Street, City", "9876543210", "DL123456");

    // Copy constructor
    Student student3 = student2;

    // Display details
    student1.display();
    student2.display();
    student3.display();

    // Display student count
    cout << "\nTotal Students: " << Student::getStudentCount() << endl;

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
*/

