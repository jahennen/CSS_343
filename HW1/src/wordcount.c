#include "list.h"
#include "allocator.h"
#include <string.h>

#define MAX_LEN 128

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
	while(1) {
		char in_buffer[MAX_LEN] = {0};
		char opt;
		char* word;
		//printf("Type 'a' or 'd' then a space, followed by a word\n");
		//printf("Like this: 'a hello'\n");
		fgets(in_buffer,MAX_LEN,stdin);
		int i;
		for (i= 0; i < strlen(in_buffer);i++) // quick loop to cut the \n off
					if (in_buffer[i]=='\n')   // fgets i never asked for this
						in_buffer[i]='\0';
		if (strlen(in_buffer) < 3 || in_buffer[1] != ' ' ||
				(in_buffer[0] != 'a'&& in_buffer[0] != 'd' && in_buffer[0] != 'q' )) {
			fprintf(stderr,"Input was not formatted properly!\n");
			continue;
		}
		//printf("You typed: %s \n", in_buffer);
		opt = in_buffer[0];
		word = &in_buffer[2];
		//printf("Length of word: %d\n", strlen(word));
		if (opt == 'q')
			return 0;
		if (opt == 'a') {
			current = increment(current, word);
		}
		if (opt == 'd') {
			current = decrement(current, word);
		}
		dump_list(current);
		//printf("\n");
	}
    return 0;
}

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
		ListNode* temp = append(current, word);
	}
	return current;
}
ListNode* decrement(ListNode* current, char* word) {
	if (current == NULL) {
		fprintf(stderr,"Trying to decrement an empty list!\n");
		return current;
	}
	current = locate(current, word);
		if (strcmp(current->next->data, word) == 0) { //word was found, decrement count
			current->next->count--;
			if (current->next->count == 0) {
				current = del(current);
			}
		} else {							  //word not found, append new entry
			fprintf(stderr,"Tried to decrement a word without an entry\n");
		}
		return current;
}

// Locates the node before the search parameter 'word'
// Note that this may be the node itself, if list has 1 element
ListNode* locate(ListNode* current, char* word) {
	if (current == NULL) {
		fprintf(stderr, "Tried to locate in empty list\n");
		return current;
	}
	ListNode* end = current;
	do {
		if(strcmp(word, current->next->data) == 0)
			return current;
		current = current->next;
	} while(current != end);
	fprintf(stderr, "Word %s not found\n", word);
	return current;
}
