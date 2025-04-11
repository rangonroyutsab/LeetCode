class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> preP(n + 1, 1), sufP(n + 1, 1);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
      preP[i + 1] = nums[i] * preP[i];
    }
    for (int i = 0; i < n; i++) {
      sufP[i + 1] = nums[n - i - 1] * sufP[i];
    }
    int x;
    for (int i = 0; i < n; i++) {
      x = preP[i] * sufP[n - i - 1];
      ans.push_back(x);
    }
    // for (int z: preP) cout << z << " ";
    // cout << endl;
    // for (int z: sufP) cout << z << " ";
    // cout << endl;
    return ans;
  }
};