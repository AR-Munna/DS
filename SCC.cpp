#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[100];
vector<int>reverse_list[100];
vector<char>component[100];

int vis[100], color[100];

int node, edge;

int indegree[100], flag = 0;

queue<int>q;
stack<int>stk;


void dfs(int s)
{
    vis[s] = 1;

    for(int i=0; i<adj_list[s].size(); i++)
    {
        int tmp = adj_list[s][i];

        if(!vis[tmp]) dfs(tmp);
    }
    stk.push(s);
}

void dfs2(int s, int id)
{
    vis[s] = 1;

    for(int i=0; i<reverse_list[s].size(); i++)
    {
        int tmp = reverse_list[s][i];

        if(!vis[tmp])
        {
            dfs2(tmp, id);
        }
    }
    component[id].push_back(s+64);
}


main()
{
    cin>>node>>edge;

    int cnt=0;

    memset(indegree, 0, sizeof(indegree));

    for(int i=0; i<edge; i++)
    {
        int u, v;

        cin>>u>>v;

        adj_list[u].push_back(v);

        reverse_list[v].push_back(u);

        indegree[v]++;
    }

    memset(vis, 0, sizeof(vis));

    for(int i=1; i<=node; i++)
    {
        if(!vis[i]) dfs(i);
    }

    memset(vis, 0, sizeof(vis));

    for(int i=0; i<stk.size(); i++)
    {
        int tmp = stk.top();
        stk.pop();

        if(!vis[tmp])
        {
            dfs2(tmp, ++cnt);
        }
    }

    cout<<cnt<<endl;

    for(int i=1; i<=cnt; i++)
    {
        cout<<"Component: "<<i<<":";
        for(int j=0; j<component[i].size(); j++)
        {
            cout<<component[i][j]<<" ";
        }
        puts("");
    }

    return 0;
}
