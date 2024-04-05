#include<stdio.h>
#include<stdlib.h>

int solve(int N, int * sweets, int k)
{
    int i;

    if(N==0) return 0;

    if(N==1)
    {
        if(sweets[0]==0 && k<=1) return 1;
        return 0;
    }

    if(N==2)
    {
        if(sweets[0]==0 && sweets[1]==0 && k<=1) return 1;
        return 0; 
    }

    if(N>2)
    {   
            if(sweets[0]==0 && sweets[1]==0)
        {
            sweets[0]=1;
            k--;
        }

        for(i=1;i<N-1 && k>0  ;i++)
        {
            if(sweets[i-1]==0 && sweets[i+1]==0)
            {
                sweets[i]=1;
                k--;
            }
            i++;
        }

        if(sweets[N-2]==0 && sweets[N-1]==0 && k>0)
        {
            sweets[N-1]=1;
            k--;
        }

        if(k==0) return 1;
        return 0;

        }
}

int main()
{
    int N;
    scanf("%d",&N);
    int i_sweets;
    int *sweets = (int *)malloc(sizeof(int)*N);

    for(i_sweets=0;i_sweets<N;i_sweets++)
    {
        scanf("%d",&sweets[i_sweets]);
    }

    int K;
    scanf("%d",&K);

    int out_ = solve(N,sweets,K);

    printf("%d", out_);

    return 0;

}