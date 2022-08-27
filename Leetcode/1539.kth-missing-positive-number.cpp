/*
Explanation

Assume the final result is x,
And there are m number not missing in the range of [1, x].
Binary search the m in range [0, A.size()].

If there are m number not missing,
that is A[0], A[1] .. A[m-1],
the number of missing under A[m] is A[m] - 1 - m.

If A[m] - 1 - m < k, m is too small, we update left = m.
If A[m] - 1 - m >= k, m is big enough, we update right = m.

Note that, we exit the while loop, l = r,
which equals to the number of missing number used.
So the Kth positive number will be l + k.


Complexity

Time O(logN)
Space O(1)
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int l=0, r=arr.size()-1;
        
        while(l<=r)
        {
            int mid= l + (r-l)/2;
            
            if( arr[mid] -1 - mid < k )
                l = mid+1;
            else
                r = mid-1;
        }
        
        return l+k;   
        
    }
};
