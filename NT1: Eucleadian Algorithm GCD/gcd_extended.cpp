#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);

}
//a x + b y = gcd(a,b); returns (x), (y) and (gcd of a,b)
vector<int> extended_gcd(int a, int b){
    if(b==0){
        return {1,0,a};
    }
    vector<int>result = extended_gcd(b, a%b);

    //after recursive call is over
    int smallx = result[0];
    int smally = result[1];
    int gcd = result[2];

    int x = smally;
    int y = smallx - (a/b)*smally;

    return {x,y,gcd}; 
}
int main(){
    int a=18, b=30;
    //cin>>a>>b;
    vector<int> result = extended_gcd(a,b);
    cout<<result[0]<<" and "<<result[1]<<" and "<<result[2]<<endl;
    return 0;

}
