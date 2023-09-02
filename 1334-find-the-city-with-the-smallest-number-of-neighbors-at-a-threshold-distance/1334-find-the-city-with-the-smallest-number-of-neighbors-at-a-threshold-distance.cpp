class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        
        vector<pair<int,int>> g[n];
        for(auto i:edges)
        {
            g[i[0]].push_back({i[1],i[2]});
              g[i[1]].push_back({i[0],i[2]});
        }
        int ans=-1;
        int cnt=1e9;
        for(int i=0;i<n;i++)
        {
            vector<int> d(n,1e9);
            priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
            q.push({0,i});
            d[i]=0;
             while(q.size())
        {
            long long x=q.top().second;
            long long w=q.top().first;
            q.pop();
            for(auto c:g[x])
            {
                if((c.second+w)<d[c.first])
                {
                    d[c.first]=(c.second+w);
                    q.push({d[c.first],c.first});
                    
                }
                
            }
        }
            int c=0;
            for(auto j:d)
            {
                if(j<=dt)
                {
                    c++;
                }
            }
            if(c<cnt)
            {
                cnt=c;
                ans=i;
            }
            else if(c==cnt)
            {
                ans=max(ans,i);
            }
        }
        return ans;
    }
};