class Solution {
public:
    int find(int x,vector<int> &p)
    {
        while(1)
        {
            if(p[x]<0)
                return x;
            else
            {
                x=p[x];
            }
        }class Solution {
public:
    int find(int x,vector<int> &p)
    {
        while(1)
        {
            if(p[x]<0)
                return x;
            else
            {
                x=p[x];
            }
        }
    }
    void uni(int x,int y,vector<int> &p)
    {
        x=find(x,p);
        y=find(y,p);
        if(x==y)
            return;
        else
        {
            
            if(p[x]<p[y])
            {
                p[x]+=p[y];
                p[y]=x;
            }
            else
            {
                p[y]+=p[x];
                p[x]=y;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& m) {
        int n=m.size();
        vector<int> v(n,-1);
        
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        if(m[i][j])
                            uni(i,j,v);
                    }
                }
            }
        int ans=0;
        for(auto i:v)
            if(i<0)
             ans++;
        return ans+1-1;
    }
};
    }
    void uni(int x,int y,vector<int> &p)
    {
        x=find(x,p);
        y=find(y,p);
        if(x==y)
            return;
        else
        {
            
            if(p[x]<p[y])
            {
                p[x]+=p[y];
                p[y]=x;
            }
            else
            {
                p[y]+=p[x];
                p[x]=y;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& m) {
        int n=m.size();
        vector<int> v(n,-1);
        
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        if(m[i][j])
                            uni(i,j,v);
                    }
                }
            }
        int ans=0;
        for(auto i:v)
            if(i<0)
             ans++;
        return ans;
    }
};