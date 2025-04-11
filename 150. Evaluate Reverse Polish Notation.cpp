class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a, b;
        for (string x: tokens) {
            if (x == "+") {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if (x == "-") {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if (x == "*") {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if (x == "/") {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b/a);
            }
            else {
                a = stoi(x);
                s.push(a);
            }
        }
        return s.top();
    }
};