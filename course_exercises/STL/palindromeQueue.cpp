#include <iostream>
#include <string>
#include <queue>

// NOTE: queues are FIFO (first in, first out)

using namespace std;

void storeReverse(string originalString, queue<char>& reverseString);
bool isPalindrome(string originalString, queue<char>& reverseString);

int main()
{
    // Test case 1
    {
        string s = "racecar";
        queue<char> s_rev;
        storeReverse(s, s_rev);
        cout << boolalpha;
        cout << "Is " << s << " a palindrome? " << isPalindrome(s, s_rev) << endl;
    }

    // Test case 2
    {
        string s = "madam";
        queue<char> s_rev;
        storeReverse(s, s_rev);
        cout << boolalpha;
        cout << "Is " << s << " a palindrome? " << isPalindrome(s, s_rev) << endl;
    }

    // Test case 3
    {
        string s = "toys";
        queue<char> s_rev;
        storeReverse(s, s_rev);
        cout << boolalpha;
        cout << "Is " << s << " a palindrome? " << isPalindrome(s, s_rev) << endl;
    }

    return 0;
}

void storeReverse(string originalString, queue<char>& reverseString)
{
    for(int i = originalString.length() - 1; i >= 0; i--)
    {
        reverseString.push(originalString[i]);
    }
}

bool isPalindrome(string originalString, queue<char>& reverseString)
{
    if ( originalString.length() != reverseString.size()) { return false; }

    for(char c: originalString)
    {
        // Get the last letter pushed onto the stack
        if (c != reverseString.front())
        { 
            return false;
        }
        reverseString.pop(); // remove the last element
    }

    return true;
}
