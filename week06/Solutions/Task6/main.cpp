#include <iostream>
#include <fstream>
using namespace std;

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

void saveNumbersInFiles(char* evenFilePath, char* oddFilePath, int min, int max) {
    ofstream outputFileStreamEvenNumbers, outputFileStreamOddNumbers;
    outputFileStreamEvenNumbers.open(evenFilePath, ios::out);
    outputFileStreamOddNumbers.open(oddFilePath, ios::out);

    if(!outputFileStreamEvenNumbers.is_open()) {
        printErrorMessage(evenFilePath);
        return;
    }

    if(!outputFileStreamOddNumbers.is_open()) {
        printErrorMessage(oddFilePath);
        return;
    }

    for(int i = min; i <= max; i++) {
        if(i % 2 == 0) {
            outputFileStreamEvenNumbers << i << endl;
        } else {
            outputFileStreamOddNumbers << i << endl;
        }
    }

    outputFileStreamEvenNumbers.close();
    outputFileStreamOddNumbers.close();

    printSuccessMessage(evenFilePath);
    printSuccessMessage(oddFilePath);
}

int main() {
    int min, max;
    cout << "Lower bound: ";
    cin >> min;
    cout << "Upper bound: ";
    cin >> max;

    char* evenFilePath = "evenNumbers.txt";
    char* oddFilePath = "oddNumbers.txt";

    saveNumbersInFiles(evenFilePath, oddFilePath, min, max);
    return 0;
}