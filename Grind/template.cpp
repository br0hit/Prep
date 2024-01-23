#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        string s;
        cin>>n;
        cin>>s;

        int count=1;
        int distinct=1;

        // cout<<s<<s.size();

        std::map<char,int> temp;
        temp[s[0]]++;

        for(int i=1; i<s.length(); i++)
        {
            if(temp[s[i]]==0)
            {
                distinct++;
                temp[s[i]]++;
            } 
            count+=distinct;
            // cout<<count<<distinct<<endl;
        }

        cout<<count<<endl;
    }
}
