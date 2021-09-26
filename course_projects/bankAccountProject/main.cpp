#include <iostream>
#include "bankAccount.h"

using namespace std;

int main()
{
    bankAccount bankOne("Jeff");
    bankAccount bankTwo("Jane", 100);
   
    cout << bankOne.getOwner() << " has " << bankOne.getBalance() << " dollars." << endl;
    cout << bankTwo.getOwner() << " has " << bankTwo.getBalance() << " dollars." << endl;

    cout << "Depositing some money for " << bankOne.getOwner() << "." << endl;
    bankOne.deposit(100);
    cout << "Now " << bankOne.getOwner() << " has " << bankOne.getBalance() << " dollars." << endl;

    cout << "Withdrawing some money for " << bankTwo.getOwner() << "." << endl;
    bankTwo.withdraw(50);
    cout << "Now " << bankTwo.getOwner() << " has " << bankTwo.getBalance() << " dollars." << endl;

    return 0;
}