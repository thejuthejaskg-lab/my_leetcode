class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;

        // Expands outward from (l, r) while the characters match
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // After the loop, the palindrome spans (l+1) to (r-1)
            int len = r - l - 1;
            if (len > maxLen) {
                maxLen = len;
                start = l + 1;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);       // odd-length palindromes, center at i
            expand(i, i + 1);   // even-length palindromes, center between i and i+1
        }

        return s.substr(start, maxLen);
    }
};