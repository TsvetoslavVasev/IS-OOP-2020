#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 100;

struct Student {
    char name[MAX_SIZE];
    int facultyNumber;
    int age;
};

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

void saveStudentInfoInFile(char* outputFilePath, Student student) {
    ofstream outputFileStream;
    outputFileStream.open( outputFilePath, ios::out);
    if(outputFileStream.is_open()) {
        outputFileStream << "Name: " << student.name << endl;
        outputFileStream << "Faculty number: " << student.facultyNumber << endl;
        outputFileStream << "Age: " << student.age;
        outputFileStream.close();
        printSuccessMessage(outputFilePath);
    } else {
        printErrorMessage( outputFilePath);
    }
}

Student retrieveStudentInfo() {
    Student student;
    cout << "What's your name: ";
    cin.getline(student.name, MAX_SIZE);
    cout << "What's your faculty number: ";
    cin >> student.facultyNumber;
    cout << "What's your age: ";
    cin >> student.age;

    return student;
}


int main() {
    char* outputFilePath = "studentInfo.txt";
    Student student = retrieveStudentInfo();
    saveStudentInfoInFile(outputFilePath, student);

    return 0;
}