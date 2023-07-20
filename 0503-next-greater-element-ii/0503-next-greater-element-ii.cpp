class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> ans(nums.size(),-1);
        stack<int> s;
        for(int i=2*nums.size()-1;i>=0;i--)
        {
            //ans[nums[i%nums.size()]]
            while(s.size())
            {      
                if(s.top()<=nums[i%nums.size()])
                {
                    s.pop();
                }
                else
                {
                 break;
                }
            }
            if(s.size())
                ans[i%nums.size()]=s.top();
            s.push(nums[i%nums.size()]);
        }
        return ans;
    }
};