#include <stdio.h>
#include <string.h>
#include "structure.h"
#define N_ENTRIES 100
CONTACT formFill(char last[], int code)
{
	CONTACT rval;
	strcpy(rval.lastname, last);
	rval.areaCode = code;
	return rval;
}
void printbook(CONTACT book[], int nentries)
{
	int i;
	for (i = 0; i < nentries; i++)
		printf("book[%d](lastname,areaCode) (%s,%d)\n",i,
			book[i].lastname, book[i].areaCode);
}
/* This does NOT modify the form of the caller */
void modifyForm(CONTACT form, char last[], int code)
{
	form = formFill(last,code);
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
	printf("(Improperly) Modify entry 1\n");
	modifyForm(phonebook[1], "Smith", 619);
	printbook(phonebook,3);
}

