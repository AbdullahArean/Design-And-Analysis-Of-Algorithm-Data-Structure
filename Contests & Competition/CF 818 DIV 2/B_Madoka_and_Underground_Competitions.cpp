#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n, k, r, c;
    cin>>n>>k>>r>>c;
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(((i+j)-(r+c))%k==0) cout<<'X';
        else cout<<'.';
      }
      cout<<"\n";
    }
  }
}