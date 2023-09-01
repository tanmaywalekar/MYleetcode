class Solution {
public:
     vector<int> d{0,-1,0,1,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        
       vector<vector<int>> v(heights.size(),vector<int>(heights[0].size(),1e7));
        
        queue<pair<int,int>>q;
        v[0][0]=0;
        q.push({0,0});
        while(q.size())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                if(i+d[k]>=0&&i+d[k]<heights.size()&&j+d[k+1]>=0&&j+d[k+1]<heights[0].size())
                {
                    if(v[i+d[k]][j+d[k+1]]>max(v[i][j],abs(heights[i][j]-heights[i+d[k]][j+d[k+1]])))
                    {
                        v[i+d[k]][j+d[k+1]]=max(v[i][j],abs(heights[i][j]-heights[i+d[k]][j+d[k+1]]));
                    q.push({i+d[k],j+d[k+1]});
                    }
                }
            }
        }
        return v[heights.size()-1][heights[0].size()-1];
    }
};