#include<bits/stdc++.h>

using namespace std;

vector<int>adj_list[100];
vector<int>reverse_list[100];

int vis[100], color[100];

int node, edge;

int indegree[100], flag = 0;

queue<int>q;
stack<int>s;

void dfs(int s)
{
    vis[s] = 1;

    for(int i=0; i<adj_list[s].size(); i++)
    {
        int tmp = adj_list[s][i];

        if(!vis[tmp]) dfs(tmp);
    }
}

void cycle_dfs(int node)
{
    color[node] = 1;

    for(int i=0; i<adj_list[node].size(); i++)
    {
        int u = adj_list[node][i];

        if(color[u]==1) flag = 0;
        if(color[u]==2) continue;
        if(color[u]==0) cycle_dfs(u);
    }
    color[node] = 2;
}

bool cycle_finding()
{
    flag = 1;

    memset(color, 0, sizeof(color));

    for(int i=1; i<=node; i++)
    {
        cycle_dfs(i);
        if(flag==0) return true;
    }
    return false;
}

void topological_sort(int v)
{
    vis[v] = 1;

    for(int i=0; i<adj_list[v].size(); i++)
    {
        int u = adj_list[v][i];

        if(!vis[u]) topological_sort(u);
    }
    s.push(v);
}

void print()
{
    cout<<s.top();
    s.pop();
    while(!s.empty())
    {
        cout<<"->"<<s.top();
        s.pop();
    }
    cout<<endl;
}

void topological_order()
{
    if(cycle_finding())
    {
        cout<<"Error, Cycle exist"<<endl;
        return;
    }

    while(!s.empty()) s.pop();

    memset(vis, 0, sizeof(vis));

    for(int i=1; i<=node; i++)
    {
        if(!indegree[i]) topological_sort(i);
    }
    print();
}



main()
{

    cin>>node>>edge;

    memset(indegree, 0, sizeof(indegree));

    for(int i=0; i<edge; i++)
    {
        int u, v;

        cin>>u>>v;

        adj_list[u].push_back(v);

        reverse_list[v].push_back(u);

        indegree[v]++;
    }

    topological_order();

    return 0;
}
/*
8 14
1 3
1 5
2 1
2 4
2 5
3 2
4 5
4 8
5 3
6 4
6 8
6 7
7 5
8 5
********
4 4
1 2
1 3
2 4
4 3
*/
