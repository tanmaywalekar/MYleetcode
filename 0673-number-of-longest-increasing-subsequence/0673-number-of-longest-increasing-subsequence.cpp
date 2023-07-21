class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
         int n=arr.size();
        vector<int> val(n,1);
       vector<int> hash(n,1);
       
            int mx=0;
        for(int i=0;i<n;i++)
        {
            for( int j = i-1 ; j >= 0; j-- )
            {
                if(arr[i]>arr[j])
                {
                    if(val[i]<val[j]+1)
                    {  
                        val[i]=val[j]+1;
                        
                        hash[i]=hash[j];
                        
                        
                        
                    }
                    else if(val[i]==val[j]+1)
                        hash[i]+=hash[j];
                }
                
            }
            mx=max(mx,val[i]);
        }
      int ans=0;
           for(int i=0;i<n;i++)
           {
               if(mx==val[i])
                   ans+=hash[i];
           }
        
        return ans;
    }
};