#include<bits/stdc++.h>
using namespace std;

int main()
{
    // declaring a 2D vecotr
   // vector<vector<char>> x(8,vector<char>(8,'.'));
   vector<char> board(64,'\0');

   for(int i=0; i<64; i++)
   {
        cin>>board[i];
   }

   for(int i=0;i<8;i++)
   {
    for(int j=0; j<8;j++)
    {
        cout<<board[8*i+j]<<" ";
    }
        cout<<endl;
   }

   return 0;
   



}