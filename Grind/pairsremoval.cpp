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
        cin>>n;
        string s;
        cin>>s;

        vector<int> freq(26,0);

        for(int i=0; i<s.size(); i++)
        {
            freq[s[i]-'a']++;
        }

        int max=-1e9;
        for(int i=0; i<freq.size(); i++)
        {
            if(freq[i]>max) max = freq[i];
        }

        if(max>=n-max)
        {
            cout<<2*max-n<<endl;
        }
        else if(n%2==0)
        {
            cout<<0<<endl;  
        }
        else cout<<1<<endl;


    }

}