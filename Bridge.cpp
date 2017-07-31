#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[2005];

int vis[2005], ap_no[2005], low[2005], dis[2005], par[2005];

int node, edge;

vector<int>bridge;

struct Graph
{
    int time = 0;

    void input()
    {
        int u, v;

        for(int i=0; i<edge; i++)
        {
            cin>>u>>v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
    }

    void dfs(int u)
    {
        vis[u] = 1;

        dis[u] = low[u] = ++time;

        int subtree = 0, v;

        for(int i=0; i<adj_list[u].size(); i++)
        {
            v = adj_list[u][i];

            if(!vis[v])
            {
                subtree++;

                par[v] = u;

                dfs(v);

                low[u] = min(low[u], low[v]);

                if(low[v]>dis[u])
                {
                    bridge.push_back(u);
                    bridge.push_back(v);
                }
            }

            else if(v!=par[u]) low[u] = min(low[u], dis[v]);// edge u->v is back edge. comparing with dis[v] because we can use at most one back edge
        }

    }

    void reset()
    {
        memset(vis, 0, sizeof(vis));

        memset(dis, 0, sizeof(dis));

        memset(low, 0, sizeof(low));

        memset(par, -1, sizeof(par));

        memset(ap_no, 0, sizeof(ap_no));

        for(int i=0; i<node; i++) adj_list[i].clear();

        bridge.clear();
    }
};

main()
{
    freopen("in.txt", "r", stdin);

    Graph g;

    int test;

    cin>>test;

    while(test--)
    {
        g.reset();

        cin>>node>>edge;

        g.input();

        for(int i=0; i<node; i++)
        {
            if(!vis[i]) g.dfs(i);
        }

        cout<<"No. of Bridge : "<<bridge.size()/2<<endl;

        cout<<"Bridges are:"<<endl;

        for(int i=0; i<bridge.size(); i+=2)
        {
            cout<<bridge[i]<<"->"<<bridge[i+1]<<endl;
        }
        cout<<endl;
    }

    return 0;
}

