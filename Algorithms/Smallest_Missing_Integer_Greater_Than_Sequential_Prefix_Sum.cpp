/*
2996. Smallest Missing Integer Greater Than Sequential Prefix Sum


Easy

You are given a 0-indexed array of integers nums.

A prefix nums[0..i] is sequential if, for all 1 <= j <= i,
nums[j] = nums[j - 1] + 1. In particular, the prefix consisting
only of nums[0] is sequential.

Return the smallest integer x missing from nums such that x
is greater than or equal to the sum of the longest sequential prefix.
-------------------------------
Example 1:

Input: nums = [1,2,3,2,5]
Output: 6
Explanation: The longest sequential prefix of nums is [1,2,3]
with a sum of 6. 6 is not in the array, therefore 6 is the
smallest missing integer greater than or equal to the sum
of the longest sequential prefix.
-------------------------
Example 2:

Input: nums = [3,4,5,1,12,14,13]
Output: 15
Explanation: The longest sequential prefix of nums
is [3,4,5] with a sum of 12. 12, 13, and 14 belong
to the array while 15 does not. Therefore 15 is the
smallest missing integer greater than or equal to the sum
of the longest sequential prefix.
=========================
Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50

*/

#include <vector>
#include <unordered_set>
#include <cassert>

class Solution {
public:
    int smallestMissingInteger(std::vector<int>& nums) {
        int prefixSum = nums[0];

       for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            } else {
                break;
            }
        }

        std::unordered_set<int> st(nums.begin(), nums.end());

        int x = prefixSum;
        while (st.count(x)) {
            ++x;
        }

        return x;
    }
};

int main() {
    Solution solution;

    std::vector<int> v1{1};
    assert(solution.smallestMissingInteger(v1) == 2);

    std::vector<int> v2{1,2,3};
    assert(solution.smallestMissingInteger(v2) == 6);

    std::vector<int> v3{1,2,3,2,5};
    assert(solution.smallestMissingInteger(v3) == 6);
    std::vector<int> v4{3,4,5,1,12,14,13};
    assert(solution.smallestMissingInteger(v4) == 15);

    std::vector<int> v5{5,1,2,3};
    assert(solution.smallestMissingInteger(v5) == 6);

    std::vector<int> v6{10,5,6};
    assert(solution.smallestMissingInteger(v6) == 11);

    std::vector<int> v7{1,2,3,6,7,8};
    assert(solution.smallestMissingInteger(v7) == 9);
}
