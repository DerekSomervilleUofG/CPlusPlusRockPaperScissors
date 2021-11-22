#pragma once
#include <vector>
#include <string>
using namespace std;
class Utilities
{
public:
    vector<string> parseByDelimiter(string row, char delimiter) {
        vector<string> listOfWords;
        string word = "";
        int wordSize = row.size();
        for (int counter = 0; counter < wordSize; counter++) {
            if (row.at(counter) == delimiter) {
                listOfWords.push_back(word);
                word = "";
            }
            else {
                word += row.at(counter);
            }
        }
        listOfWords.push_back(word);
        return listOfWords;

    }
};

