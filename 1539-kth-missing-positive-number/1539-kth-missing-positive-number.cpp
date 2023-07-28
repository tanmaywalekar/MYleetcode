class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v(arr.size(),0);
        
        int l=0;
        int h=arr.size()-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            int miss=arr[m]-(m+1);
            if(miss<k)
                l=m+1;
            else
                h=m-1;
        }
        return h+k+1;
        
    }
};