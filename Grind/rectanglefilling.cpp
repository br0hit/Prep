#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n,m;
        cin>>n>>m;

        bool ans;

        vector<vector<char>> matrix(n, vector<char>(m,'\0'));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        vector<vector<int>> map(n, vector<int>(2,0));

        int minval,maxval,globalminw=1000,globalmaxw=-1,globalminb=1000,globalmaxb=-1;

        for (int i = 0; i < n; i++)
        {
            minval = 1000; maxval = -1;
            for (int j = 0; j < m; j++)
            {
                if(matrix[i][j]=='W')
                {
                    globalminw = min(globalminw,j);
                    globalmaxw = max(globalmaxw,j);
                }
                if (matrix[i][j] == 'B')
                {
                    globalminb = min(globalminb, j);
                    globalmaxb = max(globalmaxb, j);
                }
            }
        }

        int firstrw=-1,firstrb=-1,lastrw=-1,lastrb=-1;

        for(int i=0; i<m; i++)
        {
            if(matrix[0][i]=='W')
            {
                firstrw=0;
            }
            if (matrix[0][i] == 'B')
            {
                firstrb = 0;
            }
            if (matrix[n-1][i] == 'W')
            {
                lastrw = 0;
            }
            if (matrix[n-1][i] == 'B')
            {
                lastrb = 0;
            }
        }

        ans=0;

        if(globalminb==1000 || globalminw==1000) ans=1;

        if(m-1>0)
        {
            if (globalminb == 0 && globalmaxb == m - 1 && firstrb==0 && lastrb==0)
            {
                ans = 1;
            }

            if (globalminw == 0 && globalmaxw == m - 1 && firstrw==0 && lastrw==0)
                ans = 1;
        }

        // cout<<globalmaxb<<globalminb<<globalmaxw<<globalminw<<endl;

        if(ans==1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;

    }

    return 0;
}