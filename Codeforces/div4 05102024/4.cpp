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

        int size = s.size();
        int first=0;
        int count=0;

        for(int i=0; i<size-1; i++)
        {
            if(s[i]=='0' && s[i+1]=='0') continue;
            if(s[i]=='1' && s[i+1]=='1') continue;
            if(s[i]=='0' && s[i+1]=='1')
            {
                if(first==1) count++;
                else first=1;
            }
            if(s[i]=='1' && s[i+1]=='0') count++;
        }

        cout<<count+1<<endl;
    }

    return 0;
}