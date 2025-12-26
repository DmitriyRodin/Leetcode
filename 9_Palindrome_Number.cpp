/*
Easy.
9. Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.
------------------
Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
------------------
Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
-----------------
Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
=================
Constraints:
-231 <= x <= 231 - 1
Follow up: Could you solve it without converting the integer to a string?
*/

#include <cassert>
#include <string>

using std::string;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }

        const std::string x_string = std::to_string(x);
        for (size_t index = 0; index < x_string.size()/2; ++index  ) {
            if (x_string[index] != x_string[x_string.size()-index-1]) {
                return false;
            }
        }
        return true;
    }
};

class Solution2 {	// without converting the integer to a std::string
public:
	bool isPalindrome(const int x) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }
        if (x%10 == 0) {	// the last digit of the number is zero
            return false;
        }

        long long reversed = 0;
        int x_copy = x;
        while (x_copy > 0) {
            reversed = reversed*10 + x_copy % 10;
            x_copy /= 10;
        }
        return (long long)x == reversed;
    }
};

int main() {
    Solution s;

    assert(true == s.isPalindrome(151));
    assert(false == s.isPalindrome(-151));
    assert(true == s.isPalindrome(0));
    assert(false == s.isPalindrome(1511));
    assert(false == s.isPalindrome(10));

    Solution2 s2;

    assert(true == s2.isPalindrome(151));
    assert(false == s2.isPalindrome(-151));
    assert(true == s2.isPalindrome(0));
    assert(false == s2.isPalindrome(1511));
    assert(false == s2.isPalindrome(10));

    return 0;
}
