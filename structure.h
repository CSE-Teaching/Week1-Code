/* Phonebook structure header file */
typedef struct 
#define MAXSTR 25
{
	char lastname[MAXSTR];
	char firstname[MAXSTR];
	int areaCode;
	int phoneNumber;
} CONTACT;

/* prototype declarations */
CONTACT formFill(char last[], int code);
void printbook(CONTACT book[], int nentries);

