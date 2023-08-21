class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string x="";
        for(int i=0;i<s.size()/2;i++)
        { 
            x.push_back(s[i]);
            if(s.size()%(i+1)==0)
            {
                
                int z=0;
              
                string y="";
                while(1)
                {
                    y+=x;
                    z+=i+1;
                    if(z==s.size())
                        break;
                }
                if(y==s)
                { //cout<<y<<" "<<x<<" "<<z<<" "<<" "<<i+1;
                    return true;}
            }
        }
        return false;
    }
};