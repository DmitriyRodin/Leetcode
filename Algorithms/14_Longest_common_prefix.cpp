/*
14. Longest Common Prefix
------------------------------
Difficulty level: Easy
------------------------------
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
------------------------------
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
------------------------------
Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
===============================
Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/
#include <cassert>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        for (size_t index = 0; index < strs[0].size(); ++index) {
            char character = strs[0][index];

            for (size_t word = 1; word < strs.size(); ++word) {
                if (index == strs[word].size() || strs[word][index] != character) {
                    return strs[0].substr(0, index);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    Solution x;
	{
		std::vector<std::string> input{"car", "cadrfsdfsdf", "csd"};
	    assert("c" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{"car", "cadrfsdfsdf", "caasd"};
	    assert("ca" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{"car", "cadrfsdfsdf", "bcsd"};
	    assert("" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{"car", "cart", "car"};
	    assert("car" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{"car", "car", "car"};
	    assert("car" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{"single"};
	    assert("single" == x.longestCommonPrefix(input));
	}


	{
	    std::vector<std::string> input{"", "b", "c"};
	    assert("" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{"", "", ""};
	    assert("" == x.longestCommonPrefix(input));
	}

    {
	    std::vector<std::string> input{"interview", "inter", "internal"};
	    assert("inter" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{"apple", "banana", "cherry"};
	    assert("" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{"dog", "door", "dark"};
	    assert("d" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{"test", "test", "test"};
	    assert("test" == x.longestCommonPrefix(input));
	}

    {
	    std::vector<std::string> input{"ab", "abc", "abcd"};
	    assert("ab" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{"flower", "flow", "flight"};
	    assert("fl" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{" space", " span", " speed"};
	    assert(" sp" == x.longestCommonPrefix(input));
	}

	{
	    std::vector<std::string> input{"abc", "axc"};
	    assert("a" == x.longestCommonPrefix(input));
	}

    return 0;
}
