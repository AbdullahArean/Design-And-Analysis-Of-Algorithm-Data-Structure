#include<bits/stdc++.h>
using namespace std;


void dfs(int s, vector<int> arr[], bool *vis){
    vis[s] = true;
    cout<<s<<" ";
    for(auto i : arr[s]){
        if(!vis[i]) dfs(i,arr,vis);
    }
}




int main(){
    
    freopen("input.txt","r",stdin);
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

    dfs(0,arr,vis);
    cout<<endl;
    
    
}