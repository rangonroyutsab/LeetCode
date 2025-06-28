class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        stack<int>  freq[100005];
        vector<int> ans, cnt(20005, 0);

        int i = 0, j = 0, x = 0;
        int n = nums.size();

        for (int z : nums) {
            cnt[z + 10001]++;
        }

        for (i = 0; i < 20005; i++) {
            if (cnt[i] > 0) {
                freq[cnt[i]].push(i - 10001);
            }
        }

        for (i = 100001; i >= 0 && k > 0; i--) {
            while (k > 0 && !freq[i].empty()) {
                ans.push_back(freq[i].top());
                freq[i].pop();
                k--;
            }
        }
        return ans;
    }
};