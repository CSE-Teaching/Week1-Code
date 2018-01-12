/* Phonebook structure header file */
#define MAXSTR 25
typedef struct contact
{
	char lastname[MAXSTR];
	char firstname[MAXSTR];
	int areaCode;
	int phoneNumber;
	void (*print)(struct contact *);  /* pointer to func that prints */
} CONTACT;

/* prototype declarations */
void formFill(CONTACT * this, char last[], int code);
void printbook(CONTACT book[], int nentries);

