#include <iostream>
#include <stdexcept>

using namespace std;

// Function prototype
void checkGrade(int grade);

int main()
{
    int grade;

    cout << "Please enter your grade.\n";
    cin >> grade;

    try 
    {
        checkGrade(grade);
    }
    catch(const out_of_range& err)
    {
        cerr << err.what() << endl;
    }

    return 0;
}

// Function definition
void checkGrade(int grade)
{
    if (grade >= 0 && grade <= 59)
    {
        cout << "You got an F.\n";
    }
    else if (grade >= 60 && grade <= 69)
    {
        cout << "You got a D.\n";
    }
    else if (grade >= 70 && grade <= 79)
    {
        cout << "You got a C.\n";
    }
    else if (grade >= 80 && grade <= 80)
    {
        cout << "You got a B.\n";
    }
    else if (grade >= 90 && grade <= 100)
    {
        cout << "You got an A!\n";
    }
    else
    {
        throw out_of_range("Not valid grade.");
    }
}