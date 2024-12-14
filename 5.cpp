#include <iostream>
using namespace std;

// Function template for Selection Sort
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap the found minimum element with the first element
        T temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Function to print an array
template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int intSize, floatSize;
    
    // User input for integer array
    cout << "Enter the number of integers: ";
    cin >> intSize;
    int intArr[intSize];
    
    cout << "Enter the integers: ";
    for (int i = 0; i < intSize; i++) {
        cin >> intArr[i];
    }
    
    // User input for float array
    cout << "Enter the number of floats: ";
    cin >> floatSize;
    float floatArr[floatSize];
    
    cout << "Enter the floats: ";
    for (int i = 0; i < floatSize; i++) {
        cin >> floatArr[i];
    }

    // Display original arrays
    cout << "Original integer array: ";
    printArray(intArr, intSize);
    
    cout << "Original float array: ";
    printArray(floatArr, floatSize);
    
    // Sorting the integer array
    selectionSort(intArr, intSize);
    cout << "Sorted integer array: ";
    printArray(intArr, intSize);
    
    // Sorting the float array
    selectionSort(floatArr, floatSize);
    cout << "Sorted float array: ";
    printArray(floatArr, floatSize);
    
    return 0;
}





/*
Templates are the foundation of generic programming, which involves
writing code in a way thatis independent of any particular type.
A template is a blueprint or formula for creating a generic class or a function. Thelibrary containers like iterators
and algorithms are examples of generic programming
and have been developed using template concept. There is a single definition of each
container, such as vector, but we can define many different kinds of vectorsforexample, vector <int> or vector <string>.
You can use templates to define functions as well as classes, let us see howdotheywork:Function Template:
The general form of a template function definition is shown here:
template <class type> ret-type func-name(parameter list)
{
// body of function
}
Here, type is a placeholder name for a data type used by the function. This
name can be used within the function definition.

Class Template:
Just as we can define functionb templates, we can also define class templates. Thegeneral
form of a generic classdeclaration is shown here:
template <class type> class class-name
Selection Sort:
Selection sort is a sorting algorithm, specifically an in-place comparison sort. It has O(n2)timecomplexity, makingit inefficient on large lists, and
generally performs worse than the similar insertion sort. 
Selection sort is noted for its simplicity, and it has performance advantages over more complicated algorithms in certain situations,
particularly where auxiliarymemory is limited

*/
