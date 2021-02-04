#pragma once
#include <string>
#include <iostream>
#include <map>
#include "Struct.h"
using namespace std;



void ShowAllBooks(map<string , Book> library) {
    cout << "+++BOOKS+++" << endl;
    for (auto item : library) {
        cout <<"ID-" << item.second.id << " ";
        cout <<"BOOK NAME-" << item.second.bookName << " ";
        cout <<"AUTHOR-" << item.second.author << " ";
        cout <<"READER-" << item.second.reader << endl;
    }
}


void ShowAllIssuedBooks(map<string , Book> library) {
    cout << "+++IssuedBooks+++"<< endl;
    for (auto item : library) {

        if (item.second.reader == "none"){
            cout <<"ID-" << item.second.id << " ";
            cout <<"BOOK NAME-" << item.second.bookName << " ";
            cout <<"AUTHOR-" << item.second.author << " ";
            cout <<"READER-" << item.second.reader << endl;
        }
    }
}


void ShowAllReaders(map<string , Reader> readers) {
    cout << "+++READERS+++";

    for (auto item : readers) {
        cout <<"NAME-" << item.second.lastName << " ";
        cout <<"READING-" << item.second.bookName << endl;
    }
}

