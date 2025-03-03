#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans;
        ListNode *currentNode1 = l1;
        ListNode *currentNode2 = l2;
        ListNode *currentAnsNode;
        int carryForward;

        currentAnsNode = ans = new ListNode((currentNode1->val + currentNode2->val) % 10);
        carryForward = (currentNode1->val + currentNode2->val) / 10;

        while (currentNode1->next != nullptr && currentNode2->next != nullptr)
        {
            currentNode1 = currentNode1->next;
            currentNode2 = currentNode2->next;
            int tempSum = currentNode1->val + currentNode2->val;

            currentAnsNode->next = new ListNode((tempSum + carryForward) % 10);
            carryForward = (tempSum + carryForward) / 10;
            currentAnsNode = currentAnsNode->next;
        }

        while (currentNode1->next != nullptr)
        {
            currentNode1 = currentNode1->next;
            int tempSum = currentNode1->val;

            currentAnsNode->next = new ListNode((tempSum + carryForward) % 10);
            carryForward = (tempSum + carryForward) / 10;
            currentAnsNode = currentAnsNode->next;
        }

        while (currentNode2->next != nullptr)
        {
            currentNode2 = currentNode2->next;
            int tempSum = currentNode2->val;

            currentAnsNode->next = new ListNode((tempSum + carryForward) % 10);
            carryForward = (tempSum + carryForward) / 10;
            currentAnsNode = currentAnsNode->next;
        }

        if (carryForward > 0)
            currentAnsNode->next = new ListNode(carryForward);

        return ans;
    }
};

int main()
{
    Solution sln = Solution();
}