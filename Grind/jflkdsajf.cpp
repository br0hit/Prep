#include <iostream>
#include <string>
#include <vector>

using namespace std;

string decryptString(const string &encrypted, const string &smap, int d, char c, int m, int n)
{
    // Step 1: Reverse Level 5
    string temp = encrypted.substr(n) + encrypted.substr(0, n);

    // Step 2: Reverse Level 4
    string withoutInserts;
    for (char ch : temp)
    {
        if (ch != c)
        {
            withoutInserts += ch;
        }
    }
    temp = withoutInserts;

    // Step 3: Reverse Level 3
    string withoutDuplicates;
    for (int i = 0; i < temp.size(); i += d)
    {
        withoutDuplicates += temp[i];
    }
    temp = withoutDuplicates;

    // Step 4: Reverse Level 2
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string customMappingReversed;
    for (char ch : temp)
    {
        int index = smap.find(ch);
        customMappingReversed += alphabet[index];
    }
    temp = customMappingReversed;

    // Step 5: Reverse Level 1
    vector<int> primes = {2, 3, 5, 7, 11}; // First 5 prime numbers
    string original;
    for (int i = 0; i < temp.size(); ++i)
    {
        char ch = temp[i];
        int shift = primes[i % primes.size()];
        ch = ((ch - 'A' - shift + 26) % 26) + 'A';
        original += ch;
    }

    return original;
}

int main()
{
    // Example input
    string encrypted = "@MM@MPP@PI@II@JJ@JL@LL";
    string smap = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int d = 3;
    char c = '@';
    int m = 2;
    int n = 5;

    // Decrypt the string
    string decrypted = decryptString(encrypted, smap, d, c, m, n);

    // Print the decrypted string
    cout << "Decrypted string: " << decrypted << endl;

    return 0;
}
