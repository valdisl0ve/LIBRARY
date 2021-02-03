#include <iostream>
#include <map>
#include <fstream>
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


// BOOKS
void ShowAllBooks(map<string , Book> library) {
    cout << "+++BOOKS+++";
    for (auto item : library) {
        cout << endl;
        cout << item.first << " "
             << item.second.id << " "
             << item.second.bookName << " "
             << item.second.author << " "
             << item.second.reader << endl;
    }
}

/*void AddBook(map<string, Book>& library) {

    Book book;
    string bookName;
    cout << "1. Enter the ID - "; cin >> book.id;
    cout << "2. Enter the book name - "; cin >> book.bookName;
    bookName = book.bookName;
    cout << "3. Enter the Author - "; cin >> book.author;
    cout << "4. Enter the Reader - "; cin >> book.reader;
    library.insert(make_pair(bookName, book));

}*/

void ReadFromFile(map<string, Book>& library, ifstream& file) {
    Book book;
    string key;


    while (!file.eof()) {
        getline(file, book.id, ';');
        getline(file, book.bookName, ';');
        getline(file, book.author, ';');
        getline(file, book.reader);
        key = book.bookName;
        library.insert(make_pair(key, book));
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

    file.open("export.csv", ios_base::app);
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



// READERS
void ShowAllReaders(map<string , Reader> readers) {
    cout << "+++BOOKS+++";
    for (auto item : readers) {
        cout << endl;
        cout << item.first << " "
             << item.second.lastName << " "
             << item.second.bookName << endl;
    }
}

void ReadFromFile_readers(map<string, Reader>& readers, ifstream& file) {
    Reader reader;
    string key;
    while (!file.eof()) {
        getline(file, reader.lastName, ';');
        getline(file, reader.bookName);
        key = reader.lastName;
        readers.insert(make_pair(key, reader));
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

void WriteToFile_readers(map<string, Reader> readers, ofstream& file) {

    for (auto iter : readers)
    {
        file << iter.second.lastName << ";";
        file << iter.second.bookName << endl;
    }
}

void ExportToFile_readers(map<string, Reader> readers) {
    ofstream file;

    file.open("export_readers.csv", ios_base::app);
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




int main() {
    int menu;
    map<string, Book> library;
    map<string, Reader> readers;
    ImportFromFile(library);
    ImportFromFile_readers(readers);

    do{

    cout << "LIBRARY" << endl;
    cout << "To show all books press [1]" << endl;
    cout << "To show all readers press [2]" << endl;
    cout << "To find book press [3]" << endl;
    cout << "To find reader press [4]" << endl;
    cout << "To show all issued books [5]" << endl;
    cout << "To exit [0]" << endl;
     cin >> menu;

    switch(menu) {

        case 1:
            ShowAllBooks(library);
            break;


        case 2:
            ShowAllReaders(readers);
            break;

        case 3:
            //FindBook(library);
            break;

        case 4:
            //FindReaders(readers);
            break;

        case 5:
            //ShowAllIssuedBooks(library);
            break;
    }
    } while (menu != 0);

        //ExportToFile(library);

        return 0;

}