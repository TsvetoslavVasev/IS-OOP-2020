#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 100;

void printErrorMessage(char* filePath) {
    cerr << "\n\n";
    cerr << "There was a problem opening file with name: " << filePath << endl;
    cerr << "\n\n";
}

int retrieveFileWordCount(char* filePath) {
    ifstream inputFileStream;
    inputFileStream.open(filePath, ios::in);

    if(inputFileStream.is_open()) {
        char wordFromFile[MAX_SIZE];
        int wordCounter = 0;
        while(!inputFileStream.eof()) {
            inputFileStream >> wordFromFile;
            wordCounter++;
        }
        inputFileStream.close();
        return wordCounter;
    } else {
        printErrorMessage(filePath);
        return -1;
    }
}
int main() {
    char* filePath = "file.txt";

    int fileWords = retrieveFileWordCount(filePath);
    if(fileWords == -1) {
        return 1;
    }

    cout << "Total words in file(" << filePath << "): " << fileWords << endl;
    return 0;
}