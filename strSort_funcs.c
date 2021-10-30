#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj07_strList.h"

/* this function reads the first element of the file.
 */
char *readLongStr(FILE* in){
	char c;
	int len = 8;
	while((c=fgetc(in))!=EOF){
		while(c=='\n'){
			c = fgetc(in);
		}
		int num = 0;
		// store the first element.
		char *s = (char *)malloc(len*sizeof(char));
		while(c!=EOF&&c>32){
			s[num++] = c;
			// when s is filled, double it.
			if(len==num){
				len *= 2;
				int size = len*sizeof(char);
				char *s2 = (char *)malloc(size);
				memcpy(s2, s, size/2);
				free(s);
				s = s2;
				s2 = NULL;
			}
			c = fgetc(in);
		}
		if(num>0){
			char *str = (char *)malloc(num+1);
			memcpy(str, s, num);
			str[num] = '\0';
			free(s);
			return str;
		}
		free(s);
	}
	return NULL;
}

/* this function reads the elements one at a time, 
 * and builds a linked list (sorted) as output.
 */
struct StrList *readInput(FILE* in){
	char c;
	int len = 8;
	struct StrList *head;
	head = (struct StrList *)malloc(sizeof(struct StrList));
	head->next = NULL;
	int flag = 0;
	while((c=fgetc(in))!=EOF){
		while(c=='\n'){
			c = fgetc(in);
		}
		int num = 0;
		char *s = (char *)malloc(len*sizeof(char));
		while(c!=EOF&&c>32){
			s[num++] = c;
			// when s is filled, double it.
			if(len==num){
				len *= 2;
				int size = len*sizeof(char);
				char *s2 = (char *)malloc(size);
				memcpy(s2, s, size/2);
				free(s);
				s = s2;
				s2 = NULL;
			}
			c = fgetc(in);
		}
		// got a valid element.
		if(num>0){
			struct StrList *curr,*pri;
			pri = head;
			// create a new StrList struct.
			curr = (struct StrList *)malloc(sizeof(struct StrList));
			memcpy(curr->str, s, num);
			curr->str[num] = '\0';
			// build the head of the list.
			if(!flag){
				curr->next = head->next;
				head->next = curr;
				flag = 1;
			}
			// insert the new struct to the list
			else{
				struct StrList *p = head->next;
				while(p){
					if(strcmp(curr->str,p->str)>0){
						pri = p;
						p = p->next;
					}
					else{
						curr->next = p;
						pri->next = curr;
						break;
					}
				}
				if(!p){
					curr->next = p;
					pri->next = curr;
				}
			}
		}
		free(s);
	}
	struct StrList *list = head->next;
	free(head);
	return list;
}

/* this function gets the length of the list
*/
int getLen(StrList* list){
	struct StrList *p = list;
	int len = 0;
	while(p){
		len++;
		p = p->next;
	}
	free(p);
	return len;
}

/* this function prints out all of the contents of the list.
*/
void writeOutput(StrList* list, FILE* out){
	struct StrList *p = list;
	int i = 0;
	while(p){
		fprintf(out, "%d: %s\n", i, p->str);
		p = p->next;
		i++;
	}
	free(p);
}

/* this function frees the entire list.
*/
void freeList(StrList* list){
	struct StrList *p = list;
	struct StrList *q;
	while(p){
		// store the next node first.
		q = p->next;
		free(p);
		p = q;
	}
}
