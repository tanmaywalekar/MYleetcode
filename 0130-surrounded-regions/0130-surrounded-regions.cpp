class Solution {
public:
    vector<int> l{0,-1,0,1,0};
    void dfs(int i,int j,vector<vector<char>>& b,vector<vector<char>>& g)
    {
        g[i][j]='O';
        for(int k=0;k<4;k++)
        {
            int a=i+l[k];
            int c=j+l[k+1];
            if(a>=0&&c>=0&&a<g.size()&&c<g[0].size()&&b[a][c]!='X'&&g[a][c]!='O')
            
                dfs(a,c,b,g);
            
        }
    }
    void solve(vector<vector<char>>& b) {
        vector<vector<char>>g(b.size(),vector<char>(b[0].size(),'X'));
        for(int i=0;i<b.size();i++)
        {
            if(b[i][0]=='O')
            {
                dfs(i,0,b,g);
            }
            if(b[i][g[0].size()-1]=='O')
                 dfs(i,g[0].size()-1,b,g);
        }
        for(int j=0;j<b[0].size();j++)
        {
            if(b[0][j]=='O')
            {
                dfs(0,j,b,g);
            }
            if(b[b.size()-1][j]=='O')
                 dfs(g.size()-1,j,b,g);
        }
        b=g;
    }
};