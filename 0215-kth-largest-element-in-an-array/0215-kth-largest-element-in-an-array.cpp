class Solution {
public:
    int p=-1;
    int ans=-1e7;
    int findpos(int left,int right,vector<int>& nums)
    {
        int i=left;
        int j=right;
        while(i<j)
        {
            while(i<=right-1&&nums[i]<=nums[left])
                i++;
            while(j>=left+1&&nums[j]>nums[left])
                j--;
            if(i<j)
                swap(nums[i],nums[j]);
        }
        if(j==p)
        {  ans=nums[left];return j;}
        swap(nums[left],nums[j]);
        return j;
    }
    void rec(int left,int right,vector<int>& nums)
    { 
        
        if(left>right||ans!=-1e7)
            return;
        int i=findpos(left,right,nums);
        if(ans!=-1e7)
            return;
        if(p<i)
        rec(left,i-1,nums);
        else
        rec(i+1,right,nums);
    }
    int findKthLargest(vector<int>& nums, int k) {
         p=nums.size()-k;
        rec(0,nums.size()-1,nums);
      
        return ans;
    }
};