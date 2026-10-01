#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                charStack.push(c);
            }
            else if(charStack.empty()) {
                return false;
            }
            else if ((c == '}' && charStack.top() == '{') || (c == ')' && charStack.top() == '(') || (c == ']' && charStack.top() == '[')) {
                    charStack.pop();
            }
            else {
                break;
            }
        }
        if (charStack.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};