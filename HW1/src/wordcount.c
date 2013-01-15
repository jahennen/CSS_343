#include "list.h"

#define MAX_LEN 128

int main() {
	ListNode* root = NULL;
	char opt = 'a';
	char in_buffer[MAX_LEN];
	while(1) {
		printf("Type 'a' or 'd' then a space, followed by a word\n");
		printf("Like this: 'a hello'\n");
		scanf("%c%4s", &opt, &in_buffer);
		printf("You typed: %c %s \n", opt, in_buffer);
		if (opt == 'q')
			return 0;
	}
	/*
	scanf("%c %10s", &opt, &temp);
	printf("%c %s", opt, temp);*/
    return 0;
}
