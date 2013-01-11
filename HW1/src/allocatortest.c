#include "allocator.h"
#include <stdio.h>

int main(int argc, char** argv) {
	init_arena();
	char * test_array_1 = (char*)allocate(32);
	char * test_array_2 = (char*)allocate(32);
	printf("%p\n" ,&test_array_1);
	printf("%p\n" ,&test_array_2);
	return 0;
}
