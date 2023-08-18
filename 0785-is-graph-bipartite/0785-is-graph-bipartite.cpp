class Solution {
public:
    bool dfs(int i,int p,vector<vector<int>>& g,vector<int> &v,vector<int>&cr,int r)
    {
        v[i]=1;
        cr[i]=r;
        bool ans=false;
        for(auto c:g[i])
        {
            if(v[c]==0)
            {
                ans=ans|dfs(c,i,g,v,cr,r^1);
            }
            else
            {
                
                 if(c!=p){
                     if(cr[i]==cr[c])
                    return true;}
                
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& g) {
        vector<int>v(g.size(),0);
        vector<int>c(g.size(),-1);
        for(int i=0;i<g.size();i++)
        {
            if(v[i]==0)
            {
                if(dfs(i,-1,g,v,c,0))
                    return false;
            }
        }
        return true;
    }
};