/*
21. Merge Two Sorted Lists
Easy
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
---------------------------------------------
Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
--------------------------------------------
Example 2:
Input: list1 = [], list2 = []
Output: []
---------------------------------------------
Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
============================================
Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/
#include <cstddef>
#include <vector>
#include <cassert>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }

	    ListNode dummy(0);
	    ListNode* tail = &dummy;

	    while (list1 && list2) {
	        if (list1->val <= list2->val) {
	            tail->next = list1;
	            list1 = list1->next;
	        } else {
	            tail->next = list2;
	            list2 = list2->next;
	        }
	        tail = tail->next;
	    }

	    tail->next = list1 ? list1 : list2;

	    return dummy.next;
	}
};

ListNode* buildList(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(values[0]);
    ListNode* cur = head;

    for (size_t i = 1; i < values.size(); ++i) {
        cur->next = new ListNode(values[i]);
        cur = cur->next;
    }
    return head;
}

std::vector<int> toVector(ListNode* list) {
    std::vector<int> result;
    while(list) {
        result.push_back(list->val);
        list = list->next;
    }
    return result;
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}


int main() {
    Solution solution;
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
	{
	    l1 = buildList({1,3,5,7,9});
        l2 = buildList({});

        ListNode* result = solution.mergeTwoLists(l1,l2);
	    std::vector<int> vec = toVector(result);

	    std::vector<int> correct_answer{1,3,5,7,9};
	    assert(vec == correct_answer);

        freeList(result);

	}

    {
        l1 = buildList({1,2,3,4,5,12});
        l2 = buildList({1,2,3,4,5,7,14,18,25});

        ListNode* list = solution.mergeTwoLists(l1,l2);
        std::vector<int> correct_answer{1,1,2,2,3,3,4,4,5,5,7,12,14,18,25};
        assert(toVector(list) == correct_answer);

        freeList(list);
    }

	{
	    ListNode* l1 = buildList({1,2,4});
	    ListNode* l2 = buildList({1,3,4});

	    ListNode* merged = solution.mergeTwoLists(l1, l2);
	    assert(toVector(merged) == std::vector<int>({1,1,2,3,4,4}));

	    freeList(merged);
	}

	{
	    ListNode* l1 = nullptr;
	    ListNode* l2 = nullptr;

	    ListNode* merged = solution.mergeTwoLists(l1, l2);
	    assert(merged == nullptr);
	}

	{
	    ListNode* l1 = nullptr;
	    ListNode* l2 = buildList({0});

	    ListNode* merged = solution.mergeTwoLists(l1, l2);
	    assert(toVector(merged) == std::vector<int>({0}));

	    freeList(merged);
	}

	{
	    ListNode* l1 = buildList({1,2,3});
	    ListNode* l2 = buildList({4,5,6});

	    ListNode* merged = solution.mergeTwoLists(l1, l2);
	    assert(toVector(merged) == std::vector<int>({1,2,3,4,5,6}));

	    freeList(merged);
	}

	{
	    ListNode* l1 = buildList({-10, -3, 0});
	    ListNode* l2 = buildList({-5, -2, 1});

	    ListNode* merged = solution.mergeTwoLists(l1, l2);
	    assert(toVector(merged) == std::vector<int>({-10,-5,-3,-2,0,1}));

	    freeList(merged);
	}

	{
	    ListNode* l1 = buildList({1});
	    ListNode* l2 = buildList({2});

	    ListNode* merged = solution.mergeTwoLists(l1, l2);
	    assert(toVector(merged) == std::vector<int>({1,2}));

	    freeList(merged);
    }

    return 0;
}
