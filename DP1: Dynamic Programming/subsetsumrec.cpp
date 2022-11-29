#include<bits/stdc++.h>
using namespace std;
vector<int> given ={2,3,5,7};
int subsetsum(int S, int k){
    if(S==0) return 1;
    if(S>0 && k>given.size()) return 0;
    if(S<0) return 0;
    return subsetsum(S-given[k],k+1)+subsetsum(S, k+1);
}
int main(){
    subsetsum(14,0);

}
