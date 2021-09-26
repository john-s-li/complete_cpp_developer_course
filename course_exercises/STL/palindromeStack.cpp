#include <iostream>
#include <stack>
#include <string>

using namespace std;

// NOTE: stacks are FILO (first in, last out)

// Function prototypes
void storeReverse(string originalString, stack<char>& reverseString);
bool isPalindrome(string originalString, stack<char>& reverseString);

int main()
{
    // Test case 1
    {
        string s = "racecar";
        stack<char> s_rev;
        storeReverse(s, s_rev);
        cout << boolalpha;
        cout << "Is " << s << " a palindrome? " << isPalindrome(s, s_rev) << endl;
    }

    // Test case 2
    {
        string s = "madam";
        stack<char> s_rev;
        storeReverse(s, s_rev);
        cout << boolalpha;
        cout << "Is " << s << " a palindrome? " << isPalindrome(s, s_rev) << endl;
    }

    // Test case 3
    {
        string s = "toys";
        stack<char> s_rev;
        storeReverse(s, s_rev);
        cout << boolalpha;
        cout << "Is " << s << " a palindrome? " << isPalindrome(s, s_rev) << endl;
    }

    return 0;
}

// Function definitions
void storeReverse(string originalString, stack<char>& reverseString)
{
    for(char c : originalString)
    {
        reverseString.push(c);
    }
}

bool isPalindrome(string originalString, stack<char>& reverseString)
{
    if ( originalString.length() != reverseString.size()) { return false; }

    for(char c: originalString)
    {
        // Get the last letter pushed onto the stack
        if (c != reverseString.top())
        { 
            return false;
        }
        reverseString.pop(); // remove the last element
    }

    return true;
}