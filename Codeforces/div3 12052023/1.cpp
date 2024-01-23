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

       char pos;
       int val;

       pos = s[0];
       val = s[1]-'0';

    //    cout<<val<<" "<<pos<<"\n";

        int i;

        for(i=1;i<9;i++)
        {   if(i!=val)
        {
            cout<<pos<<i<<"\n";
        }  
        }

        int char_val = 'a';
        char x;

        for(i=char_val;i<char_val+8 ;i++)
        {   if(i!=pos)
        {
            x=i;
            cout<<x<<val<<"\n";
        }  
        }
    }

    return 0;
}