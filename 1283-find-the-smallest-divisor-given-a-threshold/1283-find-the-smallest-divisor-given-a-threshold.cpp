class Solution {
public:
    int f(vector<int>& arr, int d)
    {
        int ans=0;
        for(auto i:arr)
        {
            ans+=(i/d)+(i%d!=0);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
        
        int l=1;
       int h=0;
        for(auto i:arr)
            h=max(h,i)+10;
        int ans=INT_MAX;
         while(l<=h)
        {
            int mid=l+(h-l)/2;
             int sum=f(arr,mid);
             if(sum<=threshold)
             {
                 ans=min(ans,mid);
                 h=mid-1;
             }
             else
                 l=mid+1;
         }
        return ans;
    }
};