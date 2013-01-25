/*
  CSS 343 HW1
  Jay Hennen
  wordcount.cpp
  1/17/2013
*/

#include "list.h"
#include "allocator.h"
#include <string.h>

#define MAX_LEN 128
#define OPT_LOC 0	//option index in input string
#define STR_LOC 2	//string begin index in input string

struct ListNode {
	struct ListNode* next;
	int count;
	char data[0];
};

typedef struct ListNode ListNode;

ListNode* increment(ListNode* current, char* in_buffer);
ListNode* decrement(ListNode* current, char* in_buffer);
ListNode* locate(ListNode* current, char* in_buffer);


int main() {
	init_arena();
	ListNode* current = NULL;
	char in_buffer[MAX_LEN] = {0};
	while(fgets(in_buffer,MAX_LEN,stdin)) {
		char opt;
		char* word;
		unsigned i;

		for (i= 0; i < strlen(in_buffer);i++) // quick loop to cut the \n off
					if (in_buffer[i]=='\n')   // fgets i never asked for this
						in_buffer[i]='\0';

		if (strlen(in_buffer) < 3 || in_buffer[1] != ' ' ||
				(in_buffer[0] != 'a'&& in_buffer[0] != 'd')) {
			fprintf(stderr,"Input was not formatted properly!\n");
			exit (EXIT_FAILURE);
		}
		opt = in_buffer[OPT_LOC];
		word = &in_buffer[STR_LOC];
		if (opt == 'a') {
			current = increment(current, word);
		}
		if (opt == 'd') {
			current = decrement(current, word);
		}
	}
	ListNode * end = current;
	do {
		current = print(current);

	} while (current != end);
    return 0;
}

// Increments the count of the node containing 'word'. If word not found, creates
// node containing 'word'.
ListNode* increment(ListNode* current, char* word) {
	if (current == NULL) {
		current = (ListNode*)allocate(sizeof(ListNode) + strlen(word) +1);
		current->next = current;
		strcpy(current->data,word);
		current->count = 1;
		return current;
	}
	current = locate(current, word);
	if (strcmp(current->next->data, word) == 0) { //word was found, increment count
		current->next->count++;
	} else {							  //word not found, append new entry
		append(current, word);
	}
	return current;
}

// Decrements the count of the node containing 'word'. If count goes to 0,
// node is deleted. If node not found, exit with an error
ListNode* decrement(ListNode* current, char* word) {
	if (current == NULL) {
		fprintf(stderr,"Trying to decrement an empty list!\n");
		exit (EXIT_FAILURE);
	}
	current = locate(current, word);
		if (strcmp(current->next->data, word) == 0) { //word was found, decrement count
			current->next->count--;
			if (current->next->count == 0) {
				current = del(current);
			}
		} else {							  //word not found, append new entry
			fprintf(stderr,"Tried to decrement a word without an entry\n");
			exit (EXIT_FAILURE);
		}
		return current;
}

// Locates the node before the search parameter 'word'
// Note that this may be the node itself, if list has 1 element
// If word is not found, current is unchanged
ListNode* locate(ListNode* current, char* word) {
	if (current == NULL) {
		fprintf(stderr, "Tried to locate in empty list\n");
		exit (EXIT_FAILURE);
	}

	ListNode* end = current->next;
	do {
		if(strcmp(word, current->next->data) == 0)
			return current;
		current = current->next;
	} while(current->next != end);
	return current;
}
