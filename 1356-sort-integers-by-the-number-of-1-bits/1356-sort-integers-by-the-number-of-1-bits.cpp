class Solution {
public:
    static int popcount(int x)
    {
        int c=0;
        while(x)
        {
            if(x%2==1)
                c++;
            x=x/2;
        }
        return c;
    }
   static bool cmp(const int a,const int b)
    {
        if(popcount(a)<popcount(b))
            return true;
       else if(popcount(a)==popcount(b))
           return a<b;
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};