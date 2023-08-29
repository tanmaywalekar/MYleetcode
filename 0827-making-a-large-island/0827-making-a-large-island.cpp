class Solution {
public:
    bool check(int i ,int j, vector<vector<int>>& g)
    {
        if(i>=0&&j>=0&&i<g.size()&&j<g[0].size())
            return true;
        return false;
    }
    pair<int,int> mns{-1,-1};
    vector<int> d{0,-1,0,1,0};
   int find(int i,vector<int> &v)
{
    while(1)
    {
        if(v[i]<0)
        {
            break;
        }
        i=v[i];
    }
    return i;
}
void uni(int i,int j,vector<int>&v)
{
    int x=find(i,v);
    int y=find(j,v);
    if(x==y)
    return;
    if(v[x]<v[y])
    {
        v[x]+=v[y];
        v[y]=x;
    }
    else
    {
        v[y]+=v[x];
        v[x]=y;
    }
}
    int largestIsland(vector<vector<int>>& g) {
       
       // vector<vector<pair<int,int>>> v(g.size(),vector<pair<int,int>>(g[0].size(),{-1,-1}));
            vector<int> v(g.size()*g[0].size(),-1);
        int m=g[0].size();
        int n=g.size();
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {   if(g[i][j])
                for(int k=0;k<4;k++)
                {   
                    if(check(i+d[k],j+d[k+1],g))
                    {
                        if(g[i+d[k]][j+d[k+1]])
                        {   if(find(i*m+j,v)!=find((i+d[k])*m+j+d[k+1],v))
                        {uni(i*m+j,(i+d[k])*m+j+d[k+1],v);}
                            
                        }
                    }
                }
               else
               {
                   v[i*m+j]=1e9;
               }
            }
        }
        int ans=0;
        for(auto i:v)
        {
            if(i<0)
                ans=max(ans,-i);
        }
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
                // cout<<"{"<<v[i][j].first<<","<<v[i][j].second<<"}"<<" ";
                int c=0;
                if(g[i][j]==0)
                {c++;
                 set<int>s;
                    for(int k=0;k<4;k++)
                    {   
                        if(check(i+d[k],j+d[k+1],g))
                        {
                            if(g[i+d[k]][j+d[k+1]])
                            {   int x=find((i+d[k])*m+j+d[k+1],v);
                             s.insert(x);

                            }
                        }
                    }
                 for(auto x:s)
                 {
                     c+=(-v[x]);
                 }
                }
                ans=max(ans,c);
            }
            // cout<<endl;
        }
        return ans;
       
        
    }
};