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
