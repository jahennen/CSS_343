#include "allocator.h"

struct free_node* root;
char Arena[ARENA_SIZE];

// A requested block
#define PAD_SIZE 32

struct free_node {
  size_t size;
  struct free_node* next;
};

void init_arena() {
	root = (struct free_node*)Arena;
	root->size = 0;
	struct free_node * node1 = (struct free_node*)(root+sizeof(struct free_node));
	node1->size = ARENA_SIZE-2*sizeof(struct free_node);
	node1->next = NULL;
	root->next = node1;
}

void* cutnode(struct free_node * current, size_t size);

// Allocate or die.  Returns an aligned memory address.
/* Returns a pointer to a block of storage that is at least as big as the given
 *  size_t variable. The block of storage will have a size that is a multiple
 *  of 8. Returns NULL if request cannot be completed or if requested size
 *  is less than or equal to zero.  */
void* allocate(size_t request) {
	size_t hdr = sizeof(struct free_node);  // the size of one free_node's header
	struct free_node* current;              // free_node pointer to traverse freelist

	// Check valid size request
	if (request <= 0) {
		fprintf(stderr,"Must pass non-zero or non-negative size_t to allocate()\n");
		return NULL;
	}

	// Pad size to a multiple of 8, if necessary
	if (request % 8 != 0)
		request += 8 - request % 8;
	printf("%zd\n",request);
	current = root;
	while (current) {
		printf("%p\n",current);
	    // the next block in freelist is within PAD_SIZE of request, return pointer to it
	    if (current->next && (current->next->size-request<=PAD_SIZE)) {
	      void * mem = (void*)current->next + hdr;
	      current->next = current->next->next;
	      return mem;
	    }

	    // the current block in freelist is large enough, create new node at the end of the block
	    if (current->size > request) {
	      return cutnode(current,request);
	    }

	    // no block big enough, throw error
	    if (current->next==NULL) {
	    	fprintf(stderr,"No block big enough!");
	    	return NULL;
	    }
	    current = current->next;
	  }
	return NULL; // Should never reach here
	}


// Deallocation: parameter is a pointer returned by allocate() or Bad
// Things could happen.
void deallocate(void * mem){

}

/* Takes the given current block and uses the bottom of it to create a new block of memory. A pointer to this new block of memory is returned.  */
void* cutnode(struct free_node * current, size_t size) {
  // create new free_node with given size at bottom of current block, and adjust size fields for both nodes.
  struct free_node * node = (struct free_node*)((size_t)current+current->size-size);
  node->size = size;
  current->size -= size+sizeof(struct free_node);
  // create pointer to new node, header bytes offset from node
  void * mem = (void*)node + sizeof(struct free_node);
  return mem;
}
