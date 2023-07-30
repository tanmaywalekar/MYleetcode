class Solution {
public:
    //const int k=1002;
   int dp[1002][1002];
//     int lcs (string &a, string &b,int i,int j)
//     {if(dp[i][j]!=-1)
//             return dp[i][j];
//         if(i==0||j==0)
//         {
//             return dp[i][j]= 0;
//         }
        
//         if(a[i-1]==b[j-1])
//         {
//             return dp[i][j]=1+lcs(a,b,i-1,j-1);
//         }
//         else
//         {
//             dp[i][j]= max(lcs(a,b,i-1,j),lcs(a,b,i,j-1));
//             return dp[i][j];
//         }
//     }
    int longestCommonSubsequence(string a, string b) {
       // vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
        memset(dp,-1,sizeof(dp));
       for(int i=0;i<1002;i++)
       {
           dp[i][0]=0;
           dp[0][i]=0;
       }
        for(int i=1;i<a.size()+1;i++)
        {
            for(int j=1;j<b.size()+1;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[a.size()][b.size()];
        
    }
};