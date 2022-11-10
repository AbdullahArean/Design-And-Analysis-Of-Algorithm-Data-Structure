#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
const ll MAXN = 1000000;
ll DivisorCount[MAXN], arr[MAXN],countnum;
ll BSUpperBound(ll arr[], ll N, ll value) {
    ll low = 0,high = N-1, mid;
    while (low < high) {
        //prllarray(arr,low,high);
        mid = low+ (high-low)/2;
        if(arr[mid]>value)  high = mid;
        else low= mid+1;
    }
    if(value>=arr[N-1]) low++; //To match built in functions
    return low;
}
ll BSLowerBound(ll arr[], ll N, ll value) {
     ll low = 0,high = N-1, mid;
    while (low < high) { //No Equal Sign Needed
        //prllarray(arr,low,high);
        mid = low+ (high-low)/2;

        if(arr[mid]>=value) {
            high = mid;
        } 
        else {
            low= mid+1;
        }
    }
    if(value>=arr[N-1]) low++; //To match built in functions
    return low;
}
void DivisorCountTill(){
    for (ll i = 1; i <= MAXN; i++) {
    for (ll j = i; j <= MAXN; j += i) {
        DivisorCount[j]++; //// here cnt[x] means count of divisors of x
    }
    }
}
void generateseq(){
    DivisorCountTill();
    arr[0]=1;
    ll i=1;
    for(i; ; i++){
        arr[i] = arr[i-1]+ DivisorCount[arr[i-1]];
        if(arr[i]>=MAXN) {countnum=++i;return;}
    }

}
int main(){
    generateseq();
    //for(int i=0; i<countnum; i++) cout<<arr[i]<<endl;
    ll n;
    cin>>n;
    for(int k=1; k<=n; k++)
    {
        ll a, b;
        cin>>a>>b;
        printf("Case %d: %lld\n",k ,BSUpperBound(arr,countnum,b)-BSLowerBound(arr, countnum,a));
    }
    return 0;
}