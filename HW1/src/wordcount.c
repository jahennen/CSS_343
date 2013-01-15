#include "list.h"
#include "allocator.h"
#include <string.h>

#define MAX_LEN 128

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
		printf("Type 'a' or 'd' then a space, followed by a word\n");
		printf("Like this: 'a hello'\n");
		fgets(in_buffer,MAX_LEN,stdin);
		int i;
		for (i= 0; i < strlen(in_buffer);i++) // quick loop to cut the \n off
					if (in_buffer[i]=='\n')   // fgets i never asked for this
						in_buffer[i]='\0';
		printf("You typed: %s \n", in_buffer);
		opt = in_buffer[0];
		word = &in_buffer[2];
		printf("Length of word: %d\n", strlen(word));
		if (opt == 'q')
			return 0;
		if (opt == 'a') {
			current = increment(current, word);
		}
		if (opt == 'd') {
			current = decrement(current, word);
		}
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

	return current;
}
ListNode* decrement(ListNode* current, char* word) {
	return current;
}
ListNode* locate(ListNode* current, char* word) {
	return current;
}
