class Solution {
public:
    bool f(vector<int>& arr, int m, int k,int mid)
    {
       // vector<int>v(arr.size(),0);
        int c=0;
        int z=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=mid)
                c++;
            else
            { z+=c/k;
                c=0;}
                
        }
  
        z+=c/k;
        if(z>=m)
            return true;
        else
            return false;
    }
    int minDays(vector<int>& arr, int m, int k) {
        
        int l=1;
        int h=0;
        for(auto i:arr)
            h=max(h,i);
        int ans=INT_MAX;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(f(arr,m,k,mid))
            {   
                ans=min(ans,mid);
                h=mid-1;
            }
            else
                l=mid+1;
        }
        if(ans!=INT_MAX)
        return ans;
        else
            return -1;
    }
};