#include <stdio.h>
#include <conio.h>
#define SENTINEL 9999999

typedef enum {TRUE,FALSE}Boolean;
typedef enum{LEAF,INODE}nodeType;
typedef struct L{
	char name[30];
	unsigned long ID;
}Leaf;

typedef struct node{
	nodeType indicator;
	union{
		Leaf L;
		struct{
			unsigned long key1, key2;
			struct node *ptr[3];
		}Inode;
	}U;
}*TTT, TwoThreeTree;

int main()
{
	TTT S;
	
	return 0;
}

Boolean isMember(TTT S, unsigned long x)
{
	if(S->indicator!=LEAF){
		if(x < S->U.Inode.key1){
			return isMember(S->U.Inode.ptr[0],x);
		}else if(x < S->U.Inode.key2){
			return isMember(S->U.Inode.ptr[1],x);
		}else if(x > S->U.Inode.key2){
			return isMember(S->U.Inode.ptr[2],x);
		}
	}
	
	return S->U.L.ID == x ? TRUE: FALSE;
}
