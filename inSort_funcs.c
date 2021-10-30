#include <stdio.h>
#include <stdlib.h>
#include "proj07_intList.h"

/* this function reads the elements one at a time, 
 * and builds a linked list (sorted) as output.
 */
struct IntList *readInput(FILE* in){
	struct IntList *head;
	head = (struct IntList *)malloc(sizeof(struct IntList));
	head->next = NULL;
	int flag = 0;
	while(!feof(in)){
		int val;
		int ret = fscanf(in, "%d", &val);
		// non-numeric input
		if(ret==0){
			fprintf(stderr, "INPUT ERROR: rc=0.  Terminating the read of the input.\n");
			return head->next;
		}
		// EOF
		if(ret==-1) break;
		struct IntList *curr,*pri;
		pri = head;
		curr = (struct IntList *)malloc(sizeof(struct IntList));
		curr->val = val;
		// build the head of the list
		if(!flag){
			curr->next = head->next;
			head->next = curr;
			flag = 1;
		}
		// insert the input to the list
		else{
			struct IntList *p = head->next;
			// sort the list
			while(p){
				if(curr->val>p->val){
					pri = p;
					p = p->next;
				}
				else{
					curr->next = p;
					pri->next = curr;
					break;
				}
			}
			// if the input is the largest number of the list
			if(!p){
				curr->next = p;
				pri->next = curr;
			}
		}
	}
	struct IntList *list = head->next;
	free(head);
	return list;
}

/* this function gets the length of the list
*/
int getLen(IntList* list){
	struct IntList *p = list;
	int len = 0;
	// traverse
	while(p){
		len++;
		p = p->next;
	}
	free(p);
	return len;
}

/* this function prints out all of the contents of the list.
*/
void writeOutput(IntList* list, FILE* out){
	struct IntList *p = list;
	int i = 0;
	// traverse
	while(p){
		fprintf(out, "%d: %d\n", i, p->val);
		p = p->next;
		i++;
	}
	free(p);
}

/* this function frees the entire list.
*/
void freeList(IntList* list){
	struct IntList *p = list;
	struct IntList *q;
	while(p){
		// store the next node first
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
}
