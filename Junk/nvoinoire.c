#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count_unique_char(char* str) 
{

	int hash[128] = { 0 };
	int i, c = 0;

	for (i = 0; i < strlen(str); ++i)
    {
		hash[str[i]]++;
	}

	for (i = 0; i < 128; ++i) 
    {
		if(hash[i]==1) c++;
	}

	return c;

}

char * solve(int N, char ** words)
{
    int i,temp;
    int score_max,score;

    for(i=0,score=0,score_max=0,temp=0;i<N;i++)
    {
        score = count_unique_char(*(words+i));

        if(score_max<score)
        {
            score_max=score;
            temp=i;

        }
    }

    return words[temp];
}



int main()
{
    int N;
    scanf("%d",&N);

    int i_words;
    char **words = (char **)malloc(sizeof(char *)*N);

    for(i_words=0;i_words<N;i_words++)
    {
        words[i_words]= (char *)malloc(51200* sizeof(char));

        scanf("%s",words[i_words]);

    }

    char* out_ = solve(N, words);
    printf("%s",out_);

    return 0;
}