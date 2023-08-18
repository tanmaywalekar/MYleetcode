class Solution {
public:
    vector<int> l{0,-1,0,1,0};
    void dfs(int i,int j,vector<vector<int>>& g)
    {
        g[i][j]=0;
        for(int k=0;k<4;k++)
        {
            int x=i+l[k];
            int y=j+l[k+1];
            if(x>=0&&y>=0&&x<g.size()&&y<g[0].size()&&g[x][y])
            {
                dfs(x,y,g);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& g) {
        
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
                if(g[i][j])
                {
                    
                    
                        if(i==0||j==0||i==g.size()-1||j==g[0].size()-1)
                        {
                            dfs(i,j,g);
                        }
                    
                }
            }
        }
        int c=0;
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
                if(g[i][j])
                    c++;
            }
        }
        return c;
        
    }
};