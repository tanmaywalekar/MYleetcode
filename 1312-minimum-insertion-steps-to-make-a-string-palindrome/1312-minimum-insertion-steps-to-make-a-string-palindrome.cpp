class Solution {
public:
     int dp[1002][1002];
    int rec(int i,int j,string & a,string &b)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
     if(i==a.size()&&j==b.size())
         return dp[i][j]=0;
        if(i==a.size())
            return dp[i][j]=b.size()-j;
        if(j==b.size())
            return dp[i][j]= a.size()-i;
        if(a[i]==b[j])
        {
            return dp[i][j]=rec(i+1,j+1,a,b);
        }
        else
        {
            return dp[i][j]=1+min(rec(i,j+1,a,b),rec(i+1,j,a,b));
        }
        return 0;
    }
    int minInsertions(string a) {
         string b=a;
         reverse(b.begin(),b.end());
        
        memset(dp,-1,sizeof(dp));
       // for(int i=0;i<1002;i++)
       // {
       //     dp[i][0]=0;
       //     dp[0][i]=0;
       // }
       //  for(int i=1;i<a.size()+1;i++)
       //  {
       //      for(int j=1;j<b.size()+1;j++)
       //      {
       //          if(a[i-1]==b[j-1])
       //              dp[i][j]=1+dp[i-1][j-1];
       //          else
       //          {
       //              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
       //          }
       //      }
       //  }
       //  int l= dp[a.size()][b.size()];
        return rec(0,0,a,b)/2;
    }
};