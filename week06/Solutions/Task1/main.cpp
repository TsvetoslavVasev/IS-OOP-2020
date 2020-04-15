#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 1000;

void printSuccessMessage(char* filePath) {
    cout << "\n\n";
    cout << "=================================================================" << endl;
    cout << "Successfully read file content from file: " << filePath << endl;
    cout << "=================================================================" << endl;
    cout << "\n\n";
}

void printErrorMessage(char* filePath) {
    cerr << "\n\n";
    cerr << "There was a problem opening file with name: " << filePath << endl;
    cerr << "Program stopped." << endl;
    cerr << "\n\n";
}

int main() {
    char* filePath = "myInterestingFile.txt";

    ifstream inputFileStream;
    inputFileStream.open(filePath, ios::in);

    if(inputFileStream.is_open()) {
        char lineFromFile[MAX_SIZE];
        while(!inputFileStream.eof()) {
            inputFileStream.getline(lineFromFile, MAX_SIZE);
            cout << lineFromFile << endl;
        }
        inputFileStream.close();
        printSuccessMessage(filePath);
    } else {
        printErrorMessage(filePath);
    }

    return 0;
}