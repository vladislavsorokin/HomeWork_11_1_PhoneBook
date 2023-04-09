#pragma once

#include <fstream>
#include <string>
#include <map>

using namespace std;

// <phone>|<name>

bool ImportFromFile(map<string, string>& result, string path) {
    ifstream file;
    file.open(path);
    if(file.is_open())
    {
        string line;
        while (getline(file, line)) {
            int position = line.find('|');
            string phone = line.substr(0, position);
            string name = line.substr(position + 1);

            result.insert(pair<string, string>(phone, name));
        }
        file.close();

        return true;
    } else
    {
        file.close();
        return false;
    }
}

bool ExportToFile(string path, map<string, string>& phoneBook) {
    ofstream file;
    file.open(path, ios::trunc);
    if (!file.is_open())
    {
        file.close();
        return false;
    }
    else
    {
        for (auto item : phoneBook)
        {
            file << item.first << "|" << item.second << endl;
        }
        file.close();
        return true;
    }

}
