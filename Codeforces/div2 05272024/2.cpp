#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll x;
    ll xcopy;

    cin>>x;
    xcopy = x;

    vector<int> binary;
    ll pushbin=2;

    while(1)
    {
        if(xcopy==0) break;
        int tempval = xcopy%pushbin;
        binary.push_back(tempval);

        // cout<<tempval<<" "<<pushbin<<endl;
        xcopy/=2;
    }
    int size = binary.size();
    if(size==1)
    {
        cout<<1<<endl;
        cout<<binary[0]<<endl;
        return;
    }

    binary.push_back(0);

   //  cout<<size<<binary.size()<<endl;

    for(int i=0; i<size; i++)
    {
        // cout<<i<<" "<<binary[i]<<" "<<binary[i+1];
        if(i<size-1)
        {
            if (binary[i] == 1 && binary[i + 1] == 1)
            {
                binary[i] = -1;
                binary[i + 1] = 0;
                if (binary[i + 2] == 1)
                    binary[i + 2] = 2;
                else
                    binary[i + 2] = 1;
            }
            // cout<<"Here"<<" "<<binary[i]<<" "<<binary[i+1]<<" "<<binary[i+2];
        }

        if(binary[i]==2)
        {
            if(binary[i+1]==0)
            {
                binary[i+1]=1;
                binary[i]=0;
            }
            else 
            { binary[i]=0; binary[i+1]=2; }

            // cout<<"second case"<<i<<" ";
        }

       //  cout<<endl;

    }

    // cout<<"why not reaching here"<<endl;
    int range ;

    if(binary[binary.size()-1]==0)
    {
        range = binary.size()-1;
    }
    else range = binary.size();

    cout<<range<<endl;

    for(int i=0; i<range; i++)
    {
        cout<<binary[i]<<" ";
    }
    cout<<endl;

    return;
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