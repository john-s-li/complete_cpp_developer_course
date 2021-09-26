#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

using namespace std;

class bankAccount
{
    public:
        bankAccount(string owner);
        bankAccount(string owner, int balance);
        void deposit(int amount);
        void withdraw(int amount);
        string getOwner() const;
        int getBalance() const;
    private:
        string owner;
        int balance;
}; // end of class

#endif