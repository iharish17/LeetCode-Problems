
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        for (char c : t) {
            freq[c]++;
        }

        int low = 0;
        int high = 0;
        int required = t.size();
        int minLen = INT_MAX;
        int start = 0;

        for (high = 0; high < s.size(); high++) {

            if (freq[s[high]] > 0) {
                required--;
            }

            freq[s[high]]--;

            while (required == 0) {

                if (high - low + 1 < minLen) {
                    minLen = high - low + 1;
                    start = low;
                }

                freq[s[low]]++;

                if (freq[s[low]] > 0) {
                    required++;
                }

                low++;
            }
        }

        return minLen == INT_MAX
            ? ""
            : s.substr(start, minLen);
    }
};
