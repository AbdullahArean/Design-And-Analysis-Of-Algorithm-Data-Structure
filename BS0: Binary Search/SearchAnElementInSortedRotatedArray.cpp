/*
Problem Link  : https://www.youtube.com/watch?v=Id-DdcWb5AU&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=8&ab_channel=AdityaVerma
About Problem : Binary Search Implementation
                Aditya Verma Video
Tags          : 
Notes         :
 Finding minimum element in a rotated sorted array:
                minimum element of this kind of array is smaller than both of their components
                if mid is not that kind, compare with start and end, ans go to the unsorted part
     
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
    while (low < high) { //No Equal Sign Needed
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

//Modified binary Search to find the index of minimum elemnent in a sorted and rotated array
int BSMinEleSortRotate(int arr[], int N){
    int low = 0,high = N-1, mid;
    while(low<=high){ //Equal Sign is a must or else false result!
        //printarray(arr,low,high);
        mid = (high+low)/2;
        if(arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1]) return mid;
        if(arr[mid]>arr[low])low=mid+1;
        else if( arr[mid]<arr[high]) high = mid-1;
    }
    return -1;
}

int findanelementinsortedrotatedarray(int arr[], int N,int x){
    int minindex = BSMinEleSortRotate(arr,N);
    if(arr[minindex]==x) return minindex;
    return BinarySearchBounded(arr,0,minindex-1,x)+BinarySearchBounded(arr,minindex,N-1,x)+1;
}
void Solution(){
    int arr[] = {10,13, 16,17,18,19,2};
    int N= sizeof(arr)/sizeof(arr[0]);
    cout<<findanelementinsortedrotatedarray(arr,N,17)<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}