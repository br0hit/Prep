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
        string s;
        cin>>s;

        string ans = s;


        int countn=0,counts=0,counte=0,countw=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='N') countn++;
            if (s[i] == 'S')
                counts++;
            if (s[i] == 'E')
                counte++;
            if (s[i] == 'W')
                countw++;
        }

        int upcount;
        int sidecount;

        int leftoverupn,leftoverups,leftoverside;

        upcount = countn-counts;
        sidecount = counte-countw;



        int firstupn=0,firstups=0;
        int firstsidee=0,firstsidew=0;


        if(abs(upcount)%2==1 || abs(sidecount)%2==1)
        {
            cout<<"NO"<<endl;
            continue;
        }

        if (upcount == 0 && sidecount == 0)
        {
            if(countn==1 && counts==1 && counte==0 && countw==0)
            {
                cout<<"NO"<<endl;
                continue;
            }
            if (countn == 0 && counts == 0 && counte == 1 && countw == 1)
            {
                cout << "NO" << endl;
                continue;
            }

            for(int i=0; i<n; i++)
            {
                if(ans[i]=='N'||ans[i]=='S')
                {
                    if (ans[i] == 'N')
                    {
                        if (firstupn == 0)
                        {
                            ans[i] = 'R';
                            firstupn = 1;
                        }
                        else
                        {
                            ans[i] = 'H';
                            firstupn = 0;
                        }
                    }

                    if (ans[i] == 'S')
                    {
                        if (firstups == 0)
                        {
                            ans[i] = 'R';
                            firstups = 1;
                        }
                        else
                        {
                            ans[i] = 'H';
                            firstups = 0;
                        }
                    }
                }

                if(ans[i]=='E' || ans[i]=='W')
                {
                    if (ans[i] == 'E')
                    {
                        if (firstsidee == 0)
                        {
                            ans[i] = 'H';
                            firstsidee = 1;
                        }
                        else
                        {
                            ans[i] = 'R';
                            firstsidee = 0;
                        }
                    }

                    if (ans[i] == 'W')
                    {
                        if (firstsidew == 0)
                        {
                            ans[i] = 'H';
                            firstsidew = 1;
                        }
                        else
                        {
                            ans[i] = 'R';
                            firstsidew = 0;
                        }
                    }
                }


            }
        }

        int currup=0,currside=0;
        int makeup=0,makedown=0;

        for(int i=0; i<n; i++)
        {
            if(ans[i]=='N'||ans[i]=='S')
            {
                if(upcount>0)
                {
                    if(ans[i]=='S')
                    {
                        ans[i] = 'R';
                        continue;
                    } 

                    if(currup==0)
                    {
                        ans[i] = 'R';
                        currup=1;
                    }
                    else
                    {
                        ans[i] = 'H';
                        currup=0;
                    }
                    upcount--;
                }
                else if (upcount==0) 
                { 
                    ans[i] = 'R';
                }
                else
                {
                    if (ans[i] == 'N')
                    {
                        ans[i] = 'R';
                        continue;
                    }

                    if (currup == 0)
                    {
                        ans[i] = 'R';
                        currup = 1;
                    }
                    else
                    {
                        ans[i] = 'H';
                        currup = 0;
                    }
                    upcount++;
                }

            }

            if (ans[i] == 'E' || ans[i] == 'W')
            {
                if (sidecount > 0)
                {
                    if (ans[i] == 'W')
                    {
                        ans[i] = 'H';
                        continue;
                    }

                    if (currside == 0)
                    {
                        ans[i] = 'R';
                        currside = 1;
                    }
                    else
                    {
                        ans[i] = 'H';
                        currside = 0;
                    }
                    sidecount--;
                }
                else if (sidecount == 0)
                {
                    ans[i] = 'H';
                }
                   
                else
                {
                    if (ans[i] == 'E')
                    {
                        ans[i] = 'H';
                        continue;
                    }

                    if (currside == 0)
                    {
                        ans[i] = 'R';
                        currside = 1;
                    }
                    else
                    {
                        ans[i] = 'H';
                        currside = 0;
                    }
                    sidecount++;
                }
            }
        }

        cout << ans << endl;
    }


    return 0;   
}