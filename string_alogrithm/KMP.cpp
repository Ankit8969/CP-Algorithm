class Solution {
public:
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }

    int strStr(string haystack, string needle) {
        vector<int> ans = prefix_function(needle + "#" + haystack);
        for(int i=0;i<ans.size();i++){
            if (ans[i] == needle.length())
                return i - 2*needle.length();
        }

        return -1;
    }
};
