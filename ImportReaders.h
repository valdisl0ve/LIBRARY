#pragma once
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include "Struct.h"
using namespace std;


void ReadFromFile_readers(map<string, Reader>& readers, ifstream& file) {
    Reader reader;

    while (!file.eof()) {
        getline(file, reader.lastName, ';');
        getline(file, reader.bookName);

        readers.insert(make_pair(reader.lastName, reader));
    }
}

void ImportFromFile_readers(map<string, Reader>& readers) {
    ifstream file;

    file.open("export_readers.csv");

    if (file.is_open() && file.peek() == -1) {
        cout << "Error" << endl;
    }
    else if (file.is_open() && file.peek() != -1) {
        ReadFromFile_readers(readers, file);
        cout << "All right" << endl;
    }
    else {
        cout << "Please try again!" << endl;
    }
    file.close();
}