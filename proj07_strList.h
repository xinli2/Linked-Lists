#ifndef __PROJ07_STRLIST_H__INCLUDED__
#define __PROJ07_STRLIST_H__INCLUDED__

typedef struct StrList StrList;
struct StrList
{
	char    str[50];
	StrList *next;
};



char    *readLongStr(         FILE*);
StrList *readInput  (         FILE*);
int      getLen     (StrList*);
void     writeOutput(StrList*,FILE*);
void     freeList   (StrList*);


#endif
