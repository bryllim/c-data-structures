#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100



typedef struct{
	char elem[SIZE];
	int count; /*actual number of elements in the array/last element*/
}ArrayList;

int delFirstOccurrence (ArrayList *L, char x);
void displayList(ArrayList L);
void populateList(ArrayList *L);
int delAllOccurrence(ArrayList *L, char elem);
void delDuplicates(ArrayList *L, char elem);

int main()
{
	ArrayList L;
	
	populateList(&L);
	displayList(L);
	int x;
	x = delFirstOccurrence(&L, 'I');
	printf("\n");
	printf("\n");
	printf("%d\n", x);
	displayList(L);
	
	x=delAllOccurrence(&L, 'Z');
	printf("\n");
	displayList(L);
	printf("%d", L.count);
	
	printf("\n");
	printf("\n");
	delDuplicates(&L,'B');
	displayList(L);
	

	
	return 0;
}

void populateList(ArrayList *L){
	int x, i=0;
	for(x=0;x<20;x++, i++){
		L->elem[x] = i+65;
		if(i%4==0){
			i=0;
		}
	}
	L->count = x;
//	printf("%c\n", L->elem[9]);
}

void displayList(ArrayList L){
	int i;
	for(i=0;i<L.count;i++){
		printf("%c ", L.elem[i]);
	}
}

int delFirstOccurrence(ArrayList *L, char elem){
	int ndx, retval;
	retval = -1;
	for(ndx = 0;ndx < L->count && L->elem[ndx]!=elem;ndx++){}
	if(ndx < L->count){
		L->count--;
		memcpy(L->elem+ndx, L->elem+ndx+1, sizeof(char)*(L->count - (ndx)));
		retval = ndx;
	}
	return retval;
}

int delAllOccurrence(ArrayList *L, char elem){
	int ndx, retval;
	retval = 0;
	for(ndx = 0;ndx < L->count; ){
		if(ndx < L->count && L->elem[ndx]==elem){
			retval++;
			L->count--;
			memcpy(L->elem+ndx, L->elem+ndx+1, sizeof(char)*(L->count - (ndx)));
		}else{
			ndx++;
		}
	}
	
	return retval;
}

void delDuplicates(ArrayList *L, char elem){
	int i, j;
	for(i=0;i<L->count;i++){
		for(j=i+1;j<L->count;){
			if(L->elem[i]==L->elem[j]){
				L->count--;
				memcpy(L->elem+j, L->elem+j+1, sizeof(char)*(L->count - j));
			}else{
				j++;
			}
		}
	}
}
