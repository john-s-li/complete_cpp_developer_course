#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List.h"
#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayList : public List
{
    public:
        ArrayList(int size = 16);
        void add(int newEntry);
        void add(int newEntry, int position);
        void set(int newEntry, int position);
        bool contains(int entry);
        int find(int entry);
        void remove(int position);
        void makeEmpty();
        int size() const;
        bool isEmpty() const;
        void printList() const;

    private:
        int* _Array;
        const int _MAX_SIZE;
        int _numElements;

}; // end class

ArrayList::ArrayList(int size) : _MAX_SIZE(size)
{
    this->_Array = new int[this->_MAX_SIZE];
    this->_numElements = 0;
}

void ArrayList::add(int newEntry)
{
    if(this->_numElements >= this->_MAX_SIZE)
    {
        throw out_of_range("Array already full");
    }

    this->_Array[this->_numElements] = newEntry;
    this->_numElements++;
} 

void ArrayList::add(int newEntry, int position)
{
    if(this->_numElements == this->_MAX_SIZE)
    {
        throw out_of_range("Array already full");
    }
    else if ( position > this->_numElements || position < 0 )
    {
        throw out_of_range("Array index position out of range.");
    }

    // Work backwards so all the elements after position
    // shift their position by 1 to accomodate this
    // new entry
    for(int i = this->_numElements; i > position; i--)
    {
        this->_Array[i] =  this->_Array[i-1];
    } 
    this->_Array[position] = newEntry;   
    this->_numElements++;
}

void ArrayList::set(int newEntry, int position)
{
    if(this->_numElements == this->_MAX_SIZE)
    {
        throw out_of_range("Array already full");
    }
    else if ( position > this->_numElements || position < 0 )
    {
        throw out_of_range("Array index position out of range.");
    }

    this->_Array[position] = newEntry;
}

bool ArrayList::contains(int entry)
{
    for(int i = 0; i < this->_numElements; i++)
    {
        if (this->_Array[i] == entry)
        {
            return true;
        }
    }
    return false;
}

int ArrayList::find(int entry)
{
    for(int i = 0; i < this->_numElements; i++)
        {
            if (this->_Array[i] == entry)
            {
                return i;
            }
        }

    return -1;
}

void ArrayList::remove(int position)
{
    if ( position > this->_numElements || position < 0 )
    {
        throw out_of_range("Array index position out of range.");
    }

    for(int i = position; i < this->_numElements; i++)
    {
        this->_Array[i] = this->_Array[i+1];
    }
    this->_numElements--; // fake remove the last element...
}

void ArrayList::makeEmpty()
{
    delete[] this->_Array;
    this->_Array = new int[this->_MAX_SIZE];
    this->_numElements = 0;
}

int ArrayList::size() const
{
    return this->_numElements;
}

bool ArrayList::isEmpty() const
{
    return this->_numElements == 0;
}

void ArrayList::printList() const
{
    for(int i = 0; i < this->_numElements; i++)
    {
        cout << this->_Array[i] << endl;
    }
}

#endif