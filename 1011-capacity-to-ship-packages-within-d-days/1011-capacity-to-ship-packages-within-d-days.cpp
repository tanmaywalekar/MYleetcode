class Solution {
public:
    int f(vector<int>& w, int m)
    {
        int d=1;
        int c=w[0];
        int b=0;
        int i=1;
       while(i<w.size()&&c<=m)
       {
           c+=w[i];
           if(c>m)
           {
               d++;
               c=w[i];
           }
           i++;
       }
        return d;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int l=INT_MIN;
        int h=0;
        int ans=INT_MAX;
        for(auto i:w)
        {h+=i;
         l=max(l,i);}
      
        while(l<=h)
        {
            int m=l+(h-l)/2;
            int x=f(w,m);
            if(x<=days)
            {   //cout<<x<<","<<m<<"     ";
                ans=min(m,ans);
                h=m-1;
                
            }
            else 
                l=m+1;
            
        }
        return ans;
    }
};