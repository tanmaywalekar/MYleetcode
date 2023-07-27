class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int h=nums.size()-1;
        int l=0;
        int ans=-1;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(nums[m]==target)
            {
                return true;
            }
            else if(nums[l]==nums[m]&&nums[h]==nums[m])
            {
                l++;
                h--;
            }
            else if(nums[l]<=nums[m])
                
            {   if(target<=nums[m]&&target>=nums[l])
                h=m-1;
             else
                 l=m+1;
            }
            else
            {   if(target>=nums[m]&&target<=nums[h])
                l=m+1;
             else
                 h=m-1;
            }
        }
        return false;
    }
};