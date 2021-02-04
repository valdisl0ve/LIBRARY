#pragma once
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include "Struct.h"
using namespace std;


void WriteToFile_readers(map<string, Reader> readers, ofstream& file) {

    for (auto iter : readers)
    {
        file << iter.second.lastName << ";";
        file << iter.second.bookName << endl;
    }
}

void ExportToFile_readers(map<string, Reader> readers) {
    ofstream file;

    file.open("export_readers.csv", ios_base::trunc);
    if (readers.empty()) {
        cout << "empty" << endl;
    }
    else if (file.is_open()) {
        WriteToFile_readers(readers, file);
        cout << "successful" << endl;
    }
    else {
        cout << "No  file" << endl;
    }
    file.close();
}
