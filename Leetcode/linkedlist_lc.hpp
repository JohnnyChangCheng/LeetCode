#include <vector>
#include <limits>
#include <set>
#include <string>
#include <stdlib.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*-------------------------------------------------------------------
Given the head of a linked list and a value x, partition it such that 
all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
----------------------------------------------------------------------*/
class Solution_86 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* greater = NULL, * greater_start = NULL;
        ListNode* smaller = NULL, * smaller_start = NULL;
        if (!head)
            return NULL;
        while (head) {
            if (head->val >= x) {
                if (greater == NULL) {
                    greater = head;
                    greater_start = greater;
                }
                else {
                    greater->next = head;
                    greater = greater->next;
                }
            }
            else if (head->val < x) {
                if (smaller == NULL) {
                    smaller = head;
                    smaller_start = smaller;
                }
                else {
                    smaller->next = head;
                    smaller = smaller->next;
                }

            }
            head = head->next;
        }
        if (smaller)
            smaller->next = greater_start;
        else
            smaller_start = greater_start;
        if (greater)
            greater->next = NULL;
        return smaller_start;

    }
};