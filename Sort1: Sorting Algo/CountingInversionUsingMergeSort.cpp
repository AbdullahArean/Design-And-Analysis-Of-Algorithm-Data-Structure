/*
Problem Link  : 
About Problem : An awesome application of merge sort
Tags          : Merge sort inversion count 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a
long long int merge(int arr[], int start, int mid, int end)
{
    long long int inv=0;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int leftArr[len1], rightArr[len2];

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < len2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < len1 && j < len2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            inv+=len1-i;
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < len2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    return inv;
}
long long int mergeSort(int arr[], int start, int end)
{
    long long int inv =0;
    if (start < end)
    {

        int mid = start + (end - start) / 2;
        inv+=mergeSort(arr, start, mid);
        inv+=mergeSort(arr, mid + 1, end);
        inv+=merge(arr, start, mid, end);
    }
    return inv;
}

bool Solution(){
	int n;
	cin>>n;
    int arr[100];
    long long int localinv=0;
	for(int i=0 ; i<n; i++){
		scanf("%d",arr[i]);
        if(i>0 && arr[i-1]>arr[i]) localinv++; 
	}
    if(localinv==mergeSort(arr,0,n-1))return true;
    else return false;
	
	
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	Solution();
	return 0;
}