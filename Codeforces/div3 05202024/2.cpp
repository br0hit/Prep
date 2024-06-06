#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    int t; 
    cin>>t; 

    while(t--)
    {
        int n;
        cin >> n;
        string b;
        cin >> b;

        if (n == 1)
        {
            cout << b << endl;
            continue;
        }
  
        // cout << "here" << endl;

        int vals[300];
        for (int i = 0; i < 300; i++)
            vals[i] = 0;

        for (int i = 0; i < n; i++)
        {
            // cout<<b[i]<<endl;
            vals[b[i]] = 1;
        }

        int l = 'a', r = 'z';

        while (r >= l)
        {
            if (r == l)
            {
                vals[l] = l;
                break;
            }
            if (vals[l] == 1 && vals[r] == 1)
            {
                char temp1 = l, temp2 = r;
                // cout << temp1 << temp2 << endl;
                vals[l] = r;
                vals[r] = l;
                l++;
                r--;
            }
            else if (vals[r] == 0 && vals[l == 0])
            {
                l++;
                r--;
            }
            else if (vals[l] == 0)
                l++;
            else
                r--;
        }

        for (int i = 0; i < n; i++)
        {
            b[i] = vals[b[i]];
        }

        cout << b << endl;
    }
    return 0;
}