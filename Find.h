#pragma once
#include <string>
#include <iostream>
#include <map>
#include "Struct.h"
using namespace std;


void FindBook(map<string, Book> library, string key) {

    auto iterator = library.find(key);
    if (iterator != library.end()) {
        cout <<"ID-"  << iterator->second.id << " ";
        cout <<"BOOK NAME-" << iterator->second.bookName << " ";
        cout <<"AUTHOR-"    << iterator->second.author << " ";
        cout <<"READER-"    << iterator->second.reader << endl;
    }
    else {
        cout << "No one found (" << endl;
    }
}



void FindReaders(map<string, Reader> readers, string key) {

    auto iterator = readers.find(key);
    if (iterator != readers.end()) {
        cout << iterator->second.lastName << " "
             << iterator->second.bookName << endl;
    }
    else {
        cout << "No one found (" << endl;
    }
}