#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_SIZE = 100;

struct Student {
    char name[MAX_SIZE];
    int facultyNumber;
    int age;
};

enum SortOption {
    NAME,
    FN,
    AGE
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

void enterStudentDetails(Student& student) {
        cout << "Name: ";
        cin.getline(student.name, MAX_SIZE);
        cout << "Faculty number: ";
        cin >> student.facultyNumber;
        cout << "Age: ";
        cin >> student.age;
        cin.ignore();
}

void saveStudentsToFile(char* filePath, Student* students, int numberOfStudents) {
    ofstream outputFileStream;
    outputFileStream.open(filePath, ios::out);
    if(outputFileStream.is_open()) {
        for(int i = 0; i < numberOfStudents; i++) {
            outputFileStream << students[i].name << " " << students[i].facultyNumber << " " << students[i].age << endl;
        }
        printSuccessMessage(filePath);
        outputFileStream.close();
    } else {
        printErrorMessage(filePath);
    }
}

/**
 * sortStudents() uses the Bubble Sort algorithm to sort the students
 */
void sortStudents(Student* students, int numberOfStudents, SortOption sortOption) {
   for (int i = 0; i < numberOfStudents - 1; ++i) {
        for (int j = 0; j < numberOfStudents - i - 1; ++j) {
            if (sortOption == NAME) {
                if(strcmp(students[j].name, students[j + 1].name) > 0) {
                    swap(students[j], students[j + 1]);
                }
            } else if (sortOption == FN) {
                if(students[j].facultyNumber > students[j + 1].facultyNumber) {
                    swap(students[j], students[j + 1]);
                }
            } else { // sort by age by default
                if(students[j].age > students[j + 1].age) {
                    swap(students[j], students[j + 1]);
                }
            }
        }
   }
}

int main() {
    Student students[MAX_STUDENTS];

    int numberOfStudents;
    cout << "How many students are you going to enter: ";
    cin >> numberOfStudents;
    cin.ignore();

    for(int i = 0; i < numberOfStudents; i++) {
        cout << "\tStudent #" << i << "" << endl;
        enterStudentDetails(students[i]);
        cout << endl;
    }

    char outputFilePath[MAX_SIZE];
    cout << "File name to save the information to: ";
    cin >> outputFilePath;

    char userChoice;
    cout << "\nDo you want to sort the student information? (y/n) ";
    cin >> userChoice;

    if(userChoice == 'y') {
        cout << "\nChoose an attribute to sort by:\n 1) Name\n 2) Faculty Number\n 3) Age\n\nYour choice: ";
        do {
            cin >> userChoice;
        } while(userChoice < '1' || userChoice > '3');

        switch(userChoice) {
            case '1': sortStudents(students, numberOfStudents, NAME);
                      break;
            case '2': sortStudents(students, numberOfStudents, FN);
                      break;
            case '3': sortStudents(students, numberOfStudents, AGE);
                      break;
            default:  break; // it's not necessary to specify the default here
        }
    }

    saveStudentsToFile(outputFilePath, students, numberOfStudents);

    return 0;
}