// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isCardValid(int digits[], int SIZE);
vector<int> append(vector<int> a, vector<int> b);
//int quiztotal(int scores, string lastname[], string firstname[]);

const int STUDENTS = 4;
const int QUIZZES = 3;

int main() {
    // Part 1
   const int SIZE = 8;
    int digits[SIZE];
    int x = 0;
    bool done = false;
    while (done != true) {
        cout << "Enter 8-digit card # or Q to quit: ";
        cin >> x;
        if (cin.fail()) {
            done = true;
            break;
        }
        for (int i = 0; i < SIZE; i++){
            digits[i] = x % 10; 
            x = x / 10;
        }
        if (isCardValid(digits, SIZE) == true) {
            cout << "Card is valid." << endl; // won't display that card is valid for test run, has something to do with function
        }
        else {
            cout << "Card is not valid." << endl;
        }
    }

    // Part 2
    const int SIZE = 16;
    int digits[SIZE];
    long long x = 0;
    bool done = false;
    while (done != true) {
        cout << "Enter 16-digit card # or Q to quit: ";
        cin >> x;
        if (cin.fail()) {
            done = true;
            break;
        }
        for (int i = 0; i < SIZE; i++) {
            digits[i] = x % 10;
            x = x / 10;
        }
        if (isCardValid(digits, SIZE) == true) {
            cout << "Card is valid." << endl; // won't display that card is valid for test run
        }
        else {
            cout << "Card is not valid." << endl;
        }
    }


    // Part 3
    // create 2-D array with 4 rows of students having taken 2 quizzes...
    int scores[STUDENTS][QUIZZES];

    string firstname[] = { " ", " ", " ", " " };
    string lastname[] = { " ", " ", " ", " " };

    for (int i = 0; i < 4; i++) {
        cout << "Enter first and last name of student # " << i + 1 << ": ";
        cin >> firstname[i] >> lastname[i];
    }

    //Get the quiz data
    for (int qz = 0; qz < QUIZZES; qz++) {
        for (int st = 0; st < STUDENTS; st++) {
            cout << "Quiz " << (qz + 1) << " score for " << lastname[st] << ", " << firstname[st] << ": ";
            cin >> scores[st][qz];
        }
    }
    cout << endl;

    // calculate the average for each quiz
    for (int qz = 0; qz < QUIZZES; qz++) {
        int sum = 0;
        for (int st = 0; st < STUDENTS; st++) {
            sum += scores[st][qz];
        }
        cout << "Quiz " << (qz + 1) << " average: " << (double)sum / STUDENTS << endl;
    }
    cout << endl;

    // calculate the total score for each student
    for (int st = 0; st < STUDENTS; st++) {
        int total = 0;
        for (int qz = 0; qz < QUIZZES; qz++) {
            total += scores[st][qz];
        }
        cout << lastname[st] << ", " << firstname[st] << (st + 1) << " total score: " << total << endl;
    }
    cout << endl;

    return 0;

    // Part 4
    vector<int> a = { 1, 4, 9, 16 };
    vector<int> b = { 9, 7, 4, 9, 11 };

    a = append(a, b);

    for (int i = 0; i < a.size(); i++) {
        cout << a.at(i) << " ";
    }
}

bool isCardValid(int digits[], int SIZE) {
    int sum = 0;
    int sum2 = 0;
    int temp = 0;
    int temp2 = 0;
    for (int i = 1; i <= SIZE; i++) {
        int digit = digits[i];
        if (i % 2 == 1) {
            sum += digit;
        }
        if (i % 2 == 0) {
            temp = (digit * 2);
            for (int x = 1; x <= 2; x++) {
                temp2 = temp % 10;
                temp = temp / 10;
                sum2 += temp2;
            }
        }
    }
    int checksum = sum + sum2;
    if (checksum % 10 == 0) {
        return true;
    }
    else {
        return false;
    }
}

//int quiztotal(int scores, string lastname[], string firstname[]) {
//    for (int st = 0; st < STUDENTS; st++) {
//        int total = 0;
//        for (int qz = 0; qz < QUIZZES; qz++) {
//            total += scores[st][qz];
//        }
//        cout << lastname[st] << ", " << firstname[st] << (st + 1) << " total score: " << total << endl;
//    }
//cout << endl;
//}

vector<int> append(vector<int> a, vector<int> b) {
    vector<int> values;
    for (int i = 0; i < b.size(); i++) {
        a.push_back(b.at(i));
    }
    return a;
}