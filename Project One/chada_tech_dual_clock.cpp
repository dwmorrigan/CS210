/*
* Chada Tech Dual Clock
* Author: Danforth Morrigan
* Date: 2023-09-15 
*/

#include <iostream>
#include "chada_tech_functions.cpp"

using namespace std;

int main() {
    // variables
    int hour = 0;
    int minute = 0;
    int second = 0;
    int choice = 0;
    bool exit = false;
    bool plus;

    // user inputs time
    initialTime(hour, minute, second);

    // display menu & get user input
    while (!exit) {
        plus = false; 
        displayMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            addHour(hour);
            break;
        case 2:
            plus = addMinute(minute);
            // if plus is true, that means the minute rolled over to 0
            if (plus) { addHour(hour); }
            break;
        case 3:
            plus = addSecond(second);
            // if plus is true, that means the second rolled over to 0
            if (plus) { plus = addMinute(minute); }
            // if plus is true, that means the minute also rolled over to 0
            if (plus) { addHour(hour); }
            break;
        case 4:
            exit = true;
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
        displayTime(hour, minute, second);
    }
    return 0;
}

