class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& g) {
        int ans=0;
        vector<int>roads[n];
        for(int i=0;i<g.size();i++)
        {
            int x=g[i][0];
            int y=g[i][1];
            roads[x].push_back(y);
             roads[y].push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    int x=roads[i].size()+roads[j].size();
                    for(auto k:roads[i])
                    {
                        if(k==j)
                        {
                            x--;
                            break;
                        }
                        
                    }
                    ans=max(ans,x);
                }
            }
            
        }
        return ans;
    }
};