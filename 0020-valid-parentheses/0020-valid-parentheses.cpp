class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(auto i:s)
        {
            if(i=='('||i=='{'||i=='[')
            {
                t.push(i);
            }
            else
            {
                if(t.size()>0&&((t.top()=='('&&i==')')||(t.top()=='{'&&i=='}')||(t.top()=='['&&i==']')))
                {
                    t.pop();
                }
                else
                    return false;
            }
        }
        if(t.size())
            return false;
        return true;
            
    }
};