// allocator.h: simple memory allocator

#if !defined(ALLOCATOR_H)
#define ALLOCATOR_H


#include <stdlib.h>
#include <stdio.h>


#if !defined(ARENA_SIZE)
#define ARENA_SIZE 4096
#endif


// Raw memory for allocation.  This is normally a hidden
// implementation detail.  Exposed here for no good reason.
extern char Arena[];


void init_arena();


// Allocate or die.  Returns an aligned memory address.
void* allocate(size_t request);


// Deallocation: parameter is a pointer returned by allocate() or Bad
// Things could happen.
void deallocate(void * mem);


// Print free list to stderr (for debugging).
void dump_arena();


#endif
