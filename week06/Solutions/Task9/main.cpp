#include <iostream>
#include <fstream>
using namespace std;

const int MIN = 0;
const int MAX = 999;
const int PERFORMACE_RECORDS = 5;
const int IGNORE_LENGTH = 100;

int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    int generatedRandomNumber = (rand() % (max + 1)) + min;
    return generatedRandomNumber;
}

void saveLastGame(const char* filePath, int movesTaken) {
    ofstream outputFileStream;
    outputFileStream.open(filePath, ios::out);

    if(outputFileStream.is_open()) {
        outputFileStream << "**** Last game statistics ****" << endl;
        outputFileStream << "Moves taken: " << movesTaken;
        outputFileStream.close();
        cout << "\nLast game saved.\n";
    } else {
        cerr << "\n\nProblem saving last game. File could not be created.\n\n" << endl;
    }
}

int loadScoreboard(const char* filePath, int* topPerformances) {
    ifstream inputFileStream;
    inputFileStream.open(filePath, ios::in);

    if(!inputFileStream.is_open()) { // try to create the file if the reason it couldn't be opened was due to it's non-existence
        ofstream outputFileStream(filePath, ios::out);
        outputFileStream.close();
        inputFileStream.open(filePath, ios::in); // try to open the file again
    }

    if(inputFileStream.is_open()) {
        int counter = 0;
        inputFileStream.ignore(IGNORE_LENGTH, '\n'); // ignoring the first row
        while(!inputFileStream.eof()) {
            inputFileStream.ignore(IGNORE_LENGTH, ' ');
            inputFileStream >> topPerformances[counter++];
            inputFileStream.ignore();
            inputFileStream.peek();
        }
        inputFileStream.close();
        return counter;
    } else {
        cerr << "\n\nProblem loading scoreboard. File could not be opened.\n\n" << endl;
        return -1;
    }
}

void saveScoreboardToFile(const char* filePath, int* scoreboard, int performancesToSave) {
    ofstream outputFileStream;
    outputFileStream.open(filePath, ios::out);
    if(outputFileStream.is_open()) {
        outputFileStream << "**** Top " << performancesToSave << " ****" << endl;
        for(int i = 0; i < performancesToSave; i++) {
            outputFileStream << i + 1 << ") " << scoreboard[i] << endl;
        }
        outputFileStream.close();
        cout << "\nScoreboard updated.\n\n";
    } else {
        cerr << "\n\nProblem updating the scoreboard. File could not be created/updated.\n\n" << endl;
    }
}

void updateScoreboard(const char* filePath, int movesTaken) {
    int scoreboard[PERFORMACE_RECORDS];
    int loadedPerformances = loadScoreboard(filePath, scoreboard);
    
    int performancesToSave = 0;
    bool newRecordMade = false;
    if (loadedPerformances == -1) {
        return;
    } else if (loadedPerformances == 0) {
        scoreboard[0] = movesTaken;
        newRecordMade = true;
        performancesToSave = 1;
    } else {
        for(int i = 0; i < loadedPerformances; i++) {
            if(movesTaken < scoreboard[i]) {
                int lastIdx = loadedPerformances < PERFORMACE_RECORDS ? loadedPerformances : loadedPerformances - 1;
                for(int j = lastIdx; j > i; j--) {
                    scoreboard[j] = scoreboard[j - 1];
                }
                scoreboard[i] = movesTaken;
                newRecordMade = true;
                performancesToSave = lastIdx + 1;
                break;
            }
        }

        if(!newRecordMade && loadedPerformances < PERFORMACE_RECORDS) {
            scoreboard[loadedPerformances] = movesTaken;
            newRecordMade = true;
            performancesToSave = loadedPerformances + 1;
        }
    }

    if(newRecordMade) {
        saveScoreboardToFile(filePath, scoreboard, performancesToSave);
    }
}


int main() {
    int randomNumber = generateRandomNumber(MIN, MAX);

    int userInput, moves = 0;
    do {
       cout << "Make a guess: ";
       cin >> userInput;
       if(userInput < randomNumber) {
           cout << "Your guess is lower than the random number." << endl;
       }

       if(userInput > randomNumber) {
           cout << "Your guess is higher than the random number." << endl;
       }

       moves++;
    } while(userInput != randomNumber);
    cout << "Moves taken: " << moves << endl;

    const char* lastGameFilePath = "lastGame.txt";
    const char* scoreboardFilePath = "scoreboard.txt";
    saveLastGame(lastGameFilePath, moves);
    updateScoreboard(scoreboardFilePath, moves);

    return 0;
}