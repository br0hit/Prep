    #include <bits/stdc++.h>
    #include <iostream>
    using namespace std;

    int main()
    {
        int t;
        cin >> t;

        while (t--)
        {

            int a,b,l;
            cin>>a>>b>>l;

            int pow_a,pow_b;
            int copy=l;
            int copy_new;

            pow_a = pow_b = 0;

            copy = l;
            int count=0;

            copy_new = l;
            while(pow_a>=0)
            {
                pow_b=0;
                copy = copy_new;
                while (copy > 0)
                {
                    if (copy % b == 0)
                    {
                        copy /= b;
                        pow_b++;
                    }
                    else
                        break;
                }

                count+= ++pow_b; 
                // cout<<count<<pow_a<<pow_b<<endl;
                copy_new/=a;
                pow_a--;
                
            }

            cout<<count<<endl;
        }

        return 0;
    }
