#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 1e5, MOD = 1e9 + 7;
// Edges starts from 0 to N-1
class Graph
{
    int numofvertex;
    vector<int> adjlist[MAXN];

    // for BFS
     int distance[MAXN]; // distance from the source
    int visited[MAXN];  // 0=>never visited 1=>visiting 2=>done visited
    int previos[MAXN];  // Stores the immediate parent/previous y
    int discoverytime[MAXN];
    int finishtime[MAXN];
    ll time;
    ll maxD, maxNode;

public:
    Graph(int n_vertex)
    {
        this->numofvertex = n_vertex;
    }
    void add_new_edge(int sourcenode, int destinationnode)
    {
        adjlist[sourcenode].push_back(destinationnode);
        // indeg[destinationnode]++;
        adjlist[destinationnode].push_back(sourcenode); // comment it out if it is a directed graph
        // indeg[sourcenode]++; //toplogical sort
    }
    vector<vector<int>> toadjacencylist()
    {
        // Initialize a matrix
        vector<vector<int>> matrix(numofvertex, vector<int>(numofvertex, 0));

        for (int i = 0; i < numofvertex; i++)
        {
            for (auto j : adjlist[i])
                matrix[i][j] = 1;
        }
        return matrix;
    }
    void printadjmat()
    {
        vector<vector<int>> adjmat = toadjacencylist();
        for (int i = 0; i < adjmat.size(); i++)
        {
            for (int j = 0; j < adjmat.size(); j++)
            {
                cout << adjmat[i][j] << " ";
            }
            cout << endl;
        }
    }
    vector<int> *toadjlist()
    {
        return adjlist;
    }
    void printadjlist()
    {
        for (int i = 0; i < numofvertex; i++)
        {
            cout << i << " : ";
            for (auto j : adjlist[i])
                cout << j << " ";
            cout << "\n";
        }
    }
    void dfs()
    {
        for (int i = 0; i < numofvertex; i++)
        {
            visited[i] = 0;
            previos[i] = -1;
            finishtime[i] = INT_MIN;
            discoverytime[i] = INT_MIN;
        }
        time = 0;
        for (int i = 0; i < numofvertex; i++)
        {
            if (visited[i] == 0)
            {
                dfs_visit(i);
            }
        }
    }
    void dfs_visit(int i)
    {
        time = time + 1;
        discoverytime[i] = time;
        visited[i] = 1;
        for (auto it = adjlist[i].begin(); it != adjlist[i].end(); it++)
        {
            if (visited[*it] == 0)
            {
                previos[*it] = i;
                dfs_visit(*it);
            }
        }
        visited[i] = 2;
        time = time + 1;
        finishtime[i] = time;
    }
    void bfs(int x)
    { // Here x is the root vertex
        for (int i = 0; i < MAXN; i++)
        {
            visited[i] = 0; // 2 means black//1 means grey //0 means white
            previos[i] = INT_MIN;
            distance[i] = INT_MIN;
        }
        queue<int> container_queue;
        container_queue.push(x);
        visited[x] = 1;
        previos[x] = -1;
        distance[x] = 0;

        while (!container_queue.empty())
        {
            int y = container_queue.front();
            container_queue.pop();
            // cout << y << endl;
            vector<int>::iterator it;
            for (it = adjlist[y].begin(); it != adjlist[y].end(); it++)
            {
                if (!visited[*it])
                {
                    visited[*it] = 1;
                    previos[*it] = y;
                    distance[*it] = distance[y] + 1;
                    container_queue.push(*it);
                }
                visited[y] = 2;
            }
        }
    }
    void topologicalsort()
    {
        
    }
    bool isCyclicUtil(int v, bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
  
        // Recur for all the vertices adjacent to this vertex
        for(auto i = adjlist[v].begin(); i != adjlist[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
  
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
    bool isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *recStack = new bool[numofvertex];
    for(int i = 0; i < numofvertex; i++)
    {
        visited[i] = 0;
        recStack[i] = false;
    }
  
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < numofvertex; i++)
        if ( !visited[i] && isCyclicUtil(i,recStack))
            return true;
  
    return false;
}
    bool isCycle()
    {
        vector<int> in_degree(numofvertex, 0);
        for (int u = 0; u < numofvertex; u++)
        {
            for (auto v : adjlist[u])
                in_degree[v]++;
        }
        queue<int> container_queue;
        for (int i = 0; i < numofvertex; i++)
            if (in_degree[i] == 0)
                container_queue.push(i);
        int cnt = 1;
        vector<int> top_order;
        while (!container_queue.empty())
        {
            int u = container_queue.front();
            container_queue.pop();
            top_order.push_back(u);
            vector<int>::iterator itr;
            for (itr = adjlist[u].begin(); itr != adjlist[u].end(); itr++)
                if (--in_degree[*itr] == 0)
                {
                    container_queue.push(*itr);
                    cnt++;
                }
        }
        if (cnt != numofvertex)
            return true;
        else
            return false;
    }
    void printAllPaths(int s, int d)
    {

        // Create an array to store paths
        int *path = new int[numofvertex];
        int path_index = 0; // Initialize path[] as empty

        // Initialize all vertices as not visited
        for (int i = 0; i < numofvertex; i++)
            visited[i] = 0;

        // Call the recursive helper function to print all paths
        printAllPathsUtil(s, d, path, path_index);
    }
    void printAllPathsUtil(int u, int d, int path[], int &path_index)
    {
        // Mark the current y and store it in path[]
        visited[u] = 1;
        path[path_index] = u;
        path_index++;

        // If current vertex is same as destination, then print
        // current path[]
        if (u == d)
        {
            for (int i = 0; i < path_index; i++)
                cout << path[i] << " ";
            cout << endl;
        }
        else // If current vertex is not destination
        {
            // Recur for all the vertices adjacent to current vertex
            vector<int>::iterator i;
            for (i = adjlist[u].begin(); i != adjlist[u].end(); ++i)
                if (!visited[*i])
                    printAllPathsUtil(*i, d, path, path_index);
        }

        // Remove current vertex from path[] and mark it as unvisited
        path_index--;
        visited[u] = false;
    }
    void isBt(int x)
    {
        visited[x] = 1;
        distance[x] = 0;

        queue<int> container_queue;

        container_queue.push(x);

        while (!container_queue.empty())
        {
            int y = container_queue.front();

            container_queue.pop();

            vector<int>::iterator it;
            for (it = adjlist[y].begin(); it != adjlist[y].end(); it++)
            {
                if (visited[*it] == -1)
                {

                    visited[*it] = 1;
                    distance[*it] = !distance[y];
                    container_queue.push(*it);
                }
            }
        }
    }
    bool isBipartite()
    {
        for (int i = 0; i < numofvertex; ++i)
        {
            visited[i] = -1;
            distance[i] = -1;
        }
        for (int i = 0; i < numofvertex; i++)
            if (visited[i] == -1)
                isBt(i);

        for (int i = 0; i < numofvertex; i++)
        {
            for (auto it : adjlist[i])
            {
                if (distance[i] == distance[it])
                    return false;
            }
        }
        return true;
    }
    void PrintShortestPathBFS(int source, int destination)
    {
        bfs(source);
        if (distance[destination] == INT_MIN)
            cout << "No Path Exists" << endl;
        else
        {
            stack<int> ans;
            int iterator = destination;
            while (previos[iterator] != -1)
            {
                ans.push(iterator);
                iterator = previos[iterator];
            }
            ans.push(iterator);
            while (!ans.empty())
            {
                cout << ans.top() << " ";
                ans.pop();
            }
            cout << endl;
        }
    }
    void modifiedbfs(int x)
    { // Here x is the root vertex
        for (int i = 0; i < MAXN; i++)
        {
            visited[i] = 0; // 2 means black//1 means grey //0 means white
            previos[i] = INT_MIN;
            distance[i] = INT_MIN;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> container_queue;
        container_queue.push({0, x});
        visited[x] = 1;
        previos[x] = -1;
        distance[x] = 0;

        while (!container_queue.empty())
        {
            int node = container_queue.top().second;
            int dis = container_queue.top().first;
            container_queue.pop();
            for (auto it = adjlist[node].begin(); it != adjlist[node].end(); it++)
            {
                if (!visited[*it])
                {
                    visited[*it] = 1;
                    previos[*it] = node;
                    distance[*it] = distance[node] + 1;
                    container_queue.push({dis + 1, *it});
                }
                visited[node] = 2;
            }
        }
    }
    void printlexicographicallyshortestpath(int source, int destination)
    {
        modifiedbfs(source);
        if (distance[destination] != INT_MIN)
        {
            stack<int> s1;
            int v = destination;
            s1.push(v);
            while (previos[v] != -1)
            {
                s1.push(previos[v]);
                v = previos[v];
            }
            while (!s1.empty())
            {
                cout << s1.top();
                s1.pop();
                if (!s1.empty())
                    cout << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Not Reachable" << endl;
        }
    }
    int countTriangle(vector<vector<int>> graph, bool isDirected)
    {
        int count_Triangle = 0;

        // Consider every possible
        // triplet of edges in graph
        for (int i = 0; i < numofvertex; i++)
        {
            for (int j = 0; j < numofvertex; j++)
            {
                for (int k = 0; k < numofvertex; k++)
                {
                    // Check the triplet if
                    // it satisfies the condition
                    if (graph[i][j] && graph[j][k] && graph[k][i])
                        count_Triangle++;
                }
            }
        }
        // If graph is directed ,
        // division is done by 3,
        // else division by 6 is done
        isDirected ? count_Triangle /= 3 : count_Triangle /= 6;

        return count_Triangle;
    }
    void lengthcalc(int node, int distance)
    {
        visited[node] = 1;
        if (distance > maxD)
        {
            maxD = distance, maxNode = node;
            cout << maxD << " " << maxNode << endl;
        }

        for (auto child : adjlist[node])
        {
            if (visited[child] == 0)
                lengthcalc(child, distance + 1);
        }
    }
    int maximumpathlength()
    {
        for (int i = 0; i < numofvertex; i++)
        {
            visited[i] = 0;
        }
        maxD = INT_MIN;
        for (int i = 0; i < numofvertex; i++)
        {
            lengthcalc(i, 0);
            lengthcalc(maxNode, 0);
        }
        return maxD;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n_nodes, n_edges, u, v;
    cin >> n_nodes;
    cin >> n_edges;
    Graph graph1(n_nodes);
    while (n_edges--)
    {
        cin >> u >> v;
        graph1.add_new_edge(u, v);
    }
    graph1.printadjlist();
    graph1.dfs();
    // graph1.printlexicographicallyshortestpath(1, 3);
    // graph1.PrintShortestPathBFS(1, 3);
    // graph1.topologicalsort();
    // graph1.printadjmat();
    // cout << graph1.countTriangle(graph1.toadjacencylist(), 1);

    return 0;
}
