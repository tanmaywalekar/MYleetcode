class Solution {
public:
     map<pair<double , double> , double> mp;
    double rec(int a,int b)
    {
        if(a<=0&&b<=0)
            return 0.5;
        if(a<=0)
            return 1.0;
        if(b<=0)
            return 0.0;
         if(mp.find({a , b}) != mp.end()) return mp[{a , b}];
        return mp[{a , b}] =0.25*(rec(a-100,b)+rec(a-75,b-25)+rec(a-50,b-50)+rec(a-25,b-75));
    }
    double soupServings(int n) {
        if(n >= 4800) return 1;
        return rec(n,n);
    }
};