#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h" 
#define  INITSIZE 64
#define  MAXLINE 1024
void usage()
{
	fprintf(stderr, "reverse <filename> \n");
}
int main (int argc, char *argv[])
{
	unsigned int ui;
	char * fname;
	FILE * rfile;
	char * str;
	char linebuf[MAXLINE];
	char **lines;
	int nlines = 0;
	int capacity =  INITSIZE;

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
	
	lines = malloc(capacity * sizeof (char *));	
	while (fgets(linebuf,MAXLINE-1,rfile) != NULL)
	{
		linebuf[MAXLINE-1] = '\0'; // force string termination
		str = malloc(strlen(linebuf)+1);
		strcpy(str,linebuf);
		if (nlines > capacity)
		{
			capacity *= 2;
			lines=realloc(lines,capacity * sizeof (char *));
		}
		lines[nlines++] = str;
	}

	int i;
	for(i = --nlines; i >= 0; i--)
	{
		printf("%s",lines[i]);
		free(lines[i]);
	}
	
}



	
	
