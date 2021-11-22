
#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include "Utilities.h"
#include <string>
using namespace std;
class ReadDelimitedFile
{

private:
    string fileDelimitor = ",";
    string splitByDelimitor;

public:
    ReadDelimitedFile() {

    }
    void setFileDelimitor(string fileDelimitor) {
        this->fileDelimitor = fileDelimitor;
    }

    vector<string> getFileData(string fileName) {
        vector<string> fileData = {};

        ifstream propertyFile;
        propertyFile.open(fileName);
        string row;
        while (getline(propertyFile, row)) {
            fileData.push_back(row);
        }

        return fileData;
    }

    vector<vector<string>> getDelimtiedFileData(string fileName) {
        vector<vector<string>> fileData = {};
        Utilities utilities = Utilities();
        vector<string> fileRawData = getFileData(fileName);
        for (string row : fileRawData) {
            vector<string> listOfData = utilities.parseByDelimiter(row, ',');
            fileData.push_back(listOfData);
        }

        return fileData;
    }
};
