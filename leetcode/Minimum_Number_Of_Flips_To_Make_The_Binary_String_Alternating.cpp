// ────────────────────────────────────────────────────────────
// Problem : Minimum Number Of Flips To Make The Binary String Alternating
// Platform: LeetCode
// URL     : https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/submissions/1940505400/?envType=daily-question&envId=2026-03-07
// Language: cpp
// Date    : 3/7/2026, 12:01:10 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(n)
// Notes           : Bit manipulation
// ────────────────────────────────────────────────────────────

1class Solution {
2public:
3    int minFlips(auto& s) {
4        int n = s.length();
5        int res = n;
6        int op[2] = {0, 0};
7
8        for (int i = 0; i < n; i++)
9            op[(s[i] ^ i) & 1]++;
10
11        for (int i = 0; i < n; i++) {
12            op[(s[i] ^ i) & 1]--;
13            op[(s[i] ^ (n + i)) & 1]++;
14            res = min(res, min(op[0], op[1]));
15        }
16
17        return res;
18    }
19};