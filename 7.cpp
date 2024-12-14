#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Creating a map where key is state name and value is population
    map<string, int> statePopulation;

    // Adding some sample states and their populations to the map
    statePopulation["California"] = 39538223;
    statePopulation["Texas"] = 29145505;
    statePopulation["Florida"] = 21538187;
    statePopulation["New York"] = 20201249;
    statePopulation["Pennsylvania"] = 13002700;

    // Prompting user to input the name of a state
    string state;
    cout << "Enter the name of a state to be found : ";
    getline(cin, state);

    // Checking if the state exists in the map and displaying the population
    if (statePopulation.find(state) != statePopulation.end()) {
        cout << "The population of " << state << " is " << statePopulation[state] << endl;
    } else {
        cout << "State not found in the map." << endl;
    }

    return 0;
}






/*
Theory:
Map associative container:
Map associative container are associative containers that store elements in a mapped fashion. 
Each element has a key value and a mapped value. No two mapped values can have same key values. map::operator[]
This operator is used to reference the element present at position given inside the operator.
It is similar to the at() function, 
the only difference is that the at() function throws an out-of-range exception
when the position is not in the bounds of the size of map, while this operator causes undefined behaviour
*/
