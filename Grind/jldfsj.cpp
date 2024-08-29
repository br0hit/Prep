#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string decrypt(string e, string smap, int d, char c, int m, int n)
{
    // Level 5: Substring Shift
    e = e.substr(e.length() - n) + e.substr(0, e.length() - n);

    // Level 4: Remove inserted characters
    string level4 = "";
    for (int i = 0; i < e.length(); i++)
    {
        if (e[i] != c)
        {
            level4 += e[i];
        }
    }

    // Level 3: Remove character duplication
    string level3 = "";
    for (int i = 0; i < level4.length(); i += d)
    {
        level3 += level4[i];
    }

    // Level 2: Reverse custom mapping
    string level2 = "";
    for (char ch : level3)
    {
        level2 += (char)('A' + smap.find(ch));
    }

    // Level 1: Reverse prime number shift
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    string result = "";
    for (int i = 0; i < level2.length(); i++)
    {
        int shift = primes[i % primes.size()];
        char decrypted = ((level2[i] - 'A' - shift + 26) % 26) + 'A';
        result += decrypted;
    }

    return result;
}

int main()
{
    string e, smap;
    int d, m, n;
    char c;

    // Input
    getline(cin, e);
    getline(cin, smap);
    cin >> d >> c >> m >> n;

    // Decrypt
    string decrypted = decrypt(e, smap, d, c, m, n);

    // Output
    cout << decrypted << endl;

    return 0;
}