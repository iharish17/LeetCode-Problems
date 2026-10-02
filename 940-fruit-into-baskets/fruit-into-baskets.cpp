class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> f;

        int low = 0;
        int high = 0;
        int res = 0;

        for (high = 0; high < fruits.size(); high++) {
            f[fruits[high]]++;

            while (f.size() > 2) {
                f[fruits[low]]--;

                if (f[fruits[low]] == 0) {
                    f.erase(fruits[low]);
                }
                low++;
            }

            int len = high - low + 1;
            res = max(len, res);
        }

        return res;
    }
};