//Сорокин Владислав Дмитриевич
//ДЗ 1.
//Доработать программу (дописать функции, где останутся комментарии с TODO).

#include "FileHelper.h"
#include "ConsoleHelper.h"
#include "PhoneBook.h"

using namespace std;

int main() {

    system("chcp 65001");

    cout << "Import file" << endl;
    map<string, string> phoneBook;

    if (!ImportFromFile(phoneBook, "export.psv"))
    {
        return -1;
    }
    ShowAll(phoneBook);
    cout << " --- " << endl;

    cout << "Insert phone-name" << endl;
    Insert(phoneBook, "1", "A");
    ShowAll(phoneBook);
    cout << " --- " << endl;
    Insert(phoneBook, "2", "B");
    ShowAll(phoneBook);
    cout << " --- " << endl;

    cout << "Update phone" << endl;
    UpdatePhone(phoneBook, "+7-666-66-66", "Ася");
    ShowAll(phoneBook);
    cout << " --- " << endl;

    cout << "Update name" << endl;
    UpdateName(phoneBook, "2", "C");
    ShowAll(phoneBook);
    cout << " --- " << endl;

    cout << "Find Phone" << endl;
    cout << FindByPhone(phoneBook, "66") << endl;
    cout << " --- " << endl;

    cout << "Delete Phone" << endl;
    Delete(phoneBook, "1");
    ShowAll(phoneBook);
    cout << " --- " << endl;

    if(!ExportToFile("export.psv", phoneBook))
    {
        return -2;
    }

    return 0;
}
