class Solution {
public:
    
    int uniquePaths(int m, int n) {
       
        vector<vector<int>> d(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        d[0][0]=1;
        q.push({0,0});
        //vector<vector<int>> ans(m,vector<int>(n,0));
        //ans[0][0]=1;
        while(q.size())
        {
            
            int i=q.front().first;
           int j= q.front().second;
            q.pop();
            
            if(i+1>=0&&j>=0&&i+1<m&&j<n)
            {
                if(d[i+1][j]==0)
                {
                    d[i+1][j]=d[i][j];
                    q.push({i+1,j});
                    //ans[i+1][j]=ans[i][j];
                }
                else if(d[i+1][j])
                {
                    d[i+1][j]+=d[i][j];
                }
            }
            if(i>=0&&j+1>=0&&i<m&&j+1<n)
            {
                if(d[i][j+1]==0)
                {
                    d[i][j+1]=d[i][j];
                    q.push({i,j+1});
                    //ans[i][j+1]=ans[i][j];
                }
                else if(d[i][j+1])
                {
                    d[i][j+1]+=d[i][j];
                }
            }
        }
        return d[m-1][n-1];
    }
};