#include <iostream>
#include "Link.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

void test1() {
    LinkList L;
    for (int i = 1; i < 11; i++) {
        L.creatList_R(i);
    }
//    L.getElement();

//    L.listInsert(12,20);

//    L.listDelete(10);
//    L.listReplace(11,20);
    L.getElement();
    cout << L.listLocate(3)->data.id << endl;
//    L.getLength();
}

void test2() {

}

bool isPalindrome(string s) {
    if (s.size() == 0) return true;
    string result = "";
    for (auto ch: s) {
        if (ch < 48 || (ch > 57 && ch < 65) || (ch > 90 && ch < 97) || ch > 122) continue;
        if (ch >= 65 && ch <= 90) {
            ch += 32;
        }
        result += ch;
    }
    int n = result.size();
    for (int i = 0; i < n / 2; i++) {
        if (result[i] != result[n - 1 - i]) return false;
    }
    return true;

}

int myAtoi(string s) {
    int total = s.size();
    string result = "";
    bool flag = true;//正号
    int begin = 0;
    for (int i = 0; i < total; i++)//删除空格
    {
        if (s[i] == ' ' && s[i + 1] != ' ') {
            begin = i + 1;
            break;
        } else if (s[i] >= 48 && s[i] <= 57) {
            begin = i;
            break;
        } else if (s[i] != '+' && s[i] != '-' && s[i] != ' ') {
            return 0;
        } else if (s[i] == '+' || s[i] == '-') {
            begin = i;
            break;
        }
    }
    for (int i = begin; i < total; i++) {
        if (s[i] == '+') {
            flag = true;
            begin = i + 1;
            break;
        } else if (s[i] == '-') {
            flag = false;
            begin = i + 1;
            break;
        } else if (s[i] >= 48 && s[i] <= 57) {
            begin = i;
            break;
        } else {
            return 0;
        }
    }

    for (int i = begin; i < total; i++)//读数字
    {
        if (s[i] >= 48 && s[i] <= 57) {
            result += s[i];
        }
        if (s[i] < 48 || s[i] > 57) break;
    }
    total = result.size();
    int sum = 0;
    for (int i = 0; i < total; i++) {
        if (flag && (sum + ((result[i] - 48) * pow(10, total - 1 - i)) >= 2147483647)) {
            sum = 2147483647;
            return sum;
        } else if (!flag && (sum + ((result[i] - 48) * pow(10, total - 1 - i)) >= 2147483648)) {
            sum = -2147483648;
            return sum;
        }

        if (flag)
            sum += ((result[i] - 48) * pow(10, total - 1 - i));
        else
            sum += (-(result[i] - 48) * pow(10, total - 1 - i));

    }

    return sum;

}

string countAndSay(int n) {
    string sentence = "1";
    string result = "1";

    if (n == 1) return result;

    for (int i = 1; i < n; i++) {
        int slow = 0;
        int num = sentence.size();//字符串长度

        result = "";
        while (slow < num) {
            int sum = 0;
            int fast = slow;
            string r = "";
            for (; fast < num; fast++) {
                if (sentence[fast] != sentence[slow]) {
                    break;
                }
                sum++;
            }
            r += char(48 + sum);
            r += sentence[slow];
            slow = fast;
            result += r;
        }

        sentence = result;
    }
    return sentence;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *head , *curr;
    head = curr;
    while( list1 != nullptr && list2 != nullptr)
    {
        ListNode *p = new ListNode;
        if( list1->val <= list2->val)
        {
            p->val = list1->val;
            curr->next = p;
            curr = curr->next;
            list1 = list1->next;
        }
        else
        {
            p->val = list2->val;
            curr->next = p;
            curr = curr->next;
            list2 = list2->next;
        }
    }
    head = head->next;
    return head;
}

int main() {


    return 0;

}