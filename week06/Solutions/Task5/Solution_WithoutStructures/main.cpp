#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 100;

void printSuccessMessage(char* filePath) {
    cout << "\n\n";
    cout << "=======================================================" << endl;
    cout << "Successfully saved content in file: " << filePath << endl;
    cout << "=======================================================" << endl;
    cout << "\n\n";
}

void printErrorMessage(char* filePath) {
    cerr << "\n\n";
    cerr << "There was a problem opening file with name: " << filePath << endl;
    cerr << "\n\n";
}

void saveStudentInfoInFile(char* outputFilePath, char* studentName, int facultyNumber, int age) {
    ofstream outputFileStream;
    outputFileStream.open( outputFilePath, ios::out);
    if(outputFileStream.is_open()) {
        outputFileStream << "Name: " << studentName << endl;
        outputFileStream << "Faculty number: " << facultyNumber << endl;
        outputFileStream << "Age: " << age;
        outputFileStream.close();
        printSuccessMessage(outputFilePath);
    } else {
        printErrorMessage( outputFilePath);
    }
}

void retrieveStudentInfo(char* outputFilePath) {
    char studentName[MAX_SIZE];
    int facultyNumber, age;

    cout << "What's your name: ";
    cin.getline(studentName, MAX_SIZE);
    cout << "What's your faculty number: ";
    cin >> facultyNumber;
    cout << "What's your age: ";
    cin >> age;

    saveStudentInfoInFile(outputFilePath, studentName, facultyNumber, age);
}


int main() {
    char* outputFilePath = "studentInfo.txt";
    retrieveStudentInfo(outputFilePath);

    return 0;
}