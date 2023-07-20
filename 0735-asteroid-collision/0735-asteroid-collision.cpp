class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>s;
        for(int i=a.size()-1;i>=0;i--)
        {
            while(s.size())
            {
                if(s.top()*a[i]<0&&s.top()<0)
                {
                    if(abs(s.top())<abs(a[i]))
                        s.pop();
                    else
                        break;
                   
                    
                }
                else 
                    break;
            }
            if(s.size()==0)
            s.push(a[i]);
            else
            {   
                if(s.top()*a[i]>0||s.top()>0)
                    s.push(a[i]);
                 else
                 {
                     if(s.size()&&s.top()<0&&(abs(s.top())==abs(a[i])))
                         s.pop();
                 }
            }
        }
        vector<int> ans;
      while(s.size())
      {
         ans.push_back(s.top());
          s.pop();
      }
        return ans;
    }
};