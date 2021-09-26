#include <iostream>

using namespace std;

int calc_factorial(int n)
{
    int factorial;

    if (n==1)
    {
        return 1;
    }

    factorial = n * calc_factorial(n-1);

    return factorial;
}

int main()
{
    int userInput;
    int factorial;

    cout << "Please input a number to calulate the factorial of." << endl;
    cin >> userInput;

    factorial = calc_factorial(userInput);
    cout << "Factorial of " << userInput << " is " << factorial << "." << endl;
    
    return 0; 
}