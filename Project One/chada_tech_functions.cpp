/* 
* Set of functions for the chada_tech project
* Author: Danforth Morrigan
* Date: 2023-09-15 
*/
// function definitions
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// this function uses recursion to ensures valid times
void initialTime(int& hour, int& minute, int& second) {
    cout << "Initial Clock Settings\n";
    cout << "Enter the hour: ";
    cin >> hour;
    cout << "Enter the minute: ";
    cin >> minute;
    cout << "Enter the second: ";
    cin >> second;
    // check for valid times
    if (hour > 23 || hour < 0 || minute > 59 || minute < 0 || second > 59 || second < 0) {
        initialTime(hour, minute, second);
    }
    cout << endl;
}

void displayMenu() {
    cout << right << setfill('*') << setw(28) << "*\n";
    cout << left << setfill(' ') << setw(26) << "* 1 - Add One Hour" << "*\n";
    cout << setw(26) << "* 2 - Add One Minute" << "*\n";
    cout << setw(26) << "* 3 - Add One Second" << "*\n";
    cout << setw(26) << "* 4 - Exit Program" << "*\n";
    cout << right << setfill('*') << setw(28) << "*\n";
    cout << endl;
}

void displayTime(int hour, int minute, int second) {
    // twelveHour is intentionally local to this function
    int twelveHour = hour;
    string ampm = "AM";
    // check for midnight
    if (hour == 0) {
        twelveHour = 12;
    }
    // check for noon
    else if (hour == 12) {
        ampm = "PM";
    }
    // check for afternoon
    else if (hour > 12) {
        twelveHour -= 12;
        ampm = "PM";
    }
    // this mess is to make the output look nice
    cout << endl;
    cout << right << setfill('*') << setw(30) << "* *" << setw(30) << "*\n";
    cout << "*      12-Hour Clock       * *       24-Hour Clock        *\n"; 
    cout << left << setfill(' ') << setw(8) << "*";
    cout << right << setfill('0') << setw(2) << twelveHour;
    cout << ":" << setfill('0') << setw(2) <<  minute;
    cout << ":" << setw(2) <<  second;
    cout << " " << ampm;
    cout << right << setfill(' ') << setw(11) << "* *";
    cout << left << setfill(' ') << setw(10) << " ";
    cout << right << setfill('0') << setw(2) << hour;
    cout << ":" << setw(2) << minute;
    cout << ":" << setw(2) << second;
    cout << setfill(' ') << setw(13) << " * \n";
    cout << right << setfill('*') << setw(30) << "* *" << setw(30) << "*\n";
    cout << endl;
}

void addHour(int& hour) {
    hour++;
    if (hour > 23) {
        hour = 0;
    }
}

bool addMinute(int& minute) {
    minute++;
    if (minute > 59) {
        minute = 0;
        return true;
    }
    return false;
}

bool addSecond(int& second) {
    second++;
    if (second > 59) {
        second = 0;
        return true;
    }
    return false;
}