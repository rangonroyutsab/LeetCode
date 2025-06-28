class Solution {
  public:
    bool isPalindrome(string s) {
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (('a' <= s[i] and s[i] <= 'z') or
                ('0' <= s[i] and s[i] <= '9')) {
                t.push_back(s[i]);
            } else if ('A' <= s[i] and s[i] <= 'Z') {
                t.push_back(s[i] - 'A' + 'a');
            } else {
                continue;
            }
        }
        string r(t.rbegin(), t.rend());
        if (t == r)
            return true;
        return false;
    }
};