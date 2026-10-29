 // File: P9-3.cpp
 // Description: Converts Roman numerals entered by the user to integers.
 // Author: Avery Conner

#include <iostream>
#include <string>
using namespace std;

// Function prototypes.
int romanCharValue(char r);
int convertRomanToInt(string s);

int main() {

    string input;

    // Continue accepting Roman numerals until the user enters Q.
    while (true) {
        cout << "Enter Roman number or Q to quit: ";
        getline(cin, input);

        if (input == "Q") {
            break;
        }

        cout << input << " = " << convertRomanToInt(input) << endl;

    }

    return 0;

}

// Return the value of an individual Roman numeral character

int romanCharValue(char r) {
    switch (r) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

// Convert a Roman numeral string to an integer.

int convertRomanToInt(string s) {

    int total = 0;

    while (s.length() > 0) {
        if (s.length() == 1 ||
            romanCharValue(s[0]) >= romanCharValue(s[1])) {
            total += romanCharValue(s[0]);
            s.erase(0, 1);
        }

        else {
            total += romanCharValue(s[1]) - romanCharValue(s[0]);
            s.erase(0, 2);
        }

    }

    return total;

}
