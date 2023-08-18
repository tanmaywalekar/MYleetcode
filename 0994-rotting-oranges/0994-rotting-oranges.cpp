class Solution {
public:
    vector<int> l{0,1,0,-1,0};
    bool check(int i,int j,vector<vector<int>>& g)
    {
        if(i>=0&&j>=0&&i<g.size()&&j<g[0].size()&&g[i][j]==1)
           return true;
           return false;
    }
    int bfs( queue<pair<int,int>> &q,vector<vector<int>>& g)
    {
        
        
        int d=0;
        while(q.size())
        {  
            int s=q.size();
            while(s--){
            int x=q.front().first;
            int y=q.front().second;
              //  cout<<x<<","<<y<<" ";
                
            q.pop();
                for(int k=0;k<4;k++)
                {
                    if(check(x+l[k],y+l[k+1],g))
                    { g[x+l[k]][y+l[k+1]]=0;
                        q.push({x+l[k],y+l[k+1]});
                    }
                }
                
            }
          //  cout<<endl;
            d++;
            
        }
        return d;
    }
    int orangesRotting(vector<vector<int>>& g) {
        
     
        queue<pair<int,int>> q;
        
       // vector<vector<int>> v(g.size(),vector<int>(g[0].size(),0));
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
                if(g[i][j]==2)
                { g[i][j]==0;
                    q.push({i,j});
                }
            }
        }
        
        int ans= bfs(q,g);
        //cout<<ans;
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
                if(g[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return max(ans-1,0);;
    }
};