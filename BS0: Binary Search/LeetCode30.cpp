
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
 vector<int> avoidFlood(vector<int> &rains)
{
    vector<int> ans;
    unordered_map<int, int> fulldays;
    set<int> drydays;
    int len = rains.size();
    for (int i=0; i<len; i++)
    {
        if (rains[i]==0)
        {
            drydays.insert(rains[i]);
            ans.push_back(1);
            
        }
        else{
            if(fulldays.
    find(rains[i])!= fulldays.
    end()){
                auto it =drydays.lower_bound(fulldays[rains[i]]);
                if(it == drydays.end()) {return {};}
                ans[*it]=rains[i];
                drydays.erase(*it);
                
            }
            
                fulldays[
            rains[i]]=i;
                ans.push_back(-1);
            
        }
        
    }
    return ans;
}


class Solution {
public:
// https://leetcode.com/problems/avoid-flood-in-the-city/
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans; // Store the final answer here.
        int n = rains.size(); 
        unordered_map<int, int> fulllakes; // Lake number -> day on which it became full.
        set<int> drydays;     // Set of available days that can be used for drying a full lake.
        for (int i=0; i<n; i++) {  // For each day - 
            if (rains[i] == 0) {  // No rain on this day.
                drydays.insert(i); // This day can be used as a day to dry some lake.
                                   // We don't know which lake to prioritize for drying yet.
                ans.push_back(1);  // Any number would be ok. This will get overwritten eventually.
                                   // If it doesn't get overwritten, its totally ok to dry a lake
                                   // irrespective of whether it is full or empty.
            } 
            else { // Rained in rains[i]-th lake.
                int lake = rains[i]; 

                if (fulllakes.find(lake) != fulllakes.end()) { // If it is already full -
                    // We must dry this lake before it rains in this lake.
                    // So find a day in "drydays" to dry this lake. Obviously, that day must be
                    // a day that is after the day on which the lake was full.
                    // i.e. if the lake got full on 7th day, we must find a dry day that is 
                    // greater than 7.
                    auto it = drydays.lower_bound(fulllakes[lake]);
                    if (it == drydays.end()) { // If there is no available dry day to dry the lake,
                                               // flooding is inevitable.
                        return {}; // Sorry, couldn't stop flooding.
                    }
                    int dryday = *it; // Great, we found a day which we can use to dry this lake.
                    ans[dryday] = lake; // Overwrite the "1" and dry "lake"-th lake instead.
                    drydays.erase(dryday); // We dried "lake"-th lake on "dryday", and we can't use
                                           // the same day to dry any other lake, so remove the day
                                           // from the set of available drydays.
                }
                
                fulllakes[lake] = i; // Update that the "lake" became full on "i"-th day.
                ans.push_back(-1); // As the problem statement expects.
            }
        }
        return ans; // Congratualtions, you avoided flooding.
    }
    //https://leetcode.com/problems/ugly-number-iii/discuss/387539/cpp-Binary-Search-with-picture-and-Binary-Search-Template
    int nthUglyNumber(int k, int A, int B, int C) {
        int lo = 1, hi = 2 * (int) 1e9;
        long a = long(A), b = long(B), c = long(C);
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            int cnt = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(cnt < k) 
                lo = mid + 1;
            else
			   //the condition: F(N) >= k
                hi = mid;
        }
        return lo;
    }
   // https://leetcode.com/problems/koko-eating-bananas/submissions/
        int solutionformid(vector<int>&piles,int mid){
 int ans=0;
        for(int p: piles){
            ans+=(p+mid-1)/mid;
            //substitute ceil
            
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
            int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2;
            if(solutionformid(piles,m) > h)
                l = m + 1;
            else
                r = m;
        }
        return l;
        
    }
};
int gcd(int a, int b){
    if (b==0) return a;
    if(a>=b) return(b,a%b); else return (a,b%a);
}
int nthUglyNumber( int k, int A, int B, int C){
    int lo=1, hi= 2*(int) 1e9;
    long a = long(A), b= long(B), c=long(C);
    long ab= (a*b)/__gcd(a,b);
    long bc = (b*c)/__gcd(b,c);
    long ca = (a*c)/__gcd(c,a);
    long abc = (a*bc)/__gcd(a,bc);
    while(lo<hi){
        int mid = lo +(hi-lo)/2;
        int count = mid/a + mid/b+ mid/c-mid/ab- mid/bc - mid/ca + mid/abc;
        if (count<k) lo =mid+1;
        else hi=mid;
    }
    return lo;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> any = {1, 2, 0, 0, 2, 1};
    vector<int> ans;
    //Solution a ;
    //ans =a.
    ans = avoidFlood(any);
     //= avoidFlood(any);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}