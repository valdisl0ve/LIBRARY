#pragma once
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include "Struct.h"
using namespace std;

void ReadFromFile(map<string, Book>& library, ifstream& file) {
    Book book;

    while (!file.eof()) {
        getline(file, book.id, ';');
        getline(file, book.bookName, ';');
        getline(file, book.author, ';');
        getline(file, book.reader);

        library.insert(make_pair(book.bookName, book));

    }
}

void ImportFromFile(map<string, Book>& library) {
    ifstream file;

    file.open("export.csv");

    if (file.is_open() && file.peek() == -1) {
        cout << "Error" << endl;
    }
    else if (file.is_open() && file.peek() != -1) {
        ReadFromFile(library, file);
        cout << "All right" << endl;
    }
    else {
        cout << "Please try again!" << endl;
    }
    file.close();
}