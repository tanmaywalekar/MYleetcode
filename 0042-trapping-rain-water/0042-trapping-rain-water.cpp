class Solution {
public:
    int trap(vector<int>& h) {
        
        vector<int> p,s;
        int m=0;
        for(int i=0;i<h.size();i++)
        {
            m=max(m,h[i]);
            p.push_back(m);
        }
        m=0;
        
        for(int i =h.size()-1 ; i>=0; i--)
        {
            m=max(m,h[i]);
            s.push_back(m);
        }
        reverse(s.begin(),s.end());
        int ans=0;
         for(int i=0;i<h.size();i++)
         {
             ans+=min(p[i],s[i])-h[i];
         }
        return ans;
    }
};