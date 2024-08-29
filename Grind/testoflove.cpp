#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl '\n'
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second
int modval = 1e9 + 7;



void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    string a;
    cin>>a;

    int totalwater = 0;

    int currpos=-1;
    char currcase='L';

    while(1)
    {
        //cout<<currcase<<" "<<currpos<<" "<<totalwater<<endl;
        if(currcase=='L')
        {
            if (currpos + m >= n)
            {
                cout << "YEs" << endl;
                return;
            }
            int maxwater = -1;
            int caseval=0;

            for (int i = m; i >= 1; i--)
            {
                int temppos = currpos + i;
                if (a[temppos] == 'L')
                {
                    caseval=1;
                    currpos = temppos;
                    //cout<<"here"<<endl;
                    // return;
                    break;
                }
                if (a[temppos] == 'W')
                {
                    maxwater = max(maxwater, temppos);
                }
            }

            if(caseval==1)
            {
                currcase = 'L';
                continue;
            }
            else
            {
                if(maxwater==-1)
                {
                    cout<<"NO"<<endl;
                    return;
                }
                else
                {
                    currcase = 'W';
                    currpos = maxwater;
                }
            }
        }
        else
        {
           while(1)
           {
               totalwater++;

               if (totalwater > k)
               {
                   cout << "NO" << endl;
                   return;
               }

               currpos++;

               if(currpos>=n)
               {
                   cout << "YEs" << endl;
                   return;
               }

               if(a[currpos]=='C')
               {
                    cout<<"NO"<<endl;
                    return;
               }
               else if(a[currpos]=='L')
               {
                    currcase = 'L';
                    break;
               }

           }
        }

    }

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}