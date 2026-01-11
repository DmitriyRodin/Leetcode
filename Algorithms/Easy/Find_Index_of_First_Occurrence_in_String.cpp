/*
28.Find the Index of the First Occurrence in a String
Easy

Given two strings needle and haystack, return the index
of the first occurrence of needle in haystack, or -1 if
 needle is not part of haystack.
--------------------
Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
--------------------
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
=====================
Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/
#include <string>
#include <cassert>

using std::string;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();

        if (nLen > hLen) {
            return -1;
        }

        for (int i = 0; i <= hLen - nLen; ++i) {
            int j = 0;

            while (j < nLen && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == nLen) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    assert(sol.strStr("mybestfriendknowsmeasgoodasmywife", "my") == 0);
    assert(sol.strStr("leetcode_but_not_leetcode", "FF") == -1);
    assert(sol.strStr("helloworldhowAreYou", "ow") == 4);
    assert(sol.strStr("no_fait", "you can do it") == -1);
    assert(sol.strStr("just do it", "do") == 5);
    assert(sol.strStr("travel to Mars", "Mars") == 10);

    return 0;
}
