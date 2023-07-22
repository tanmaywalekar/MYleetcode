class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nxts(n,n),prvs(n,-1);
        stack<int> f,s;
        for(int i=n-1;i>=0;i--)
        {
            while(f.size())
            {
                if(heights[f.top()]>=heights[i])
                    f.pop();
                else
                    break;
            }
            if(f.size())
                nxts[i]=f.top();
            f.push(i);
        }
        for(int i=0;i<n;i++)
        {
            while(s.size())
            {
                if(heights[s.top()]>=heights[i])
                    s.pop();
                else
                    break;
            }
            if(s.size())
                prvs[i]=s.top();
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=(prvs[i]+1);
            int y=nxts[i]-1;
            ans=max(heights[i]*(y-x+1),ans);
        }
        return ans;
        
    }
};