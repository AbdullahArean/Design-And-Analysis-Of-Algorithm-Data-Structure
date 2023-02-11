#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int source, destination;
vector<int> association;
int bfs(int source, int destination, vector<int> &ancestor, vector<vector<int>> &weight, vector<vector<int>> adjacencymatrix)
{
    fill(ancestor.begin(), ancestor.end(), -1);
    ancestor[source] = -2;
    queue<pair<int, int>> tempqueue;
    tempqueue.push({source, INT_MAX});
    while (!tempqueue.empty())
    {
        int cur = tempqueue.front().first;
        int total_cost = tempqueue.front().second;
        tempqueue.pop();

        for (int next : adjacencymatrix[cur])
        {
            if (ancestor[next] == -1 && weight[cur][next])
            {
                ancestor[next] = cur;
                int cost = min(total_cost, weight[cur][next]);
                if (next == destination)
                    return cost;
                tempqueue.push({next, cost});
            }
        }
    }
    return 0;
}
int edmondcarp(int points, int source, int destination, vector<vector<int>> &weight, vector<vector<int>> adjacencymatrix)
{
    int total_cost = 0;
    vector<int> ancestor(points);
    int cost;

    while (cost = bfs(source, destination, ancestor, weight, adjacencymatrix))
    {
        total_cost += cost;
        int cur = destination;
        while (cur != source)
        {
            int prev = ancestor[cur];
            if(prev!=source && cur!=destination)association[prev]=cur;
            weight[prev][cur] -= cost;
            weight[cur][prev] += cost;
            cur = prev;
        }
    }

    return total_cost;
}

int dest_reached = 0;
void dfs(int u, int p, int source, int destination, vector<pair<int, int>> &dfsstack, vector<vector<int>> &weight, vector<bool> &visited, vector<vector<int>> adjacencymatrix)
{
    if (dest_reached)
        return;
    visited[u] = true;
    if (p != -1)
        dfsstack.push_back({p, u});
    for (int v : adjacencymatrix[u])
    {
        if (!visited[v] && weight[u][v])
        {
            dfs(v, u, source, destination, dfsstack, weight, visited, adjacencymatrix);
            if (v == destination)
            {
                dfsstack.push_back({u, destination});
                dest_reached = true;
                return;
            }
        }
    }
    if (dest_reached)
        return;
    dfsstack.pop_back();
}
int fordfulkerson(int points, int source, int destination, vector<vector<int>> weight, vector<vector<int>> adjacencymatrix)
{
    vector<bool> visited;
    int total_cost = 0;
    vector<pair<int, int>> dfsstack;
    while (!dest_reached)
    {
        dfsstack.clear();
        visited.assign(points, false);
        dfs(source, -1, source, destination, dfsstack, weight, visited, adjacencymatrix);
        if (dest_reached)
        {
            int cost = INT_MAX;
            for (auto it : dfsstack)
            {
                int u = it.first, v = it.second;
                cost = min(cost, weight[u][v]);
            }
            total_cost += cost;
            for (auto it : dfsstack)
            {
                int u = it.first, v = it.second;
                weight[u][v] -= cost;
                weight[v][u] += cost;
            }
        }
        dest_reached ^= 1;
    }
    return total_cost;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    
    
    vector<vector<int>> adjacencymatrix;
    vector<vector<int>> weight, storeweight;
    int points, people, books,edges;
    
    cin >> points>>people>>books;
    cout<<"Number Of Points: "<<points<<endl;
    cin >> edges;
    cout<<"Number Of Edges: "<<edges<<endl;
    adjacencymatrix.assign(points, vector<int>());
    weight.assign(points, vector<int>(points, 0));
    association.assign(people,-1);
    for (int i = 0; i < edges; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        adjacencymatrix[u].push_back(v); adjacencymatrix[v].push_back(u);
        weight[u][v] = c;
    }

    source=points-2;
    destination=points-1;
    for(int i=0; i<people; i++){
         adjacencymatrix[source].push_back(i); adjacencymatrix[i].push_back(source);
        weight[source][i] = 1;

    }
    for(int j=0; j<books; j++){
        adjacencymatrix[people+j].push_back(destination); 
        adjacencymatrix[destination].push_back(people+j);
        weight[people+j][destination] = 1;

    }
    // Stored Weight To Use Again
    storeweight = weight;
    auto start = high_resolution_clock::now();
    cout << "Max Flow: ";
    cout << edmondcarp(points, source, destination, weight, adjacencymatrix) << "  ";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by edmondcarp: "
         << duration.count() << " microseconds" << endl;

    weight = storeweight;
    start = high_resolution_clock::now();
    cout << "Max Flow: ";
    cout << fordfulkerson(points, source, destination, weight, adjacencymatrix) << "  ";
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by fordfulkerson: "
         << duration.count() << " microseconds" << endl;
    for(int i=0; i<people; i++){
        cout<<"P"<<i+1<<"===>"<<"B"<<association[i]+1-people<<endl;
    }
}