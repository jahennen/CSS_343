#include "list.h"
#include <string.h>

struct ListNode {
	struct ListNode* next;
	int count;
	char data[0];
};

typedef struct ListNode ListNode;

ListNode* new_node(char* data);

// Add new node after current and return new node.
ListNode* append(ListNode* current, char * data) {
	ListNode* new = new_node(data);
	new->next = current->next;
	current->next = new;
	return current->next;
}


// Delete next node (not current), returning current node (or NULL if
// the list only had a single element).
ListNode* del(ListNode* current) {
	if (current->next == current){	//List has a single element so
		deallocate(current);		//Deallocate mem and return NULL
		return NULL;
	}
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
void dump_list(ListNode* current) {
	if (current == NULL) {
		fprintf(stderr, "List is empty!\n");
		return;
	}
	ListNode* end = current;
	fprintf(stderr,"List is as follows:\n");
	do {
		fprintf(stderr,"%s # = %d\n", current->data, current->count);
		current = current->next;
	} while (current != end);
}

ListNode* new_node(char* word) {
	ListNode* new = (ListNode*)allocate(sizeof(ListNode) + strlen(word) +1);
	new->next = NULL;
	new->count = 1;
	strncpy(new->data,word,strlen(word));
	return new;
}
