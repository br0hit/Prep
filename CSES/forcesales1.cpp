
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void solve(string arr[], int n);

int main()
{

    string a1[] = {"aba", "aba"};

    int n1 = sizeof(a1) / sizeof(a1[0]);

    solve(a1, n1);

    string a2[] = {"abc", "dba", "kop", "abd", "cba"};

    int n2 = sizeof(a2) / sizeof(a2[0]);

    solve(a2, n2);

    //        abaaba

    //        abdcbaabcdba

    return 0;
}

void solve(string arr[], int n)
{

    //   array ans[] will store the final palindromic

    //   strings

    vector<string> ans(n);

    //        pointer i at starting and j at ending index of

    // ans

    int i = 0, j = n - 1;

    //        pallMap wil store the  palindromic strings

    unordered_map<string, int> pallMap;

    //        notPallMap will store the not palindromic

    // strings

    unordered_map<string, int> notPallMap;

    for (int k = 0; k < n; k++)
    {

        //            String str1 will store the

        // string of arr

        string str1 = arr[k];

        //            freq is the frequency of

        // pall_String

        string str2 = string(str1.rbegin(), str1.rend());

        if (str1 == str2)
        {

            //                if the str1 is a palindromic

            // string                 than increase its frequency in pallMap

            pallMap[str1]++;
        }

        else
        {

            //                check if reverse string str2 exist in

            // notPallMap or not

            int freq = notPallMap[str2];

            //                if str2 not exist than increase it's

            // frequency in notPallMap

            if (freq == 0)
            {

                notPallMap[str1]++;
            }

            else
            {

                //                    if str2

                // exist in the notPallMap than                     add str1 at

                // index i and str2 at index j

                ans[i] = str1;

                ans[j] = str2;

                //                    increase i

                // and decrease j after adding in ans

                i++;

                j--;

                //                    decrease the

                // frequency of str2 in notPallMap

                notPallMap[str2]--;
            }
        }
    }

    //        Stirng odd will store the palindromic string with

    // odd frequency

    string odd;

    //        travel the hashMap, pallMap

    for (auto &kk : pallMap)
    {

        //            pall_String is the palindromic

        // string

        string pall_string = kk.first;

        //            freq is the frequency of

        // pall_String

        int freq = kk.second;

        if (freq % 2 == 1)
        {

            while (freq > 1)
            {

                ans[i++] = pall_string;

                ans[j--] = pall_string;

                freq -= 2;
            }

            //                if the freq is odd, than store it in

            // String odd

            if (odd.empty())
            {

                odd = pall_string;
            }
        }

        else
        {

            while (freq > 0)
            {

                ans[i++] = pall_string;

                ans[j--] = pall_string;

                freq -= 2;
            }
        }
    }

    //        Store the String odd in ans if it is not

    // null

    if (!odd.empty())
    {

        ans[i++] = odd;
    }

    //        String res will hold the final palindromic

    // string

    string res;

    for (auto &temp : ans)
    {

        //            if String is not null than add

        // it in ans

        if (!temp.empty())
        {

            res += temp;
        }
    }

    cout << res << endl;
}

string reverse(string input)
{

    int l, r = input.size() - 1;

    for (l = 0; l < r; l++, r--)
    {

        char temp = input[l];

        input[l] = input[r];

        input[r] = temp;
    }

    return input;
}
