#include<bits/stdc++.h>
using namespace std;


void bfs(int s, vector<int> arr[], bool *vis){

    queue<int> q;
    q.push(s);
    vis[s] = true;
    

    while(!q.empty()){

        int u = q.front(); q.pop();
        cout<<u<<" ";

        for(auto i : arr[u]){
            if(!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
    }
    
}




int main(){
    
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int v,e;
    cin>>v>>e;

    vector<int> arr[v];
    bool vis[v];

    memset(vis,false,sizeof(vis));

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    bfs(0,arr,vis);
    cout<<endl;
    
    
}