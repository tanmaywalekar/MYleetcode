class Solution {
    
public:
    //double dp[25][25][101];
    double rec(int i,int j,int k,int n,double p,vector<vector<vector<double>>> &dp)
    {
        
        if(i>=n||j>=n||i<0||j<0)
            return 0;
        if(k==0)
            return 1;
        if(dp[i][j][k]!=-1.0)
            return dp[i][j][k];
            
        double ans=0;
            ans+=((1.0)/(8.0))*rec(i+2,j+1,k-1,n,p,dp);
            ans+=((1.0)/(8.0))*rec(i-2,j+1,k-1,n,p,dp);
            ans+=((1.0)/(8.0))*rec(i+2,j-1,k-1,n,p,dp);
            ans+=((1.0)/(8.0))*rec(i-2,j-1,k-1,n,p,dp);
            ans+=((1.0)/(8.0))*rec(i+1,j+2,k-1,n,p,dp);
            ans+=((1.0)/(8.0))*rec(i+1,j-2,k-1,n,p,dp);
            ans+=((1.0)/(8.0))*rec(i-1,j+2,k-1,n,p,dp);
            ans+=((1.0)/(8.0))*rec(i-1,j-2,k-1,n,p,dp);
        return dp[i][j][k]=ans*p;
        
        
        
        
            
    }
    double knightProbability(int n, int k, int r, int c) {
       vector<vector<vector<double>>> dp(n, vector<vector<double> >(n, vector<double>(k+1,-1)));
        return rec(r,c,k,n,1,dp);
    }
};