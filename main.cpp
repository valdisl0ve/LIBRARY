#include <iostream>
#include <map>
#include <string>
#include "Struct.h"
#include "Find.h"
#include "Show.h"
#include "ImportBooks.h"
#include "ExportBooks.h"
#include "ImportReaders.h"
#include "ExportReaders.h"

using namespace std;



int main() {
    int menu;
    string key;

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
            cout << "Enter the book name - "; cin >> key;
            FindBook(library, key);
            break;

        case 4:
            cout << "Enter the lastname of reader - "; cin >> key;
            FindReaders(readers, key);
            break;

        case 5:
            ShowAllIssuedBooks(library);
            break;
    }
    } while (menu != 0);

       ExportToFile(library);
       ExportToFile_readers(readers);

        return 0;

}