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
        int n;
        cin>>n;

        string a;
        cin>>a;

        vector<vector<int>> oldvals(n+1,vector<int>(2,0));
        vector<vector<int>> newvals(n + 1, vector<int>(2, 0)); 

        int zerocount=0,onecount=0;

        for(int i=n; i>=0; i--)
        {
            oldvals[i][0] = zerocount;
            oldvals[i][1] = onecount;

            if(i>0)
            {
                if (a[i - 1] == '0')
                    zerocount++;
                else
                    onecount++;
            }
        }

        float middleofvillage = (n)/2.0;
        int leftvalid,rightvalid;

        int currval,index;
        float minval = 1e9;

        zerocount=0;
        onecount=0;

        for(int i=0; i<=n; i++)
        {
            // cout<<i<<" ";
            if(i==0) leftvalid=1;
            else
            {
                if(a[i-1]=='0') zerocount++;
                else onecount++;

                if(zerocount>=onecount) leftvalid=1;
                else leftvalid=0;
            }
            if(i==n) rightvalid=1;
            else
            {
                if (oldvals[i][1] >= oldvals[i][0]) rightvalid=1;
                else rightvalid=0;
            }
            // cout<<zerocount<<onecount<<" "<<oldvals[i][0]<<oldvals[i][1]<<" "<<leftvalid<<rightvalid<<endl;

            if(leftvalid==1 && rightvalid==1)
            {
                // cout<<i<<endl;
                float val = abs(middleofvillage - i);

                // cout << " " << middleofvillage - i<<val << minval << endl;
                if(val<minval)
                {
                    minval=val;
                    index=i;
                }
            }
        }

        cout<<index<<endl;
    }

    return 0;
}