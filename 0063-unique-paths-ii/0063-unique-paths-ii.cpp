class Solution {
public:
    int dp[102][102];
    int x,y;
    
    int rec(int m,int n,vector<vector<int>>& g)
    {
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(m==1&&n==1&&g[m-1][n-1]==0)
            return dp[m][n]=1;
        int ans=0;
        if(m-1>0&&n>0&&m<=x&&n<=y&&g[m-1][n-1]==0)
        {
            ans+= rec(m-1,n,g);
        }
        if(m>0&&n-1>0&&m<=x&&n<=y&&g[m-1][n-1]==0)
        {
            ans+= rec(m,n-1,g);
        }
        return dp[m][n]=ans;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        x=g.size();
        y=g[0].size();
         memset(dp,-1,sizeof(dp));
        return rec(x,y,g);
    }
};