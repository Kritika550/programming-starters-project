class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> result;
        string s = to_string(n);
        int len = s.size();

        for (int i = 0; i < len; i++) {
            int digit = s[i] - '0';
            if (digit > 0) {
                int value = digit * pow(10, len - i - 1);
                result.push_back(value);
            }
        }

        return result;
    }

   
    vector<int> decimalRepresentationDP(int n) {
       
        vector<int> components;
        for (int k = 0; pow(10, k) <= n; k++) {
            int base = pow(10, k);
            for (int d = 1; d <= 9; d++) {
                int val = d * base;
                if (val <= n) components.push_back(val);
            }
        }

        vector<int> dp(n + 1, 1e9);
        vector<int> parent(n + 1, -1);
        dp[0] = 0;

        for (int x = 1; x <= n; x++) {
            for (int c : components) {
                if (c <= x && dp[x - c] + 1 < dp[x]) {
                    dp[x] = dp[x - c] + 1;
                    parent[x] = c;
                }
            }
        }

        vector<int> result;
        int cur = n;
        while (cur > 0) {
            result.push_back(parent[cur]);
            cur -= parent[cur];
        }

        
        sort(result.rbegin(), result.rend());
        return result;
    }
};
