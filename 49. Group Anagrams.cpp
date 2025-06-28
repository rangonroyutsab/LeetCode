class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<vector<int>, vector<string>> freq;
        set<vector<int>>                 ss;
        vector<vector<string>>           ans;
        for (string s : strs) {
            vector<int> k(26, 0);
            for (char x : s) {
                k[x - 'a']++;
            }
            ss.insert(k);
            freq[k].push_back(s);
        }
        for (auto x : ss) {
            ans.push_back(freq[x]);
        }
        return ans;
    }
};