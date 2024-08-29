#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to reverse level 5 encryption
string reverseLevel5(const string &encrypted, int n)
{
    return encrypted.substr(n) + encrypted.substr(0, n);
}

// Function to reverse level 4 encryption
string reverseLevel4(const string &encrypted, char c, int m)
{
    string result;
    for (char ch : encrypted)
    {
        if (ch != c)
        {
            result += ch;
        }
    }
    return result;
}

// Function to reverse level 3 encryption
string reverseLevel3(const string &encrypted, int d)
{
    string result;
    for (int i = 0; i < encrypted.size(); i += d)
    {
        result += encrypted[i];
    }
    return result;
}

// Function to reverse level 2 encryption
string reverseLevel2(const string &encrypted, const string &smap)
{
    string result;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char ch : encrypted)
    {
        int index = smap.find(ch);
        result += alphabet[index];
    }
    return result;
}

// Function to reverse level 1 encryption
string reverseLevel1(const string &encrypted)
{
    vector<int> primes = {2, 3, 5, 7, 11}; // First 5 prime numbers
    string result;
    for (int i = 0; i < encrypted.size(); ++i)
    {
        char ch = encrypted[i];
        int shift = primes[i % primes.size()];
        ch = ((ch - 'A' - shift + 26) % 26) + 'A';
        result += ch;
    }
    return result;
}

int main()
{
    string encrypted = "@MM@MPP@PI@II@JJ@JL@LL";
    string smap = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int d = 3;
    char c = '@';
    int m = 2;
    int n = 5;

    // Reverse Level 5
    string afterLevel5 = reverseLevel5(encrypted, n);

    cout << afterLevel5 << endl;

    // Reverse Level 4
    string afterLevel4 = reverseLevel4(afterLevel5, c, m);
    cout << afterLevel4 << endl;

    // Reverse Level 3
    string afterLevel3 = reverseLevel3(afterLevel4, d);
    cout << afterLevel3 << endl;

    // Reverse Level 2
    string afterLevel2 = reverseLevel2(afterLevel3, smap);
    cout << afterLevel2 << endl;

    // Reverse Level 1
    string original = reverseLevel1(afterLevel2);
    cout << original << endl;
    cout << "Decrypted string: " << original << endl;

    return 0;
}
