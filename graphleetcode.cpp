int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> container;
        int n=board.size();
        n=n*n+1;
        int vis[n];
        int dis[n];
        for(int i=0; i<n; i++){
            vis[n]=0;
            dis= INT_MAX;
        }
        container.push(1);
        dis[1]=0;
        vis[1]=1;
        while(container.empty()){
            int u= container.front();
             container.pop();
            for(int i=1; i<=6; i++){
                v= u+1;
                if(vis[v]==0){
                vis[v]=1;
                dis[v]=dis[u]+1;
                container.push(v);
                }
            }
            
        }
        
    }
