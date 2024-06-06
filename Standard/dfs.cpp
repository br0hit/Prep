#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> (&adj)[6], bool (&visited)[6], int curr_node)
{
    if (visited[curr_node] == 0)
        visited[curr_node]=  1;
    else return;
    cout<<"Here"<<curr_node<<endl;
    for(int i=0; i<adj[curr_node].size(); i++)
    {
        int nodeval = adj[curr_node][i];
        cout<<nodeval<<endl;
        if(visited[nodeval]==0)
        {
            // visited[nodeval]=1;
            dfs(adj, visited, nodeval);
        }
    }

    return;
}

void bfs(vector<int> (&adj)[7], bool (&visited)[7], queue<int> nextlevel, int &distance)
{
    while(!nextlevel.empty())
    {
        int nodeval = nextlevel.front();
        nextlevel.pop();

        visited[nodeval] =1;

        cout<<nodeval<<" "<<distance<<endl;

        for(int i=0; i<adj[nodeval].size(); i++)
        {
            if(visited[adj[nodeval][i]]==0)
            nextlevel.push(adj[nodeval][i]);
        }
    }

}

int main()
{
    vector<int> adj[6];
    vector<int> newadj[7];
    bool visited[6];
    bool newvisited[7];

    for(int i=1; i<6; i++)
    {
        visited[i] =0;
        cout<<visited[i];
    }

    for (int i = 1; i < 7; i++)
    {
        newvisited[i] = 0;
        cout << visited[i];
    }

    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[2].push_back(5);
    adj[3].push_back(5);
    adj[5].push_back(2);

    // newadj[1] = vector<int> {2,4};
    // cout<<"atleaset that works"<<endl;
    // newadj[2] = vector<int> {1,3,5};
    // newadj[3] = vector<int> {2,6};
    // newadj[4] = vector<int> {1};
    // newadj[5] = vector<int> {2,6};
    // newadj[6] = vector<int> {3,5};

    newadj[1].push_back(2);
    newadj[1].push_back(4);
    newadj[2].push_back(3);
    newadj[2].push_back(5);
    newadj[3].push_back(2);
    newadj[3].push_back(6);
    newadj[4].push_back(1);
    newadj[5].push_back(2);
    newadj[5].push_back(6);
    newadj[6].push_back(1);

    cout<<"DFS starting"<<endl;

    dfs(adj,visited,1);

    cout<<endl;
    for (int i = 1; i < 6; i++)
    {
        cout << visited[i];
    }

    cout<<endl<<"BFS Starting"<<endl;

    queue<int> visitedlist;
    visitedlist.push(1);

    int distance=0;

    bfs(newadj, newvisited, visitedlist, distance);
}