class Solution {
public:
    void dfs(int i, vector<int>& v,vector<int> g[])
    {
        v[i]=1;
        for(auto c:g[i])
        {
            if(v[c]==0)
            {
                dfs(c,v,g);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        
      int n=a.size();
        vector<int> g[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0 ; j<n; j++)
            {
                if(a[i][j])
                {
                    g[i].push_back(j);
                }
            }
        }
        int c=0;
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                c++;
                dfs(i,v,g);
            }
        }
        return c;
    }
};