#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        for(int i = s.size()-1; i>=0; i--)
        {
            if(s[i]=='0' && s[i-1]=='0') s[i] = '\0';
            else
            {
                s[i]='\0';
                break;
            }
        }

        cout<<s<<endl;

    }

    return 0;
}
