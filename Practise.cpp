#include<bits/stdc++.h>
using namespace std;
struct Graph
{
    int nodes,edges;
    vector<int>adj_list[107];
    int adj_mat[107][107];
    int vis[107],parent[107],dis[107],indegree[107],color[107];
    queue<int> q;
    stack<int> stk;
    int flag = 1;
    void input()
    {
        memset(indegree,0,sizeof(indegree));
        cout<<"Enter the number of nodes and edges: ";
        cin>>nodes>>edges;
        cout<<"Enter the graph\n";
        for(int i=0;i<edges;i++)
        {
            int u,v;
            cin>>u>>v;
            adj_list[u].push_back(v);
            //adj_list[v].push_back(u);
            adj_mat[u][v]=1;
            indegree[v]++;
            //adj_mat[v][u]=1;
        }
    }
    void bfs(int s)
    {
        memset(vis,0,sizeof(vis));

        q.push(s);
        vis[s] = 1;
        dis[s] = 0;
        parent[s] = s;

        while(!q.empty())
        {
            int prev = q.front();
            q.pop();
            for(int i=0;i<adj_list[prev].size();i++)
            {
                int current = adj_list[prev][i];
                if(!vis[current])
                {
                    q.push(current);
                    vis[current] = 1;
                    dis[current] = dis[prev] + 1;
                    parent[current] = prev;
                }
            }
        }
    }
    void shortest_path_length()
    {
        printf("Enter the source and destination nodes : ");
            int u,v;
            cin>>u>>v;
            bfs(u);
            if(vis[v]==0)
                puts("No Path");
            else cout<<"Shortest Path Length "<<dis[v]<<endl;
    }
    void shortest_path_print()
    {
        printf("Enter the source and destination nodes : ");
            int u,v;
            cin>>u>>v;
            bfs(u);
            if(vis[v]==0)
                puts("No Path");
            else cout<<"Shortest Path between "<<u<<" and "<<v<<endl;
            path_print(u,v);
            cout<<endl;

    }
    void path_print(int source,int current)
    {
        if(source==current)
        {
            printf("%d",source);
            return;
        }
        path_print(source,parent[current]);
        printf("->%d",current);
    }
    void bipartite_checking()
    {
        bool bicoloring = isBicolorable(0);
        if(bicoloring==true)
        {
            puts("Graph is bi-colorable");
        }
        else
        {
            puts("Graph is not bi-colorable");
        }
    }
    bool isBicolorable(int s)
    {
        memset(vis,-1,sizeof(vis));

        q.push(s);
        vis[s] = 1;
        dis[s] = 0;
        parent[s] = s;

        while(!q.empty())
        {
            int prev = q.front();
            q.pop();
            for(int i=0;i<adj_list[prev].size();i++)
            {
                int current = adj_list[prev][i];
                if(vis[current]==vis[prev])
                {
                    return false;
                }
                else if(!vis[current])
                {
                    q.push(current);
                    vis[current] = 1 - vis[prev];
                    dis[current] = dis[prev] + 1;
                    parent[current] = prev;
                }
            }
        }
        return true;
    }
    void dfs(int s)
    {
        vis[s] = 1;
        for(int i=0;i<adj_list[s].size();i++)
        {
            if(!vis[adj_list[s][i]])
            {
                dfs(adj_list[s][i]);
            }
        }
    }
    void topological_order()
    {
        if(cycle_finding())
        {
            printf("Cycle Exists. Topological Sort is not possible\n");
            return;
        }
        while(!stk.empty())
            stk.pop();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<nodes;i++)
        {
            if(!indegree[i])
            {
                topological_sort(i);
            }
        }
        topological_order_print();
        cout<<endl;
    }
    void topological_sort(int s)
    {
        vis[s] = 1;
        for(int i=0;i<adj_list[s].size();i++)
        {
            if(!vis[adj_list[s][i]])
            {
                topological_sort(adj_list[s][i]);
            }
        }
        stk.push(s);
    }
    void topological_order_print()
    {
        printf("%d",stk.top());
        stk.pop();
        while(!stk.empty())
        {
            printf("->%d",stk.top());
            stk.pop();
        }
    }
    void check_cycle()
    {
        if(cycle_finding())
        {
            printf("Cycle Exists.\n");
        }
        else
        {
            printf("No Cycle.\n");
        }
    }
    void cycledfs(int node)
    {
        color [node] = 1;

        for(int i=0; i<adj_list[node].size(); i++)
        {
            int u = adj_list[node][i];

            if(color[u]==1)   flag = 0;

            if(color[u]==2)    continue;

            if(color[u]==0) cycledfs(u);
        }

        color[node] = 2;
    }
    bool cycle_finding()
    {
        flag = 1;
        for(int i=0;i<nodes;i++)
        {
           memset(color,0,sizeof(color));//0 for white node , 1 for grey node (child is not visited) , 2 for black node completely visited
           cycledfs(i);
           if(flag == 0)
                return true;
        }
        return false;
    }
    void isTree()
    {
        int cnt = 0, root;

        for(int i=0; i<nodes; i++)
        {
            if(indegree[i]==0)
            {
                cout<<i<<endl;
                root = i;
                cnt++;
            }
        }

        if(cnt!=1)
        {
            cout<<"Not tree"<<endl;//checking whether there are more than one component by checking the in-degree
            return;
        }

        flag = 1;
        memset(color,0,sizeof(color));
        cycledfs(root);
        if(flag==0)
        {
            cout<<"Not tree"<<endl;//checking whether there is a cycle
            return;
        }

        for(int i=0; i<nodes; i++)
        {
            if(color[i]!=2)
            {
                cout<<"Not tree"<<endl;//checking whether there any node which is not visible
                return;
            }
        }

        cout<<"Tree :) "<<endl;
    }
};
int main ()
{
    Graph g;
    puts("\n\n\t\t****************MENU BOARD****************") ;
    puts("\t\t1: Enter a graph");
    puts("\t\t2: Shortest Path Length");
    puts("\t\t3: Shortest Path Print");
    puts("\t\t4: Bipartite Checking");
    puts("\t\t5: Cycle Finding");
    puts("\t\t6: Topological Sort");
    puts("\t\t7: Tree Checking");
    puts("\t\t0: Exit");
    while(1)
    {
        cout<<"Enter your option ";
        int option;
        cin>>option;
        if(!option)
        {
             break;
        }
        else if(option==1)
        {
            g.input();
        }
        else if(option==2)
        {
             g.shortest_path_length();
        }
        else if(option==3)
        {
            g.shortest_path_print();
        }
        else if(option ==4)
        {
            g.bipartite_checking();
        }
        else if(option==5)
        {
            g.check_cycle();
        }
        else if(option==6)
        {
            g.topological_order();
        }
        else if(option==7)
        {
            g.isTree();
        }
    }
    return 0;
}
