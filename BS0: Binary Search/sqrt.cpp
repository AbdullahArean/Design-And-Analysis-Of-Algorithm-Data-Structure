/*
Problem Link  :
About Problem :
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
#define ll long long int 

double sqrtbinarysearch(ll n){
    double low=0, high=n, mid;
    while((high-low)>1e-9){//Precsion
    mid=(high+low)/2;
    if(mid*mid>n) high = mid;
    else low= mid;
    }
    return low;
}
double nthsqrtbinarysearch(ll n){
    double low=0, high=n, mid;
    while((high-low)>1e-9){//Precsion
    mid=(high+low)/2;
    if(mid*mid*mid>n) high = mid;//Multiply n times
    else low= mid;
    }
    return low;
}
void Solution(){
	printf("%.9lf",nthsqrtbinarysearch(456));
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}