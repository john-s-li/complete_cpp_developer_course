#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node
{
    public:
        Node(T data, Node* next);
        void setData(T data);
        void setNext(Node* next);
        T getData() const;
        Node* getNext() const;

    private:
        T data;
        Node* next;
}; // end class

template<class T>
Node<T>::Node(T data, Node* next)
{
    this->data = data;
    this->next = next;
}

template<class T>
void Node<T>::setData(T data)
{
    this->data = data;
}

template<class T>
void Node<T>::setNext(Node* next)
{
    this->next = next;
}

template<class T>
T Node<T>::getData() const
{
    return this->data;
}

template<class T>
Node<T>* Node<T>::getNext() const
{
    return this->next;
}

#endif