#ifndef SWAPPER_H
#define SWAPPER_H

template<class T>
class Swapper
{
    public:
        Swapper(T first, T second);
        void swap();
        T getFirst() const;
        T getSecond() const;
    private:
        T first;
        T second;
};

template<class T>
Swapper<T>::Swapper(T first, T second)
{
    this->first = first;
    this->second = second;
}

template<class T>
void Swapper<T>::swap()
{
    T temp = this->first;
    this->first = this->second;
    this->second = temp;
}
template<class T>
T Swapper<T>::getFirst() const
{
    return this->first;
}

template<class T>
T Swapper<T>::getSecond() const
{
    return this->second;
}

#endif