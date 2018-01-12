#include <stdio.h>
#include <string.h>
#include "structure.h"
#define N_ENTRIES 100

/* Return a filled-out contact structure */ 
CONTACT formFill(char last[], int code)
{
	CONTACT rval;
	strncpy(rval.lastname, last,MAXSTR-1);
	rval.lastname[MAXSTR-1] = '\0';
	rval.areaCode = code;
	return rval;

	/* Note on this return, this is full contact struct, the entire struct is
           returned, NOT a pointer to it! */
}

void printbook(CONTACT book[], int nentries)
{
	int i;
	for (i = 0; i < nentries; i++)
		printf("book[%d](lastname,areaCode) (%s,%d)\n",i,
			book[i].lastname, book[i].areaCode);
}

int main(int argc, char *argv[])
{
	int i;
	CONTACT phonebook[N_ENTRIES];  
	phonebook[0] = formFill("Papadopoulos", 858);
	phonebook[1] = formFill("Alvarado", 858);
	phonebook[2] = phonebook[1];   /* copy entries */

	printf("sizeof(CONTACT): %d \n", sizeof(CONTACT));
	printf("sizeof(phonebook): %d \n", sizeof(phonebook));
	printbook(phonebook,3);
	
	/* Modify entry 2 last name */
	printf("Modify entry 1\n");
	phonebook[1] = formFill("Smith", 619);
	printbook(phonebook,3);
}

