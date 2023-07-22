class Solution {
public:
    stack<pair<int, int>> s1, s2;
    int mim()
    {
        if (s1.empty() || s2.empty()) 
   return s1.empty() ? s2.top().second : s1.top().second;
else
   return  max(s1.top().second, s2.top().second);
        
    }
    void add(int new_element)
    {
        int minimum = s1.empty() ? new_element : max(new_element, s1.top().second);
s1.push({new_element, minimum});
    }
    void remove()
    {
        if (s2.empty()) {
    while (!s1.empty()) {
        int element = s1.top().first;
        s1.pop();
        int minimum = s2.empty() ? element : max(element, s2.top().second);
        s2.push({element, minimum});
    }
}
int remove_element = s2.top().first;
s2.pop();
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         int n=nums.size();
        for(int i=0;i<k;i++)
        {
            add(nums[i]);
        }
        vector<int> ans;
        ans.push_back(mim());
        for(int i=k;i<n;i++)
        {  
            remove();
            add(nums[i]);
            ans.push_back(mim());
        }
        return ans;
       
    }
};