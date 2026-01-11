/*
20. Valid Parentheses
Easy
Given a string s containing just the characters '(', ')',
'{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
-----------------------------------
Example 1:

Input: s = "()"
Output: true
-----------------------------------
Example 2:

Input: s = "()[]{}"
Output: true
-----------------------------------
Example 3:

Input: s = "(]"
Output: false
----------------------------------
Example 4:

Input: s = "([])"
Output: true
---------------------
Example 5:

Input: s = "([)]"
Output: false
======================
Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
#include <string>
#include <cassert>

using std::string;

class Solution {
public:
    bool isValid(string s) {
        std::string temp;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                temp.push_back(c);
            } else {
                if (temp.empty()) {
                    return false;
                }

                if (c == ')' && temp.back() != '(') {
                    return false;
                }

                if (c == '}' && temp.back() != '{') {
                    return false;
                }

                if (c == ']' && temp.back() != '[') {
                    return false;
                }

                temp.pop_back();
            }
        }

        return temp.empty();
    }
};

int main() {

    Solution sol;

    // Valid Cases
    assert(sol.isValid("()") == true);
    assert(sol.isValid("()[]{}") == true);
    assert(sol.isValid("([])") == true);
    assert(sol.isValid("{{[[(())]]}}") == true);
    assert(sol.isValid("[[{{[[(([]))]]}}]]") == true);

    // Invalid Cases
    assert(sol.isValid("(]") == false);
    assert(sol.isValid("([)]") == false);
    assert(sol.isValid("(") == false);
    assert(sol.isValid(")") == false);
    assert(sol.isValid("(((") == false);
    assert(sol.isValid("]]]") == false);
    assert(sol.isValid("(([]))}") == false);

    // Empty strin
    assert(sol.isValid("") == true);
}
