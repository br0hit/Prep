#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin>>s;

        if(s[0]=='0' && s[1] == '0')
        {
            cout<<"12:"<<s[3]<<s[4]<<" AM"<<endl;
            continue;
        }

        if(s[0]=='0' || s[0]=='1' && (s[1]>='0' && s[1]<='1'))
        {
            cout <<s<< " AM"<<endl;
            continue;
        }

        if(s[0]=='1' && s[1]=='2')
        {
            cout<<s<<" PM"<<endl;
            continue;
        }

        if(s[0]=='1')
        {
            cout<<"0"<<s[1]-'1'-1<<":"<<s[3]<<s[4]<<" PM"<<endl;
            continue;
        }

        if(s[0]=='2' && (s[1]=='0' || s[1]=='1'))
        {
            cout << "0" << s[1] - '0' + 8 << ":" << s[3] << s[4] << " PM"<<endl;
            continue;
        }

        cout << "1" << s[1] - '2'<< ":" << s[3] << s[4] << " PM"<<endl;
    }
}