#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    vector<int> arr1;
    vector<char> arr2;

    int case1=0,ans=0;
    int mindigit= -1;
    int minchar = -1;

    for(int i=0; i<n; i++)
    {
        if(case1==0)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                case1 = 1;
                if(s[i]>=minchar)
                {
                    minchar = s[i];
                }
                else
                {
                    ans=1;
                    break;
                }

            }
            else if(s[i]>='0' && s[i]<='9')
            {
                if(s[i]>=mindigit)
                {
                    mindigit = s[i];
                }
                else 
                {
                    ans=1;
                    break;
                }
            }
            else
            {
                ans=1;
                break;
            }

        }
        
        else
        {
            if(s[i]<'a' || s[i]>'z')
            {
                ans=1;
                break;
            }
            else
            {
                if (s[i] >= minchar)
                {
                    minchar = s[i];
                }
                else
                {
                    ans = 1;
                    break;
                }
            }
        }
    }

    if(ans==0)
    {
        cout<<"yes"<<endl;
    }
    else cout<<"no"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}