Linked list in C: Linked list data structure is very useful and has many advantages. New element can be inserted at the beginning or at the end in a constant time (in doubly linked lists). Memory is utilized efficiently as it is allocated when we add new element to a list and we can increase a list size as desired till all of computer memory is exhausted. Linked lists are useful when size of a list is unknown and changes frequently. Linked list data structure uses node which is represented below. It contains data to be stored and pointer to next node.

struct node {
   int data;
   struct node *next;
};
There are many variants of linked lists such as circular linked list in which last node contains address of first node, doubly linked lists in which every node contains pointers to previous and next nodes and circular doubly linked lists which is a circular doubly linked lists.