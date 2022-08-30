#include <bits/stdc++.h>
using namespace std;
//Link:https://leetcode.com/problems/network-delay-time/
class Graph
{
    vector<pair<int, int>> *adjlist;
    int nver;
    int *dis;

public:
    Graph(int n)
    {
        this->nver = n;
        adjlist =new vector<pair<int, int>>[n+1];
    }
    void addedge(int x, int y, int w)
    {
        adjlist[x].push_back({y, w});
    }
    void dijkastra_STL(int source)
    {
        dis = new int[nver+1];
        for (int i = 1 ;i<=nver; i++)
        {
            dis[i] = INT_MAX;
        }
        dis[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto x : adjlist[u])
            {

                int v = x.first;
                int weight = x.second;
                if (dis[v] > dis[u] + weight)
                {
                    dis[v] = dis[u] + weight;
                    pq.push({dis[v], v});
                }
            }
        }
    }
    int solve(int source){
        dijkastra_STL(source);
        int ans=INT_MIN;
        for (int i = 1; i <= nver; i++){
            ans = max(ans,dis[i]);
        }
        if(ans==INT_MAX) return -1;
        else return ans;

    }
};
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    int e = times.size();
    Graph g1 = Graph(n);
    for (auto i : times)
    {
        g1.addedge(i[0], i[1], i[2]);
    }
    return g1.solve(k);
}
int main()
{
    vector<vector<int>> temp ={{1,2,1}};
    cout<<networkDelayTime(temp,2,1);
}