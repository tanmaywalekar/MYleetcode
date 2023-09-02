class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long>d(n,LONG_MAX);
         vector<long long>ans(n,0);
       long long m=1e9+7;
        vector<pair<long long,long long>> g[n];
        for(auto i:roads)
        {
            g[i[0]].push_back({i[1],i[2]});
            g[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
       d[0]=0;
        q.push({0,0});
        ans[0]=1;
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
                    ans[c.first]=ans[x]%m;
                }
                else if(c.second+w==d[c.first])
                {
                    ans[c.first]=(ans[c.first]%m+ans[x]%m)%m;
                }
            }
        }
        return ans[n-1];
    }
};