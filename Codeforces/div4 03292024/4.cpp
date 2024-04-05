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

        if(n==0)
            cout << "yes" << endl;

        int copy =n,temp=0;
        while(copy>0)
        {
            if(copy%10 >1 )
            {
                temp=1;
                // cout<<"here"<<copy%10<<endl;
                break;
            }
            copy = copy/10;
        }
        if(temp==0) cout<<"yes"<<endl;

        
    }
}