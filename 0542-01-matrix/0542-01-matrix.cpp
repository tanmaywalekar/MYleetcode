class Solution {
public:
    bool valid(int i, int j, int m, int n, vector<vector<int>> &g, vector<vector<int>> &vis)

  {
    if (i < 0 || j < 0 || i >= m || j >= n ||vis[i][j]==1)
      return false;
    return true;
  }
    void bfs(vector<vector<int>>& vis,vector<vector<int>>& g, queue<pair<int,int>> &q,vector<vector<int>>& dis)
    {
       int m = g.size();
    int n = g[0].size();
    int i, j;
    vector<pair<int, int>> v = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (!q.empty())
    {
      pair<int, int> p = q.front();
      q.pop();
     
      i = p.first;
      j = p.second;
      for (int z = 0; z < 4; z++)
      {
        int r = i + v[z].first;
        int s = j + v[z].second;
        if (valid(r, s, m, n, g, vis))
        {
          vis[r][s] =1;
          dis[r][s]=dis[i][j]+1; 
         
          //vis[r][s] = 1;
          q.push({r, s});
        }
      }
    }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]==0)
                {   q.push({i,j});
                    vis[i][j]=1;
                 dis[i][j]=0;
                }
            }
        }
        bfs(vis,g,q,dis);
        return dis;
    }
};