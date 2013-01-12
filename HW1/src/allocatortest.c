#include "allocator.h"
#include <stdio.h>

int main(int argc, char** argv) {
	init_arena();
	char * test_array_1 = (char*)allocate(25);
	printf("%zd\n" ,(size_t)test_array_1);
	char * test_array_2 = (char*)allocate(25);
	printf("%zd\n" ,(size_t)test_array_2);

	deallocate(test_array_1);
	deallocate(test_array_2);
	return 0;
}
