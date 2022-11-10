#include <bits/stdc++.h>
using namespace std;
#define IO ios_base :: sync_with_stdio(0),cin.tie(0)
#define ll long long int
#define ull unsigned long long int

#define WHITE 0 //Not visited
#define GREY 1 //Started visiting
#define BLACK 2 //Finished visiting


int depth[1005][1005]; //Keep track of the distance
int color[1005][1005]; //Keep track of the color
char grid[1005][1005]; //The given grid 

//Important Concept : In grid we can move to four sides, there dx[i], dy[i] easily
//keep track of where to go next
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int BFS(int n,int m,int sx, int sy, int desx, int desy){
    //We will apply simple BFS on Grid
    queue<int>q; //A queue to keep track which box visited or not

    int vx,vy,ux,uy; //u is the current working box and v is any adjacent box of u
    
    while(!q.empty()) q.pop(); //Making the queue empty

    q.push(sx);
    q.push(sy);

    color[sx][sy] = GREY;
    depth[sx][sy] = 0;

    while(!q.empty()){
        ux = q.front();
        q.pop();

        uy = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            vx = ux + dx[i];
            vy = uy + dy[i];

            if(vx>=0 && vx<n && vy>=0 && vy<m && grid[vx][vy]!='#' && color[vx][vy]==WHITE)
            {
                color[vx][vy]=GREY;
                depth[vx][vy]=depth[ux][uy]+1;
                q.push(vx);
                q.push(vy);
            }
        }
        color[ux][uy]=BLACK;
    }
    if(depth[desx][desy]==INT_MIN) return -1;
    return depth[desx][desy];
}



int main(){
   IO; //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    int n,m;
    scanf("%d%d",&n, &m);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            color[i][j] = 0;
            depth[i][j] = INT_MIN;
        }

    for(int i=0; i<n; i++)
        scanf("%s",grid[i]);
    
    printf("%d\n",BFS(n,m,0,0,n-1,m-1));
}
