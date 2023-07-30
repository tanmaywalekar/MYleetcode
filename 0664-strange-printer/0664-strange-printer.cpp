class Solution {
public:
    int dp[102][102];
    int rec(int i,int j,string &s)
    {
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int mx=rec(i,k,s)+rec(k+1,j,s);
            if(s[i]==s[k+1])
                mx=mx-1;
            ans=min(ans,mx);
        }
        return dp[i][j]=ans;
    }
    int strangePrinter(string s) {
       memset(dp,-1,sizeof(dp));
        return rec(0,s.size()-1,s);
    }
};