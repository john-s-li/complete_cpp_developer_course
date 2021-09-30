#ifndef STACK_H
#define STACK_H

class Stack
{
    public:
        virtual void push(int newEntry) = 0;
        virtual int pop() = 0; // remove top
        virtual int peek() = 0; // remove top BUT also display value
        virtual bool isEmpty() const = 0;
        virtual void makeEmpty() = 0;

}; // end class

#endif