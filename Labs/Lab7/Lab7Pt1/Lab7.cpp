#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    cout << "input line:\n";
    getline(cin, line);

    int length = line.size();
    if (length >= 75) {
        cout << "Line too long. Must be less than 75 characters." << endl;
        return 0;
    }

    // Split the line into words
    string words[50];
    int wordCount = 0;
    string current = "";

    for (int i = 0; i < length; i++) {
        if (line[i] == ' ') {
            if (current != "") {
                words[wordCount] = current;
                wordCount++;
                current = "";
            }
        } else {
            current = current + line[i];
        }
    }
    if (current != "") {
        words[wordCount] = current;
        wordCount++;
    }

    // Count total letters (not spaces)
    int totalLetters = 0;
    for (int i = 0; i < wordCount; i++) {
        totalLetters = totalLetters + words[i].size();
    }

    // Figure out how many spaces we need to reach 75 characters
    int totalSpaces = 75 - totalLetters;
    int spacesBetween = totalSpaces / (wordCount - 1);
    int extraSpaces = totalSpaces % (wordCount - 1);

    // Build justified line
    string result = "";
    for (int i = 0; i < wordCount - 1; i++) {
        result = result + words[i];

        // Add the even number of spaces
        for (int j = 0; j < spacesBetween; j++) {
            result = result + " ";
        }

        // Add one extra space until they run out
        if (extraSpaces > 0) {
            result = result + " ";
            extraSpaces--;
        }
    }

    // Add the last word (no space after)
    result = result + words[wordCount - 1];

    cout << "your line justified:\n" << result << endl;

    return 0;
}
