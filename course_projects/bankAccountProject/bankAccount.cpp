#include "bankAccount.h"
#include <iostream>

using namespace std;

bankAccount::bankAccount(string owner)
{
    this->owner = owner;
    this->balance = 0;
}

bankAccount::bankAccount(string owner, int balance)
{
    this->owner = owner;
    if (balance <= 0)
    {
        cout << "Balance cannot be zero or negative! Setting balance to 0. . ." << endl;
        this->balance = 0;
    }
    else
    {
        this->balance = balance;
    }
}

void bankAccount::deposit(int amount)
{
    if (amount <= 0)
    {
        cout << "Must deposit more than $0." << endl;
    }
    else
    {
        this->balance += amount;
    }
}

void bankAccount::withdraw(int amount)
{
    if (amount <= 0)
    {
        cout << "Must withdraw more than $0." << endl;
    }
    else if (amount > this->balance)
    {
        cout << "Cannot withdraw more than current balance." << endl;
    }
    else
    {
        this->balance -= amount;
    }
}

string bankAccount::getOwner() const
{
    return this->owner;
}

int bankAccount::getBalance() const
{
    return this->balance;
}