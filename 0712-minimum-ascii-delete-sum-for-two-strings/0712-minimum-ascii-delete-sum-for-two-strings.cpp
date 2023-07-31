class Solution {
public:
    int dp[1001][1001];
    int rec(int i,int j,string &a, string &b)
    {
        if(i==a.size()&&j==b.size())
            return 0;
        if(i==a.size())
        {
            return b[j]+rec(i,j+1,a,b);
        }
         if(j==b.size())
        {
            return a[i]+rec(i+1,j,a,b);
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            return rec(i+1,j+1,a,b);
        return dp[i][j]=min(b[j]+rec(i,j+1,a,b),a[i]+rec(i+1,j,a,b));
    }
    int minimumDeleteSum(string &a, string &b) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,a,b);
    }
};