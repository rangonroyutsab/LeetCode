class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<string> v, ans;

        for (int i = 0; i < n; i++)
            v.push_back("(");
        for (int i = 0; i < n; i++)
            v.push_back(")");

        do {
            stack<string> st;
            bool          f = true;
            for (auto x : v) {
                if (x == "(")
                    st.push(x);
                else {
                    if (!st.empty())
                        st.pop();
                    else {
                        f = false;
                        break;
                    }
                }
            }
            if (f and st.empty()) {
                string s = "";
                for (auto x : v) {
                    s.append(x);
                }
                ans.push_back(s);
            }
        } while (next_permutation(v.begin(), v.end()));
        return ans;
    }
};