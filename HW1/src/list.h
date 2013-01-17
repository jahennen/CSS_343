// list.h
//
// Maintain circular list of strings.


#if !defined(LIST_H)
#define LIST_H

#include "allocator.h"
#include <stdlib.h>

struct ListNode;

// Add new node after current and return new node.
ListNode* append(ListNode* current, char * data);


// Delete next node (not current), returning current node (or NULL if
// the list only had a single element).
ListNode* del(ListNode* current);


// Advance to next node.  Return NULL if list is empty.
ListNode* next(ListNode* current);


// Print current node and advance.
ListNode* print(ListNode* current);


// Print length to stdout.
void print_length(ListNode* current);


// Print list to stderr (for debugging).
void dump_list(ListNode* current);


#endif  // LIST_H
