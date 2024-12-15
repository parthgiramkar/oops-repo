#include<iostream>
using namespace std;

class complex {
    float real, imag;
    
public:
    complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    complex operator+ (complex &c1) {
        complex c3;
        c3.real = real + c1.real;
        c3.imag = imag + c1.imag;
        return c3;
    }

    complex operator* (complex &c1) {
        complex c3;
        c3.real = real * c1.real - imag * c1.imag;
        c3.imag = real * c1.imag + imag * c1.real;
        return c3;
    }

    friend istream  &operator>>(istream &in, complex &c2) {
        cout << "Enter the real part: ";
        in >> c2.real;
        cout << "Enter the imaginary part: ";
        in >> c2.imag;
        return in;
    }

    friend ostream &operator<<(ostream &out, complex &c2) {
        out << c2.real << "+" << c2.imag << "i";
        return out;
    }
};

int main() {
    complex c1, c2, c3;
    cout << "Enter the first complex number:" << endl;
    cin >> c1;
    cout << "Enter the second complex number:" << endl;
    cin >> c2;
    c3 = c1 + c2;
    cout << "Sum: " << c3 << endl;
    c3 = c1 * c2;
    cout << "Product: " << c3 << endl;
    return 0;
}







/*
Operator Overloading
It is a specific case of polymorphism where different operators have different
implementations dependingon their arguments. In C++ the overloading principle applies not
only to functions, but to operators too. That is, of operators can be extended to work not just
with built-in types but also classes. A programmer can provide his or her own operatortoaclass by overloading the built-in operator to perform some specific computationwhen the
operator is used on objects of that class
Overloaded + operator: Adds two complex numbers by adding their real parts and imaginary parts separately.
Overloaded * operator: Multiplies two complex numbers using the formula-
(a+bi)(c+di)=(ac−bd)+(ad+bc)i

Overloaded << operator: Prints a complex number in the form a + bi or a - bi.
Overloaded >> operator: Reads the real and imaginary parts of a complex number from the input.
Arithmetic Operators
Arithmetic Operators are used to do basic arithmetic operations like addition,
subtraction,multiplication, division, and modulus
    */
  
