/*
 * CSS 343 HW1
 * Jay Hennen
 * list.cpp
 * 1/17/2013
 */

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
	ListNode* newp = new_node(data);
	newp->next = current->next;
	current->next = newp;
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
	if (current == NULL) {
		fprintf(stderr, "Tried to print empty list\n");
		return current;
	}

	printf("%7d %s\n", current->count, current->data);
	return current->next;
}


// Print length of list to stdout.
void print_length(ListNode* current) {
	if (current == NULL) {
		printf("0");
	}
	int count = 0;
	ListNode* end = current;
	do {
		count++;
		current = current->next;
	} while (end != current);
	printf("%d",count);
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
		fprintf(stderr,"%7d %s\n", current->count, current->data);
		current = current->next;
	} while (current != end);
}

ListNode* new_node(char* word) {
	ListNode* newp = (ListNode*)allocate(sizeof(ListNode) + strlen(word) +1);
	if (newp == NULL) { //Out of memory, die a massive, horrible death
		fprintf(stderr,"OUT OF MEMORY\n");
		exit (EXIT_FAILURE);
	}
	newp->next = NULL;
	newp->count = 1;
	strcpy(newp->data,word);
	return newp;
}
