#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 1000;

void printErrorMessage(char* filePath) {
    cerr << "\n\n";
    cerr << "There was a problem opening file with name: " << filePath << endl;
    cerr << "\n\n";
}

int retrieveFileLineCount(char* filePath) {
    ifstream inputFileStream;
    inputFileStream.open(filePath, ios::in);

    if(inputFileStream.is_open()) {
        char lineFromFile[MAX_SIZE];
        int lineCounter = 0;
        while(!inputFileStream.eof()) {
            inputFileStream.getline(lineFromFile, MAX_SIZE);
            lineCounter++;
        }
        inputFileStream.close();
        return lineCounter;
    } else {
        printErrorMessage(filePath);
        return -1;
    }
}
int main() {
    char* file1Path = "file1.txt";
    char* file2Path = "file2.txt";

    int file1Lines = retrieveFileLineCount(file1Path);
    int file2Lines = retrieveFileLineCount(file2Path);

    if(file1Lines == -1 || file2Lines == -1) {
        return 1;
    }

    if(file1Lines == file2Lines) {
        cout << "Both files have the same number of lines." << endl;
    } else if (file1Lines > file2Lines) {
        cout << file1Path << " is longer than " << file2Path << endl;
    } else {
        cout << file2Path << " is longer than " << file1Path << endl;
    }

    return 0;
}