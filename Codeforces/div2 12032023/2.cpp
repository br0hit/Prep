    #include<iostream>
    using namespace std;

    int main()
    {
        int ts;
        long long int n,p,l,t;
        long long int x,y,z,w, no_tasks;
        long long int amount1, amount2, amount3;




        cin>>ts;

        while(ts--)
        {
            cin>>n>>p>>l>>t;
            x=0;

            no_tasks = ((n-1)/7)+1;
            // cout<<"No of tasks: "<<no_tasks<<"\n";

            amount1 = l + t*2;

            // if(no_tasks>=2)
            // {
            //     y = p/amount1;

            //     if(y==0)
            //     {
            //         cout<<n-1<<"\n";
            //         continue;
            //     }
            //     else
            //     {

            //     }
            // }

            


            if(p == n*l + no_tasks*t) 
            {
                cout<<"0\n";
                continue;
            }

            while(p>0)
            {
                if(no_tasks>=2)
                {
                    p-= l + t*2;
                    no_tasks-=2;
                }
                else if(no_tasks==1)
                {
                    p-= l + t;
                    no_tasks-=1; 
                }
                else
                {
                    p-= l;
                }

                x++;
            }  

            cout<<n-x<<"\n";

        }

        return 0;
    }