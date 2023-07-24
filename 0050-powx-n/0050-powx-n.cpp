class Solution {
public:
    double myPow(double x, int p) {
        long long n=p;
        if(x==1)
            return 1;
       if(n==0)
           return 1;
       if(n<0)
       { double ans=1;
           n=-n;
           while(n!=0)
           { 
               if(n%2==0)
               {
                   n=n/2;
                   x=x*x;
               }
               else
               {ans= x*ans;
               n--;}
           }
        return 1/ans;
       }
        else   
       { double ans=1;
            while(n!=0){
           if(n%2==0)
               {
                   n=n/2;
                  x=x*x;
               }
               else
               {ans= x*ans;
               n--;}
            }
        return ans;
       }
        
        
    }
};