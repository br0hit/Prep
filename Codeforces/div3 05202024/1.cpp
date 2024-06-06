#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x,y;
        cin>>x>>y;

        int count=0;
        int remaning;
        if(y%2==0) 
        { 
            count+=y/2;
            remaning = count*7;
        }
        else 
        {
            count+=(y/2)+1;
            remaning = (count-1)*7+11;
        }

        int newval = x-remaning;

        if(newval<0) 
        { cout<<count<<endl; continue; }
        
        if(newval%15==0) count+=newval/15;
        else count += (newval/15 +1 );
        cout<<count<<endl;


    }

    return 0;
}