
#pragma once
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include "Struct.h"
using namespace std;


void WriteToFile(map<string, Book> library, ofstream& file) {

    for (auto iter : library)
    {
        file << iter.second.id << ";";
        file << iter.second.bookName << ";";
        file << iter.second.author << ";";
        file << iter.second.reader << endl;
    }
}

void ExportToFile(map<string, Book> library) {
    ofstream file;

    file.open("export.csv", ios_base::trunc);
    if (library.empty()) {
        cout << "empty" << endl;
    }
    else if (file.is_open()) {
        WriteToFile(library, file);
        cout << "successful" << endl;
    }
    else {
        cout << "No  file" << endl;
    }
    file.close();
}