class Solution {
public:
    double myPow(double x, long long p) {
         if(p==0)
             return 1;
        if(p==1)
            return x;
        if(p<0)
        {
            return 1.0/myPow(x,-p);
        }
        else
        {
        if(p%2==0)
        {
            return myPow(x*x,p/2);
        }
        else
        {
            return x* myPow(x*x,p/2);
        }
        }
        
    }
};