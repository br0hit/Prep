#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int check(vector<int> a, vector<int> b)
{
    if(a[0]==b[0] && a[1]==b[1] && a[2]==b[2]) return 0;
    if (a[1] == b[1] && a[2] == b[2])
        return 1;
    if (a[0] == b[0] && a[2] == b[2])
        return 1;
    if (a[0] == b[0] && a[1] == b[1] )
        return 1;

    return 0;
}

bool sort1(tuple<int,int,int> t1, tuple<int,int,int> t2)
{

    if (get<0>(t1) != get<0>(t2))
        return get<0>(t1) < get<0>(t2);

    if (get<1>(t1)!=get<1>(t2))
        return get<1>(t1) < get<1>(t2);

    return get<2>(t1) < get<2>(t2);
}
bool sort2(tuple<int, int, int> t1, tuple<int, int, int> t2)
{

    if (get<1>(t1) != get<1>(t2))
        return get<1>(t1) < get<1>(t2);

    if (get<2>(t1) != get<2>(t2))
        return get<2>(t1) < get<2>(t2);

    return get<0>(t1) < get<0>(t2);
}
bool sort3(tuple<int, int, int> t1, tuple<int, int, int> t2)
{

    if (get<2>(t1) != get<2>(t2))
        return get<2>(t1) < get<2>(t2);

    if (get<0>(t1) != get<0>(t2))
        return get<0>(t1) < get<0>(t2);

    return get<1>(t1) < get<1>(t2);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin>>n;

        vector<int> a(n,0);
        for(int i=0; i<n; i++) cin>>a[i];

        if(n==3)
        {
            cout<<0<<endl;
            continue;
        }

        vector<int> temp1(3,0),temp2(3,0);
        long long ans=0;

        vector<tuple<int,int,int>> trynew;
        vector<tuple<int, int, int>> trynew2;
        vector<tuple<int, int, int>> trynew3;

        for(int i=0; i<n-2; i++)
        {
            trynew.push_back({a[i],a[i+1],a[i+2]});
            trynew2.push_back({a[i], a[i + 1], a[i + 2]});
            trynew3.push_back({a[i], a[i + 1], a[i + 2]});
        }

        for(int i=0; i<n-2;i++)
        {
           // cout << (get<0>(trynew[i])) << (get<1>(trynew[i])) << (get<2>(trynew[i]))<<" ";
        }
        // cout<<endl;
        sort(trynew.begin(), trynew.end(),sort1);
        sort(trynew2.begin(), trynew2.end(), sort2);
        sort(trynew3.begin(), trynew3.end(), sort3);

        for (int i = 0; i < n - 2; i++)
        {
           // cout << (get<0>(trynew[i])) << (get<1>(trynew[i])) << (get<2>(trynew[i]))<<" ";
        }
        // cout<<endl;
        for (int i = 0; i < n - 2; i++)
        {
           // cout << (get<0>(trynew2[i])) << (get<1>(trynew2[i])) << (get<2>(trynew2[i])) << " ";
        }// cout<<endl;
        for (int i = 0; i < n - 2; i++)
        {
        // cout << (get<0>(trynew3[i])) << (get<1>(trynew3[i])) << (get<2>(trynew3[i])) << " ";
        }

        int firstcount,secondcount,totalcount;
        int tempi;

        // cout<<"first"<<endl;

        for(int i=0; i<n-2; i++)
        {
            tempi = 0;
            if(i+1==n-2) break;
            if(get<0>(trynew[i])==get<0>(trynew[i+1]) && get<1>(trynew[i])==get<1>(trynew[i+1]))
            {
                // // cout<<i<<"Here"<<endl;
                firstcount=0;
                secondcount=0;
                totalcount=0;
                for(int j=i+1; j<n-2;j++)
                {
                    // // cout<<"stage2"<<endl;
                    if (get<0>(trynew[i]) == get<0>(trynew[j]) && get<1>(trynew[i]) == get<1>(trynew[j]))
                    {
                        // // cout<<"stage3"<<endl;
                        firstcount++;
                        if(get<2>(trynew[j-1]) == get<2>(trynew[j]))
                        { secondcount++; }
                        else
                        {
                            totalcount += (secondcount*(secondcount+1))/2;
                            secondcount=0;
                        }
                    }
                    else { i=j;tempi=1; break;}
                }


                totalcount += (secondcount * (secondcount + 1)) / 2;

                int val=0;

                val+= ((firstcount+1)*firstcount)/2;
                val-=totalcount;
                ans+=val;

                // cout<<endl<<firstcount<<" "<<totalcount<<" "<<val<<" "<<ans;
                if (tempi == 0) break;
            }
        }

        // cout<<"second"<<endl;

        for (int i = 0; i < n - 2; i++)
        {
            tempi=0;
            if (i + 1 == n - 2)
                break;

            if (get<1>(trynew2[i]) == get<1>(trynew2[i + 1]) && get<2>(trynew2[i]) == get<2>(trynew2[i + 1]))
            {
                firstcount = 0;
                secondcount = 0;
                totalcount=0;
                for (int j = i + 1; j < n - 2; j++)
                {
                    if (get<1>(trynew2[i]) == get<1>(trynew2[j]) && get<2>(trynew2[i]) == get<2>(trynew2[j]))
                    {
                        firstcount++;
                        if (get<0>(trynew2[j - 1]) == get<0>(trynew2[j]))
                        {
                            secondcount++;
                        }
                        else
                        {
                            totalcount += (secondcount * (secondcount + 1)) / 2;
                            secondcount = 0;
                        }
                    }
                    else
                    {
                        i=j;
                        tempi=1;
                        break;
                    }
                }
                int val = 0;
                totalcount += (secondcount * (secondcount + 1)) / 2;

                val += ((firstcount + 1) * firstcount) / 2;
                val -= totalcount;
                ans += val;

                // cout <<endl<<i<< firstcount << " " << totalcount << " " << val << " " << ans ;
                if(tempi==0) break;
            }
        }

        // cout<<"third"<<endl;
        for (int i = 0; i < n - 2; i++)
        {
            tempi=0;
            if (i + 1 == n - 2)
                break;

            if (get<0>(trynew3[i]) == get<0>(trynew3[i + 1]) && get<2>(trynew3[i]) == get<2>(trynew3[i + 1]))
            {
                firstcount = 0;
                secondcount = 0;
                totalcount=0;
                for (int j = i + 1; j < n - 2; j++)
                {
                    if (get<0>(trynew3[i]) == get<0>(trynew3[j]) && get<2>(trynew3[i]) == get<2>(trynew3[j]))
                    {
                        firstcount++;
                        if (get<1>(trynew3[j - 1]) == get<1>(trynew3[j]))
                        {
                            secondcount++;
                        }
                        else
                        {
                            totalcount += (secondcount * (secondcount + 1)) / 2;
                            secondcount = 0;
                        }
                    }
                    else
                        {i=j; tempi =1; break;}
                }
                totalcount += (secondcount * (secondcount + 1)) / 2;

                int val = 0;

                val += ((firstcount + 1) * firstcount) / 2;
                val -= totalcount;

                ans += val;

                // cout <<endl<< firstcount << " " << totalcount << " " << val << " " << ans;
                if(tempi==0) break;
            }
        }

        // for(int i=0; i<n-3; i++)
        // {
        //     temp1[0] = a[i];
        //     temp1[1] = a[i+1];
        //     temp1[2] = a[i+2];

        //     for( int j=i+1; j<n-2; j++)
        //     {
        //         temp2[0] = a[j];
        //         temp2[1] = a[j+1];
        //         temp2[2] = a[j+2];

        //         ans+= check(temp1,temp2);
        //     }
        // }

        // cout<<endl<<ans<<endl;
        cout<<ans<<endl;
    }

    return 0;
}