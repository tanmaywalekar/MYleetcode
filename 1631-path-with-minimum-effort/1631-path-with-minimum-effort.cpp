class Solution {
public:
    vector<int> d{0,-1,0,1,0};
    bool check(int x,vector<vector<int>>& h)
    {
        vector<vector<int>> v(h.size(),vector<int>(h[0].size(),0));
        queue<pair<int,int>>q;
        v[0][0]=1;
        q.push({0,0});
        while(q.size())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                if(i+d[k]>=0&&i+d[k]<h.size()&&j+d[k+1]>=0&&j+d[k+1]<h[0].size()&&v[i+d[k]][j+d[k+1]]==0&&(abs(h[i][j]-h[i+d[k]][j+d[k+1]])<=x))
                {
                    v[i+d[k]][j+d[k+1]]=1;
                    q.push({i+d[k],j+d[k+1]});
                }
            }
        }
        if(v[h.size()-1][h[0].size()-1])
            return true;
        else
            return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
         vector<vector<int>> v(heights.size(),vector<int>(heights[0].size(),0));
        queue<pair<int,int>>q;
        v[0][0]=1;
        q.push({0,0});
        int h=0;
        while(q.size())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                if(i+d[k]>=0&&i+d[k]<heights.size()&&j+d[k+1]>=0&&j+d[k+1]<heights[0].size()&&v[i+d[k]][j+d[k+1]]==0)
                {
                    v[i+d[k]][j+d[k+1]]=1;
                    q.push({i+d[k],j+d[k+1]});
                    h=max(h,abs(heights[i][j]-heights[i+d[k]][j+d[k+1]]));
                }
            }
        }
        
        int l=0;
       
        int ans=h;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(check(m,heights))
            {
                ans=min(ans,m);
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};