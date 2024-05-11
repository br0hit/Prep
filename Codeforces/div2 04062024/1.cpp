#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        int total1s=0;
        int consec1=0;
        
        for(int i=0; i<n; i++)
        {
            if(s[i]=='1') total1s++;

            if(i!=n-1)
            {
                if (s[i] == '1' && s[i + 1] == '1')
                    consec1++;
            }

        }

        if(total1s%2!=0 || consec1==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            cout<<"YES"<<endl;
            continue;
        }

    }
}