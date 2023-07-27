class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int h=nums.size()-1;
        int l=0;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            
            if(nums[l]<=nums[m])
            {
                ans=min(nums[l],ans);
                l=m+1;
            }
            else
            {
                ans=min(ans,nums[m]);
                h=m-1;
            }
        }
        return ans;
    }
};