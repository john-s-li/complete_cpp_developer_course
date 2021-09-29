#ifndef LIST_H
#define LIST_H

// This is an abstract data type (ADT)
// Explains functionality but has no implementation

class List
{
    public:
        virtual void add(int newEntry) = 0; // pure virtual function
        virtual void add(int newEntry, int position) = 0;
        virtual void set(int newEntry, int position) = 0;

        virtual bool contains(int entry) = 0;
        virtual int find(int entry) = 0;
        virtual void remove(int position) = 0;

        virtual void makeEmpty() = 0;
        virtual int size() const = 0;
        virtual bool isEmpty() const = 0;
        virtual void printList() const = 0;
}; // end class

#endif