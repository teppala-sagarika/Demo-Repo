// ────────────────────────────────────────────────────────────
// Problem : Minimum Number of Flips to Make the Binary String Alternating
// Platform: LeetCode
// URL     : https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/submissions/1940655463/?envType=daily-question&envId=2026-03-07
// Language: cpp
// Date    : 3/7/2026, 3:11:03 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(n)
// Notes           : bit manipulation
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int minFlips(auto& s) {
        int n = s.length();
        int res = n;
        int op[2] = {0, 0};

        for (int i = 0; i < n; i++)
            op[(s[i] ^ i) & 1]++;

        for (int i = 0; i < n; i++) {
            op[(s[i] ^ i) & 1]--;
            op[(s[i] ^ (n + i)) & 1]++;
            res = min(res, min(op[0], op[1]));
        }

        return res;
    }
};