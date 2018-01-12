/** @file 
 * \brief  Print Command-line arguments 
 * \author Philip Papadopoulos
 * \email ppapadopoulos@ucsd.edu
 * \date 11 Jan 2018
*/
#include <stdio.h>
/**
 * \fn int main(int argc, char *argv[])
 * \param argc - number of command-line arguments 
 * \param argv - string representations of arguments (
 */
#include <stdio.h>
int main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < argc; i++)
		printf("argv[%d]:'%s'\n",i, argv[i]);
}
