class Solution {
public:
    unordered_set<string>s;
    int dp[51][51];
    int rec(int i,int j,string &z)
    {
        if(s.find(z.substr(i,j-i+1))!=s.end())
            return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=z.length();
        for(int k=i;k<j;k++)
        {
            int b=0;
            if(dp[i][k]!=-1)
                b+=dp[i][k];
            else
                b+=rec(i,k,z);
            
             if(dp[k+1][j]!=-1)
                b+=dp[k+1][j];
            else
                b+=rec(k+1,j,z);
              
            ans=min(ans,b);
            
        }
        return dp[i][j]= ans;
    }
    int minExtraChar(string st, vector<string>& d) {
        for(auto &i:d)
        {
            s.insert(i);
        }
        memset(dp,-1,sizeof(dp));
        return rec(0,st.size()-1,st);
    }
};