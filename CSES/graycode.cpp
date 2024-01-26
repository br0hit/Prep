#include<bits/stdc++.h>
using namespace std;

vector<string> graycode(int n)
{
    if(n==1)
    {
        vector<string> x;
        string one = "1";
        string zero = "0";
        x.push_back(zero);
        x.push_back(one);

        return x;
    }
    else
    {
        int npower,nminus1power;
        npower = pow(2,n);
        nminus1power = pow(2,n-1);

        vector<string> prev= graycode(n-1);
        vector<string> current(npower,"\0");


        for(int i=0; i<nminus1power; i++)
        {
            string temp;
            temp = "0"+ prev[i];
           // cout<<temp;
            current[i] = temp;
        }

        for(int i=nminus1power-1; i>=0; i--)
        {
            string temp;
            temp = "1"+ prev[i];
           // cout<<temp;
            current[2*nminus1power-i-1] = temp;
        }

        return current;
    }


}

int main()
{
    int n;
    cin>>n;

    vector<string> answer = graycode(n);

    for(int i=0; i<pow(2,n);i++)
    {
        cout<<answer[i]<<endl;
    }
    


    return 0;

}