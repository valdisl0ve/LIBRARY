#pragma once
#include <string>
using namespace std;

struct Book {
    string id;
    string bookName;
    string author;
    string reader;
};

struct Reader {
    string lastName;
    string bookName;
};