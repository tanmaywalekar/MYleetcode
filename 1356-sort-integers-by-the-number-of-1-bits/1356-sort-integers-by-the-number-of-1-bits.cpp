class Solution {
public:
   static bool cmp(const int a,const int b)
    {
        if(__builtin_popcount(a)<__builtin_popcount(b))
            return true;
       else if(__builtin_popcount(a)==__builtin_popcount(b))
           return a<b;
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};