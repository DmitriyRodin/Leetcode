/*
27. Remove Element
--------------------
Easy
--------------------
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.
--------------------------------
Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
-------------------------------
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
===============================
Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

*/
#include <vector>
#include <cassert>
#include <algorithm>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
    int count = 0;
    const int num_size = static_cast<int>(nums.size());
    for (int i = 0; i < num_size; ++i) {
        if (nums[i] != val) {
            nums[count] = nums[i];
            ++count;
        }
    }

    return count;
    }
};

void testing(std::vector<int> nums, int val, int expectedK, std::vector<int> expectedNums) {
    Solution s;
    int count = s.removeElement(nums, val);

    assert(count == expectedK);

    sort(nums.begin(), nums.begin() + count);
    sort(expectedNums.begin(), expectedNums.end());

    for (int i = 0; i < count; ++i) {
        assert(nums[i] == expectedNums[i]);
    }
}

int main() {
    testing({3,2,2,3}, 3, 2, {2,2});
    testing({0,1,2,2,3,0,4,2}, 2, 5, {0,0,1,3,4});
    testing({}, 1, 0, {});
    testing({2,2,2,2}, 2, 0, {});
    testing({1,3,5,7}, 2, 4, {1,3,5,7});
    testing({5}, 5, 0, {});
    testing({5}, 3, 1, {5});
    testing({2,1,3,4}, 2, 3, {1,3,4});
    testing({1,3,4,2}, 2, 3, {1,3,4});
    testing({2,1,2,3,2,4,2}, 2, 3, {1,3,4});
}
