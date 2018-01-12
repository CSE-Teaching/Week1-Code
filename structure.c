#include <stdio.h>
#include <string.h>
#define MAXSTR 25
#define N_ENTRIES 100

struct contact
{
	char lastname[MAXSTR];
	char firstname[MAXSTR];
	int areaCode;
	int phoneNumber;
};

int main(int argc, char *argv[])
{
	int i;
	struct contact phonebook[N_ENTRIES];  
	strcpy(phonebook[1].lastname,"Papadopoulos");
	strcpy(phonebook[0].lastname,"Alvarado");
	phonebook[0].areaCode=phonebook[1].areaCode = 858;

	printf("sizeof(struct contact): %d \n", sizeof(struct contact));
	printf("sizeof(phonebook): %d \n", sizeof(phonebook));
	for (i = 0; i <= 1; i++)
		printf("phonebook[%d](lastname,areaCode) (%s,%d)\n",i,
			phonebook[i].lastname, phonebook[i].areaCode);
}

