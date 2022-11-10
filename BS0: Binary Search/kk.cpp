#include<bits/stdc++.h>
using namespace std;
const long long int MAXN = 100000;

int nightneeded(int arr[], int num, int maxd){
    int cur=maxd;
    int ans=0;
    for(int i=0; i<num+1; i++){
        if(arr[i]>maxd) return -1;
        if(cur>=arr[i]) {cur-=arr[i];}
        else {
            cur=maxd; ans++;
            cur-=arr[i];
        }
    }
    if(ans==0) ans++;
    return ans;
}
void print(int arr[], int num, int maxd){
    int cur=maxd;
    int print=0;
    for(int i=0; i<num+1; i++){
        if(cur>=arr[i]) {cur-=arr[i];print+=arr[i];}
        else {
            cout<<print<<endl;
            print=0;
            cur=maxd;
            print+=arr[i];
            cur-=arr[i];
        }
    }
    cout<<print<<endl;
}
int binarysearch(int arr[], int n, int k){
        int lo=1, hi=MAXN, mid;
        while(hi>lo){
            int mid =  lo +(hi-lo)/2;
            int night=nightneeded(arr, n,mid);
            if(night==-1) lo=mid+1;
            else if(night>k)lo=mid+1;
            else if(night<k) hi=mid-1;
            else lo=mid;
        }
        return lo;
}
int main(){
     freopen("inp.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n, k, arr[MAXN];
        cin>>n>>k;
        for(int j=0; j<n+1; j++) cin>>arr[j];
        //cout<<nightneeded(arr, n, 100)<<endl;
        int ans = binarysearch(arr, n,k);
        printf("Case %d: %d\n", i+1,ans);
        print(arr, n, ans);
    }
}