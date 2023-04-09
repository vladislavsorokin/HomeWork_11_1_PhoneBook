#pragma once

#include <string>
#include <map>

using namespace std;

void Insert(map<string, string>& phoneBook, string phone, string name) {
    phoneBook.insert(pair<string, string>(phone, name));
}

void UpdateName(map<string, string>& phoneBook, string phone, string name) {
    //TODO Добавить проверку на существование телефона (phone), перед обновлением имени
    // Если не существует - то просто игнорируем.
    for (pair <string, string> item : phoneBook)
    {
        if(item.first.size() != 0)
        {
            if(item.first == phone)
            {
                phoneBook[phone] = name;
            }
        }
    }
}

void UpdatePhone(map<string, string>& phoneBook, string phone, string name) {
    //TODO реализовать функцию
    map<string, string> newPhoneBook;
    for (pair <string, string> item : phoneBook)
    {
        if(item.first != phone)
        {
            newPhoneBook.insert(item);
        }
    }
    Insert(newPhoneBook, phone, name);
    phoneBook = newPhoneBook;
}

void Delete(map<string, string>& phoneBook, string phone) {
    phoneBook.erase(phone);
}

string FindByPhone(map<string, string>& phoneBook, string phone) {
    //TODO Продумать что возвращать в случае отсутствия номера в массиве
    map<string, string> newPhoneBook = phoneBook;
    if(newPhoneBook[phone] == "")
    {
        return phone + (newPhoneBook[phone] = " отсутствует");
    }
    else
    {
        return phone + " : " + phoneBook[phone];
    }
}

map<string, string> FindByName(map<string, string>& phoneBook, string name) {
    map<string, string> result;

    for (auto item : phoneBook) {
        if (item.second == name) {
            result.insert(item);
        }
    }
    return result;
}