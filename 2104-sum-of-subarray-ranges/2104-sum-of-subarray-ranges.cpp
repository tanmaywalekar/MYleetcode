class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ng(n,n),pg(n,-1),ns(n,n),ps(n,-1);
        stack<int> a,b,c,d;
        for(int i=n-1;i>=0;i--)
        {
            while(a.size())
            {
                if(nums[a.top()]<nums[i])
                    a.pop();
                else
                    break;
            }
            if(a.size())
            {
                ng[i]=a.top();
            }
            a.push(i);
            
            
            
            while(c.size())
            {
                if(nums[c.top()]>nums[i])
                    c.pop();
                else
                    break;
            }
            if(c.size())
            {
                ns[i]=c.top();
            }
            c.push(i);
        }
        for(int i=0;i<n;i++)
        {
            while(b.size())
            {
                if(nums[b.top()]<=nums[i])
                    b.pop();
                else
                    break;
            }
            if(b.size())
            {
                pg[i]=b.top();
            }
            b.push(i);
            
            
            
            while(d.size())
            {
                if(nums[d.top()]>=nums[i])
                    d.pop();
                else
                    break;
            }
            if(d.size())
            {
                ps[i]=d.top();
            }
            d.push(i);
        }
        long long ans=0;
        for(long long i=0;i<n;i++)
        {
            long long z=((ng[i]-i*1ll)*(pg[i]-i*1ll)-(i*1ll-ns[i])*(i*1ll-ps[i]));
            ans+=z*nums[i];
        }
        return -(ans);
        
    }
};