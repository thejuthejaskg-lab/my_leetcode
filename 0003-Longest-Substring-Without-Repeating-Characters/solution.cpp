class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);  // last index of each character
        int maxLen = 0;
        int left = 0;                   // start of current window

        for (int right = 0; right < s.size(); right++) {
            unsigned char c = s[right];

            // If c was seen inside the current window, move left past it
            if (lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }

            lastSeen[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};