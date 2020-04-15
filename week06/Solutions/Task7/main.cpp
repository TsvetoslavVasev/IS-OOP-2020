#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 100;
const int NUMBER_OF_BITS = 32;

int main() {
    int userNumbers[MAX_SIZE];
    int count;
    cout << "How many numbers do you want to enter: ";
    cin >> count;

    for(int i = 0; i < count; i++) {
        cout << "Enter a number: ";
        cin >> userNumbers[i];
    }

    char* filePath = "numbers.txt";
    ofstream outputFileStream;
    outputFileStream.open(filePath, ios::out);

    if(outputFileStream.is_open()) {
        for(int i = 0; i < count; i++) {
            outputFileStream << userNumbers[i] << " <-> " << bitset<NUMBER_OF_BITS>(userNumbers[i]).to_string() << endl;
        }
        outputFileStream.close();
    }


    return 0;
}