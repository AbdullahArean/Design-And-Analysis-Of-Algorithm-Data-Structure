/*
Problem Link   : https://www.youtube.com/watch?v=W3-KgsCVH1U&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=9&ab_channel=AdityaVerma
About Problem  : Aditya Verma Video Lecture 9
Tags           : Binary Search
Notes          :
                1. Nearly Sorted Array : ith index might be in i+1th, ith index, or i-1th index
        
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
int BSUpperBoundBounded(int arr[], int start, int end, int value){
   
    int low = start,high = end, mid;
    while (low < high) {
        //printarray(arr,low,high);
        mid = low+ (high-low)/2;
        if(arr[mid]>value)  high = mid;
        else low= mid+1;
    }
    if(value>=arr[end]) low++; //To match built in functions
    return low;
}
int BSLowerBoundBounded(int arr[], int start, int end, int value){
   
    int low = start,high = end, mid;
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
    if(value>=arr[end]) low++; //To match built in functions
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
int BSMinimumElementSortedRotatedArray(int arr[], int N){
    //Modified binary Search to find the index of minimum elemnent in a sorted and rotated array
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
int BinarySearchInNearlySortedArray(int arr[], int start, int end, int value){
   //Find an element in nearly sorted array
    int low = start,high = end, mid;
    while(low<=high){ //Equal Sign is a must or else false result!
        mid = (high+low)/2;
        if(arr[mid]==value) return mid;
        else if(arr[mid+1]==value) return mid+1;
        else if(arr[mid-1]==value) return mid-1;
        else if(arr[mid]>value) high=mid-2;
        else if( arr[mid]<value) low = mid+2;
    }
    return -1;
}

void Solution(){
    int arr[] = {1,30,20,40,50,60,70};
    int N= sizeof(arr)/sizeof(arr[0]);
    
    cout<<BinarySearchInNearlySortedArray(arr,0,N-1,20)<<endl;
  
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}