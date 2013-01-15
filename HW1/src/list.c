#include "list.h"
#include <string.h>

ListNode* new_node(char* data);

// Add new node after current and return new node.
ListNode* append(ListNode* current, char * data) {
	ListNode* new = new_node(data);
	new->next = current->next;
	current->next = new;
	return current;
}


// Delete next node (not current), returning current node (or NULL if
// the list only had a single element).
ListNode* del(ListNode* current) {
	if (current->next == current)
		return NULL;
	ListNode* temp = current->next;
	current->next = temp->next;
	deallocate(temp);
	return current;
}


// Advance to next node.  Return NULL if list is empty.
ListNode* next(ListNode* current) {
	if (current->next == current)
		return NULL;
	return current->next;
}


// Print current node and advance.
ListNode* print(ListNode* current) {
	printf("%s",current->data);
	return current->next;
}


// Print length to stdout.
void print_length(ListNode* current) {
	printf("%d", strlen(current->data));
}


// Print list to stderr (for debugging).
void dump_list(ListNode* current) {}

ListNode* new_node(char* word) {
	ListNode* new = (ListNode*)allocate(sizeof(ListNode) + strlen(word) +1);
	new->next = NULL;
	new->count = 1;
	strncpy(new->data,word,strlen(word));
	return new;
}
