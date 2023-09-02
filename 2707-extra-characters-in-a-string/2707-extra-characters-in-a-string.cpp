class Solution {
public:
    int minExtraChar(string st, vector<string>& d) {
        unordered_set<string> s;
    for (auto& i : d) {
        s.insert(i);
    }
    
    int n = st.size();
    int dp[51][51];
    
    // Initialize dp table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    
    // Base case: single characters are already present in the dictionary
    for (int i = 0; i < n; i++) {
        if (s.find(string(1, st[i])) != s.end()) {
            dp[i][i] = 0;
        } else {
            dp[i][i] = 1;
        }
    }
    
    // Fill in the dp table
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = len; // Initialize to worst case
            
            // Check if the entire substring is in the dictionary
            if (s.find(st.substr(i, len)) != s.end()) {
                dp[i][j] = 0;
                continue;
            }
            
            // Try to split the substring and minimize the result
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    
    return dp[0][n - 1];
        
    }
};