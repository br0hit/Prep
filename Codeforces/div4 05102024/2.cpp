#include <iostream>
using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        string s;
        cin>>s;

        int size = s.length();
        if(size==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        char first = s[0];
        int temp=0,pos;
        for(int i=1; i<size; i++)
        {
            if(s[i]!=first)
            {
                pos=i;
                temp=1;
                break;
            }
        }

        if(temp==0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            s[0] = s[pos];
            s[pos] = first;
            cout<<"yes"<<endl<<s<<endl;
        }
    }

    return 0;
}