#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl '\n'
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second
int modval = 1e9 + 7;

bool isPalindrome(const string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int maxConcatenatedPalindrome(vector<string> &words)
{
    unordered_map<string, int> wordMap;
    int maxLength = 0;
    int centerLength = 0;

    // Process each word
    for (const string &word : words)
    {
        string reversedWord = word;
        reverse(reversedWord.begin(), reversedWord.end());

        // Case 1: The word itself is a palindrome
        if (isPalindrome(word, 0, word.length() - 1))
        {
            if (word.length() > centerLength)
            {
                centerLength = word.length();
            }
        }

        // Case 2: The word can be paired with its reverse
        if (wordMap.find(reversedWord) != wordMap.end())
        {
            maxLength += 2 * word.length();
            wordMap[reversedWord]--;
            if (wordMap[reversedWord] == 0)
            {
                wordMap.erase(reversedWord);
            }
        }
        else
        {
            wordMap[word]++;
        }

        // Case 3: The word can be part of a palindrome
        for (int i = 1; i < word.length(); i++)
        {
            // Check if the prefix can be paired
            string prefix = word.substr(0, i);
            reverse(prefix.begin(), prefix.end());
            if (wordMap.find(prefix) != wordMap.end() && isPalindrome(word, i, word.length() - 1))
            {
                maxLength += 2 * i;
                wordMap[prefix]--;
                if (wordMap[prefix] == 0)
                {
                    wordMap.erase(prefix);
                }
            }

            // Check if the suffix can be paired
            string suffix = word.substr(word.length() - i);
            reverse(suffix.begin(), suffix.end());
            if (wordMap.find(suffix) != wordMap.end() && isPalindrome(word, 0, word.length() - i - 1))
            {
                maxLength += 2 * i;
                wordMap[suffix]--;
                if (wordMap[suffix] == 0)
                {
                    wordMap.erase(suffix);
                }
            }
        }
    }

    // Add the length of the center palindrome
    maxLength += centerLength;

    return maxLength;
}

void solve()
{
    vector<string> words = {"aba"};

    int ans = maxConcatenatedPalindrome(words);

    cout<<ans<<endl;
}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // int t;cin>>t;while(t--)
       solve();
}