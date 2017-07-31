#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[2005];

int vis[2005], ap_no[2005], low[2005], dis[2005], par[2005];

int node, edge;

vector<int>ap;

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

                if(par[u]!=-1 && low[v]>=dis[u]) ap_no[u]=1; //  one child has low >= dis[u], so u is a.p

                if(par[u]==-1 && subtree>1) ap_no[u] = 1; // u is root, so u is a.p if no. of subtree > 1
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

        ap.clear();
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

        for(int i=0; i<node; i++)
        {
            if(ap_no[i]) ap.push_back(i);
        }

        cout<<"Articulation points : "<<ap.size()<<endl;

        cout<<"Articulation points are : ";

        for(int i=0; i<ap.size(); i++)
        {
            cout<<ap[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

