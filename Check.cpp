#include<bits/stdc++.h>
using namespace std;

int messageRoute(int n, vector<vector<int>>edges)
{
    vector<int> adjl[100001];
    for(auto i:edges)
    {
        adjl[i[0]].push_back(i[1]);
        adjl[i[1]].push_back(i[0]);
    
    }
    int vis[100001];
    int dis[100001];
    for(int i=1; i<=n; i++)
    {
        vis[i]=0;
        dis[i]=INT_MAX;
    }
    vis[1]=1;
    dis[1]=0;
    queue<int> con;
    con.push(1);
    while(!con.empty())
    {
        int u= con.front();
        con.pop();
        for(auto v: adjl[u])
        {
            if(vis[v]==0)
            {
                vis[v]=1;
                dis[v]=dis[u]+1;
                con.push(v);
            }
        }
    }
    if(dis[n]==INT_MAX) return -1;
    else return dis[n];
}