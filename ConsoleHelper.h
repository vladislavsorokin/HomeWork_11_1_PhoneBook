#include <iostream>
#include <string>
#include <map>

using namespace std;

void ShowAll(map<string, string>& phoneBook) {
    for (auto item : phoneBook) {
        cout << item.first << " : " << item.second << endl;
    }
}