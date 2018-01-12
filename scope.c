/** @file 
 * \brief Recursive calls in C to demonstrate various static var declarations 
 * \author Philip Papadopoulos
 * \email ppapadopoulos@ucsd.edu
 * \date 11 Jan 2018
*/
#include <stdio.h>
#include <string.h>
#include <alloca.h>

#define MAXINDENT 10
#define INC 10
#define G_INIT 100
#define G_MAX 140
#define GS_INIT 200
#define LS_INIT 300
#define IDENT_STR "---"
int g = G_INIT;   /** global variable, declared outside of every function */
static int gs = GS_INIT; /** variable only available to procedures in this file */


int myfunc(int level)
{
	char *indent; 
	indent = (char *) alloca(MAXINDENT * (strlen(IDENT_STR) * sizeof(char)) + 1);
	indent[0] = '\0';

 	static int ls;	      /* persist data between function calls */
	int a = 1, i, j;      /* automatic variables */

	if (g <= G_INIT )     /* first time through, assigne local static */
		ls = LS_INIT;  

	gs += 2 * INC; 	      /* use the global static  */	

	g += INC;      	      /* use the global  */

	for (i = GS_INIT, j=0; i < gs && j < MAXINDENT; i += 20, j++) 
	{
		strcat(indent,IDENT_STR);
	}
	printf("myfunc (pre):  %s (l,a,g,gs,ls) (%d,%d,%d,%d,%d) \n",indent,level,a,g,gs,ls);
	if (g <  G_MAX)
		myfunc(level + 1);

	printf("myfunc (post): %s (l,a,g,gs,ls) (%d,%d,%d,%d,%d) \n",indent,level, a,g,gs,ls);
	return 0; 
}


/**
 * \fn int main(int argc, char *argv[])
 * \param argc - number of command-line arguments (ignored)
 * \param argv - string representations of arguments (ignored)
 */
int main(int argc, char *argv[])
{
	printf("l= parameter, a = automatic, g=global, gs=global static, ls=local static\n");
	myfunc(0);
}

