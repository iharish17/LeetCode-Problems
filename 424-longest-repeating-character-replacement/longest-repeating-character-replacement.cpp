class Solution {
public:
    int characterReplacement(string s, int k) {
        int high = 0;
        int low = 0;
        int res = 0;

        int f[256] = {0};

        for (high = 0; high < s.size(); high++) {

            f[s[high]]++;

            int len = high - low + 1;

            int maxInt = 0;
            for (int i = 0; i < 256; i++) {
                maxInt = max(maxInt, f[i]);
            }

            int diff = len - maxInt;

            while (diff > k) {

                f[s[low]]--;
                low++;

                len = high - low + 1;

                maxInt = 0;
                for (int i = 0; i < 256; i++) {
                    maxInt = max(maxInt, f[i]);
                }

                diff = len - maxInt;
            }

            res = max(res, high - low + 1);
        }

        return res;
    }
};