#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
public:
int val;
ListNode* next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    int getLength(ListNode* head) {
        int i = 0;
        while (head) {
            head = head->next;
            i++;
        }
        return i;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = getLength(head);
        if (k == n || n == 0 || n == 1)return head;
        k %= n;
        if (k == 0)return head;
        ListNode* slow = head, * fast = head;
        while (fast && k--) {
            fast = fast->next;
        }
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* newHead = slow->next;
        if (fast != NULL)
        {
            fast->next = head;
            slow->next = NULL;
        }
        return newHead;
    }
};
//class Solution {
//public:
//    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
//        vector<vector<int>> ans;
//        int len = intervals.size();
//        int i = 0;
//        while (i < len && intervals[i][0] <= newInterval[0] &&
//            intervals[i][1] < newInterval[0]) {
//            i++;
//        }
//        if (i == len) {
//            ans.push_back({ start, newInterval[1] });
//            return ans;
//        }
//        int start = min(intervals[i][0], newInterval[0]);
//        int end;
//        while (i < len && intervals[i][1] <= newInterval[1]) {
//            i++;
//        }
//        if (i == len) {
//            ans.push_back({ start, newInterval[1] });
//            return ans;
//        }
//        if (intervals[i][0] <= newInterval[1]) {
//            end = intervals[i][1];
//            i++;
//        }
//        else
//            end = newInterval[1];
//        ans.push_back({ start, end });
//        while (i < len) {
//            ans.push_back(intervals[i]);
//            i++;
//        }
//        return ans;
//    }
//};