#include "list.h"

int main() {
	ListNode* root = (ListNode*)allocate(sizeof(ListNode));
	root->next = root;
	root->count = 0;
	char opt = 'a';
	char temp[10];
	scanf("%c %10s", &opt, &temp);
	printf("%c %s", opt, temp);
    return 0;
}
