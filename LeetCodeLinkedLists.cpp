#include <LeetCodeProblems.h"

using namespace std;

//Easy
//Delete Node in a Linked List
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

//Remove Nth Node From End of List
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head->next == NULL)
        return NULL;

    ListNode* temp = new ListNode(0);
    temp->next = head;
    ListNode* first = temp;
    ListNode* second = temp;

    for(int i = 0; i < n + 1; i++)
        first = first->next;

    while(first != NULL) {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;
    return temp->next;
}

//Reverse Linked List
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr != NULL) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

//Merge two sorted lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr && l2 == nullptr)
        return nullptr;
    else if(l1 == nullptr)
        return l2;
    else if(l2 == nullptr)
        return l1;

    ListNode* curr = nullptr;

    if(l1->val <= l2->val) {
        curr = l1;
        l1 = l1->next;
    }
    else {
        curr = l2;
        l2 = l2->next;
    }

    ListNode* head = curr;

    while(l1 != nullptr && l2 != nullptr) {
        if(l1->val <= l2->val) {
            curr->next = l1;
            curr = curr->next;
            l1 = l1->next;
        }
        else if(l1->val > l2->val) {
            curr->next = l2;
            curr = curr->next;
            l2 = l2->next;
        }
    }

    if(l1 == nullptr)
        curr->next = l2;
    else if(l2 == nullptr)
        curr->next = l1;

    return head;
}

//Palindrome linked list
bool isPalindrome(ListNode* head) {
    string str = "";

    while(head != nullptr) {
        str += head->val;
        head = head->next;
    }

    int len = str.size();

    for(int i = 0, j = len - 1; i < j; i++, j--) {
        if(str[i] != str[j])
            return false;
    }

    return true;
}

//Linked List Cycle
bool hasCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr)
        return false;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while(slow != fast) {
        if(slow == nullptr || fast == nullptr)
            return false;

        slow = slow->next;
        fast = fast->next;

        if(fast == nullptr)
            return false;

        fast = fast->next;
    }

    return true;
}

//Medium
//AddTwoNumbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0;
    ListNode* l3 = NULL;
    ListNode** node = &l3;

    while(l1 != NULL || l2 != NULL || sum > 0) {
        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        *node = new ListNode(sum % 10);
        sum /= 10;
        node = &((*node)->next);
    }

    return l3;
}

//Odd Even Linked List
ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr)
        return nullptr;

    ListNode* currOdd = head;
    ListNode* currEven = head->next;
    ListNode* evenHead = currEven;


    while(currEven != nullptr && currEven->next != nullptr) {
        currOdd->next = currEven->next;
        currOdd = currOdd->next;
        currEven->next = currOdd->next;
        currEven = currEven->next;
    }

    currOdd->next = evenHead;

    return head;
}

//Intersection of Two Linked lists
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr || headB == nullptr)
        return nullptr;

    ListNode* bStarter = headA;
    ListNode* aStarter = headB;

    while(bStarter != aStarter) {
        if(bStarter == nullptr)
            bStarter = headB;
        else
            bStarter = bStarter->next;

        if(aStarter == nullptr)
            aStarter = headA;
        else
            aStarter = aStarter->next;
    }

    return bStarter;
}



