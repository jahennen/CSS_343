#include "allocator.h"

char Arena[ARENA_SIZE];

// A requested block
#define PAD_SIZE 32

// Define the node header
struct Free_node {
	  size_t size;
	  struct Free_node* next;
};

typedef struct Free_node Free_node;

// Declare root node
Free_node* root = NULL;

void init_arena() {
	root = (Free_node*)Arena;
	root->size = 0;
	Free_node * node1 = (Free_node*)((size_t)root+sizeof(Free_node));
	node1->size = ARENA_SIZE-2*sizeof(Free_node);
	node1->next = NULL;
	root->next = node1;
}

void* cutnode(Free_node * current, size_t request);

// Allocate or die.  Returns an aligned memory address.
/* Returns a pointer to a block of storage that is at least as big as the given
 *  size_t variable. The block of storage will have a size that is a multiple
 *  of 8. Returns NULL if request cannot be completed or if requested size
 *  is less than or equal to zero.  */
void* allocate(size_t request) {
	if (root == NULL)
		init_arena();

	size_t hdr = sizeof(Free_node);  // the size of one free_node's header
	Free_node* current;              // free_node pointer to traverse freelist

	// Check valid size request
	if (request <= 0) {
		fprintf(stderr,"Must pass non-zero or non-negative size_t to allocate()\n");
		return NULL;
	}

	// Pad size to a multiple of 8, if necessary
	if (request % 8 != 0)
		request += 8 - request % 8;
	//printf("%zd\n",request);
	current = root;
	while (current) {
		//printf("%p\n",current);
	    // the next block in freelist is within PAD_SIZE of request, return pointer to it
	    if (current->next && (current->next->size-request<=PAD_SIZE)) {
	      void * mem = (void*)current->next + hdr;
	      current->next = current->next->next;
	      return mem;
	    }

	    // the current block in freelist is large enough, create new node at the end of the block
	    if (current->size >= request + hdr) {
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
	if (root + ARENA_SIZE <= mem) {
		die();
	}

	size_t hdr = sizeof(Free_node);
	if (mem == NULL)
		return;

	Free_node* node; // pointer to reference recovered free_node

	// Rebuild free_node using address of p
	node = (Free_node*)((size_t)mem-hdr);

	// Traverse freelist until correct position for current is found.
	Free_node * current;
	current = root;
	while(current) {
		// freed block is between current + size + hdr and current->next
		if ((size_t)current->next > (size_t)node || current->next == NULL) {
			node->next = current->next;
			if (current != node)
				current->next = node;
			break;
		}
		current = current->next;
	}

	// check if freed block is directly after a block in freelist.
	// If it is, sew them together, else move to newly freed block
	if ((size_t)current + current->size + hdr == (size_t)node) {
		// current and newly freed block are contiguous, combine them
		current->size += (hdr + node->size);
		current->next = node->next;
	} else
		current = current->next;

	// check if freed block is between 2 blocks in freelist, IE makes 3 blocks contiguous.
	// If true then sew the current block to the next in the freelist
	if (current && (size_t)current + current->size+hdr == (size_t)current->next) {
		// current and next block are contiguous, combine them
		current->size += (hdr+current->next->size);
		current->next = current->next->next;
	}
}

/* Takes the given current block and uses the bottom of it to create a new block of
 *  memory. A pointer to this new block of memory is returned.  */
void* cutnode(struct Free_node * current, size_t request) {
  // create new free_node with given size at bottom of current block, and adjust size fields for both nodes.
  Free_node * node = (Free_node*)((size_t)current + current->size-request);
  node->size = request;
  current->size -= request + sizeof(Free_node);
  // create pointer to new node, header bytes offset from node
  void * mem = (void*)node + sizeof(Free_node);
  return mem;
}
