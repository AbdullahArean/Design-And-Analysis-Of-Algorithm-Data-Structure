#include<bits/stdc++.h>
using namespace std;
int Mat[1001][1001]; //Memoization
vector<int> given ={2,3,5,7,10, 12, 14, 15, 17, 18, 20, 21, 34,56};
int subsetsum(int S, int k){
    if(S==0) return 1;
    if(S>0 && k>given.size()) return 0;
    if(S<0) return 0;
    if(Mat[S][k] != -1) return Mat[S][k]; //Memoization
    return Mat[S][k]=subsetsum(S-given[k],k+1)+subsetsum(S, k+1);
}
int main(){
  memset(Mat,-1,sizeof(Mat)); //Memoization
  for(int i=1; i<=100; i++)
    cout<<i<<" : "<<subsetsum(i,0)<<"\n";

}