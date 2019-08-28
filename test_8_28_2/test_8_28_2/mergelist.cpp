#define _CRT_SECURE_NO_WARNINGS 1
//�ϲ�������������
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode* l = new ListNode(-1);//����ߵ����ҵĺڰס������ɡ�
		ListNode* ll = l;
		while ((l1 != nullptr) && (l2 != nullptr))
		{
			if (l1->val <= l2->val)
			{
				l->next = l1;
				l1 = l1->next;
			}
			else
			{
				l->next = l2;
				l2 = l2->next;
			}
			l = l->next;

		}
		if (l1 == nullptr)
			l->next = l2;
		else
			l->next = l1;
		return ll->next;

	}
};