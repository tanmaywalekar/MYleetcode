class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int h=nums.size()-1;
        int l=0;
        int x=0;
        int y=h;
        while(h>=l)
        {
            int m=l+(h-l)/2;
            if(nums[m]>=target)
            {
                y=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        h=nums.size()-1;l=0;
        while(h>=l)
        {
            int m=l+(h-l)/2;
            if(nums[m]<=target)
            {
                x=m;
                l=m+1;
                
            }
            else
                h=m-1;
        }
        vector<int> ans;
        if(nums.size()!=0&&nums[x]==target)
        {
            ans.push_back(y);
            ans.push_back(x);
        }
        else
        {
           ans.push_back(-1);
            ans.push_back(-1); 
        }
        return ans;
    }
};