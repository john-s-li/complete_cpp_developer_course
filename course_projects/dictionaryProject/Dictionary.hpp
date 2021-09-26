#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Dictionary
{
    public:
        void addDefinition(string word, string definition);
        string getDefinition(string word) const;
        void printAll() const;
    private:
        unordered_map<string,string> dictionary;
}; // end class

void Dictionary::addDefinition(string word, string definition)
{
   this->dictionary[word] = definition;
}

string Dictionary::getDefinition(string word) const
{
    if (this->dictionary.find(word) == this->dictionary.end())
    {
        return "NOT FOUND";
    }
    return this->dictionary.at(word);
}

void Dictionary::printAll() const
{
    for(pair<string, string> entry : this->dictionary)
    {
        cout << entry.first << " : " << entry.second << endl;
    }
}

#endif