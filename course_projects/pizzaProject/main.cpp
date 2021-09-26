#include "Pizza.h"
#include <iostream>
#include <string>

int main()
{
    Pizza Pizza1("Hawaiian", 25, 8);
    Pizza1.addTopping("Pineapple");
    Pizza1.addTopping("Ham");
    Pizza1.printToppings();
    cout << "Cost = $" << Pizza1.getCost() << endl;


    Pizza Pizza2("Supreme", 12, 10);
    Pizza2.addTopping("Green Peppers");
    Pizza2.addTopping("Sausage");
    Pizza2.addTopping("Mushrooms");
    Pizza2.printToppings();
    cout << "Cost = $" << Pizza2.getCost() << endl;

    return 0;
}