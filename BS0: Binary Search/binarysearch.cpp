/*
Problem Link  : Binary Search, Lower Bound and Upper Bound Implemented and matched with STL
About Problem : Binary Search Implementation
Tags          : 
Notes         :
        lower_bound returns an iterator pointing to the first element 
        in the range [first,last) which has a value not less than ‘val’. 
        upper_bound returns an iterator pointing to the first element in the 
        range [first,last) which has a value greater than ‘val’. 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
void printarray(int arr[],int low, int high){
    for(int i=low; i<=high; i++) printf("%d ",arr[i]);
    printf("\n");
}
int LOWER_BOUND(int arr[], int N, int X)
{
    int MIDELEMENT;
    int LOW = 0;
    int HIGH = N;
    while (LOW < HIGH) {
        MIDELEMENT = LOW + (HIGH - LOW) / 2;
        if (X <= arr[MIDELEMENT]) {
            HIGH = MIDELEMENT;
        }
        else {
            LOW = MIDELEMENT + 1;
        }
    }
    if(LOW < N && arr[LOW] < X) {
       LOW++;
    }
    return LOW;
}
int UPPER_BOUND(int arr[], int N, int X)
{
    int MIDELEMENT;
    int LOW = 0;
    int HIGH = N;
    while (LOW < HIGH) {
        MIDELEMENT = LOW + (HIGH - LOW) / 2;
        if (X >= arr[MIDELEMENT]) {
            LOW = MIDELEMENT + 1;
        }
        else {
            HIGH = MIDELEMENT;
        }
    }
    if(LOW < N && arr[LOW] <= X) {
       LOW++;
    }
    return LOW;
}
int BinarySearch(int arr[], int N, int value){
   
    int low = 0,high = N-1, mid;
    while(low<=high){ //Equal Sign is a must or else false result!
        //printarray(arr,low,high);
        mid = (high+low)/2;
        if(arr[mid]>value) high=mid-1;
        else if( arr[mid]<value) low = mid+1;
        else return mid;
    }
    return -1;

}
//Modified Binary Search for returning Bounded
int BinarySearchBounded(int arr[], int start, int end, int value){
   
    int low = start,high = end, mid;
    while(low<=high){ //Equal Sign is a must or else false result!
        //printarray(arr,low,high);
        mid = (high+low)/2;
        if(arr[mid]>value) high=mid-1;
        else if( arr[mid]<value) low = mid+1;
        else return mid;
    }
    return -1;

}
void Solution(){
    int arr[] = {2, 5,5,5,5,5 ,23, 45, 78, 345, 768, 987, 1098, 1099};
    int N= sizeof(arr)/sizeof(arr[0]);
    
    
    	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}