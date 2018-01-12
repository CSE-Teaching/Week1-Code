#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h" 
#define MAXLINE 1024
void usage()
{
	fprintf(stderr, "reverse <filename> \n");
}
int main (int argc, char **argv)
{
	char * fname;
	FILE * rfile;
	char * str;
	char linebuf[MAXLINE];
	SLLIST * list;

	if (argc != 2 )
	{
		usage();
		exit(-1);
	}
	fname = argv[1];

	if (! (rfile = fopen(fname,"r")))
	{
		fprintf(stderr,"Could not open file: %s \n", fname);
		exit(-1);
	}
	
	list = createList();

	while (fgets(linebuf,MAXLINE-1,rfile) != NULL)
	{
		linebuf[MAXLINE-1] = '\0'; // force string termination
		str = malloc(strlen(linebuf)+1);
		strcpy(str,linebuf);
		insertElem(list,str);
	}


	NODE * n;
	n = list -> head;
	while ( (n = n -> link))
		printf("%s",n->elem);
	destroyList(list,TRUE);
}



	
	
