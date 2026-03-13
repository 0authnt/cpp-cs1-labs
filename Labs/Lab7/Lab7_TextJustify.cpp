#include <fstream>
#include <string>
#include <iostream>

using std::string;
using std::ifstream; using std::ofstream;
using std::cin; using std::cout; using std::endl;

string justify75(const string& line) {
    // Split into words using a simple array (max 50 words)
    string words[50];
    int wordCount = 0;
    string current = "";
    int length = (int)line.size();

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

    // If empty line: return as-is
    if (wordCount == 0) {
        return "";
    }

    // Count letters only (no spaces)
    int totalLetters = 0;
    for (int i = 0; i < wordCount; i++) {
        totalLetters = totalLetters + (int)words[i].size();
    }

    // If only one word: pad spaces to reach 75
    if (wordCount == 1) {
        string result = words[0];
        // add trailing spaces to hit 75 characters
        while ((int)result.size() < 75) {
            result = result + " ";
        }
        return result;
    }

    // Compute spaces to distribute
    int totalSpaces = 75 - totalLetters;           // total spaces needed
    int gaps = wordCount - 1;                      // number of gaps between words
    int spacesBetween = totalSpaces / gaps;        // base spaces per gap
    int extraSpaces = totalSpaces % gaps;          // leftover spaces

    // Build the justified line
    string result = "";
    for (int i = 0; i < wordCount - 1; i++) {
        result = result + words[i];

        // add the even number of spaces
        for (int j = 0; j < spacesBetween; j++) {
            result = result + " ";
        }

        // distribute the leftover spaces from the left
        if (extraSpaces > 0) {
            result = result + " ";
            extraSpaces--;
        }
    }
    // last word, no spaces after
    result = result + words[wordCount - 1];

    return result;
}

int main() {
    // input file name
    cout << "Input file name to print: ";
    string fileName;
    cin >> fileName;

    // open input
    ifstream fin(fileName);
    if (!fin) {
        cout << "Cannot open input file." << endl;
        return 0;
    }

    // open output
    ofstream fout("justified.txt");
    if (!fout) {
        cout << "Cannot open output file." << endl;
        return 0;
    }

    // process each line: justify to 75 and write out
    string line;
    while (std::getline(fin, line)) {
        string out = justify75(line);
        fout << out << '\n';
    }

    fin.close();
    fout.close();

    cout << "Output written to justified.txt" << endl;
    return 0;
}