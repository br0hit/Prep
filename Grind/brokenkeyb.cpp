#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        // vector<pair<char,int>> capital,small;
        // vector<int>b(s.size() , 1) ;

        vector<char> capital,small;
        vector<int> capital_int, small_int;

        for(int i=0; i<s.size(); i++)
        {

            if(s[i]=='b')
            {
                // small.pop_back();
                if(!small_int.empty()) small_int.pop_back();
                // small_int.push_back(-1);
                // small_int.push_back(0);
               
            }
            else if(s[i]=='B')
            {
                // capital.pop_back();
                if(!capital_int.empty()) capital_int.pop_back();
                // capital_int.push_back(-1);
                // capital_int.push_back(-1);
                
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                small.push_back(s[i]);
                small_int.push_back(i);
            }
            else
            {
                capital.push_back(s[i]);
                capital_int.push_back(i);
            } 
        }
                            cout<<"charunprn"<<endl;



        for(int i=0; i<capital_int.size(); i++) cout<<capital_int[i];
        cout<<endl;
                for(int i=0; i<small_int.size(); i++) cout<<small_int[i];


        int i=0,j=0;

        while( i<= small_int.size() && j<= capital_int.size())
        {
            if(small_int[i]<capital_int[j])
            {
                cout<<s[small_int[i]];
                i++;
            }
            else
            {
                cout<<s[capital_int[j]];
                j++;
            }
        }


    }

    return 0;
}

