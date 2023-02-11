/*
Problem Link  : https://onlinejudge.org/external/100/10041.pdf
Tags          : Median is the saviour
Notes         :
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
void printarray(int arr[],int low, int high){
    for(int i=low; i<=high; i++) printf("%d ",arr[i]);
    printf("\n");
}
int BSUpperBound(int arr[], int N, int value) {
    int low = 0,high = N-1, mid;
    while (low < high) {
        //printarray(arr,low,high);
        mid = low+ (high-low)/2;
        if(arr[mid]>value)  high = mid;
        else low= mid+1;
    }
    if(value>=arr[N-1]) low++; //To match built in functions
    return low;
}
int BSLowerBound(int arr[], int N, int value) {
     int low = 0,high = N-1, mid;
    while (low < high) {
        //printarray(arr,low,high);
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
int BinarySearch(int arr[], int N, int value){
   
    int low = 0,high = N-1, mid;
    while(low<=high){ //Equal Sign is a must or else false result!
        //printarray(arr,low,high);
        mid = (high+low)/2;
        if(arr[mid]>value) high=mid-1;
        else if( arr[mid]<value) low = mid+1;
        else return 1;
    }
    return -1;

}
long long int distance(int arr[], int n, int x){
    long long int dis=0;
    for(int i=0; i<n; i++){
        dis+=abs(arr[i]-x);
    }
    return dis;
}
void Solution1(){ //Bruteforce
    int n,r, arr[30001], max, min;
    cin>>n;
    while(n--){ 
        cin>>r;
        for(int i=0; i<r; i++){
            cin>>arr[i];
            if(i==0)  {max= arr[i]; min = arr[i];}
            else if(arr[i]>max) max= arr[i];
            else if(arr[i]<min) min= arr[i];

        }
        long long int  ansdist;
        for(int i=min; i<=max; i++)
        {
            long long int dis= distance(arr, r,i);
            if(i==min) ansdist= dis;
            else if(ansdist>dis) ansdist = dis;
        }
        printf("%d\n", ansdist); 
    }
}
void Solution(){
     int n,r, arr[(int)1e6];
    cin>>n;
    while(n--){ 
        cin>>r;
        for(int i=0; i<r; i++) cin>>arr[i];
        sort(arr, arr+n);
        int median = arr[r / 2];

		int ans = 0;
		for (int i = 0; i < r; i++) {
			ans += abs(median - arr[i]);
		}
		printf("%d\n", ans);       
    }

}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	Solution();
	return 0;
}