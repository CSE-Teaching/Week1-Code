#include <stdio.h>
#include <string.h>
#include "structure2.h"
static void printIt(CONTACT * t)
{
	printf("%s (%d)\n", t -> lastname, t -> areaCode);
}
void formFill(CONTACT * t, char last[], int code)
{
	strncpy(t->lastname, last, MAXSTR-1);
	t->lastname[MAXSTR-1] = '\0';
	t->areaCode = code;
	t->print = &printIt;
}
void printbook(CONTACT *book, int nentries)
{
	int i;
	for (i = 0; i < nentries; i++)
	{
		printf("book[%d]lastname,(areaCode):",i);
		book -> print(book);
		book++;
	}
}
/* This does modify the form of the caller */
void modifyForm(CONTACT * form, char last[], int code)
{
	formFill(form, last,code);
}

int main(int argc, char *argv[])
{
	int i;
	CONTACT phonebook[100];  
	formFill(phonebook, "Papadopoulos", 858);
	formFill(phonebook + 1,"Alvarado", 858);
	phonebook[2] = phonebook[1];   /* copy entries */

	printf("sizeof(CONTACT): %d \n", sizeof(CONTACT));
	printf("sizeof(phonebook): %d \n", sizeof(phonebook));
	printbook(phonebook,3);
	
	/* Modify entry 1 last name */
	printf("(properly) Modify entry 1\n");
	modifyForm(phonebook + 1, "Smith", 619);
	printbook(phonebook,3);
}

