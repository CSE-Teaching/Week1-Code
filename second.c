/** @file 
 * \brief Example of C-preprocessor usage 
 * \author Philip Papadopoulos
 * \email ppapadopoulos@ucsd.edu
 * \date 11 Jan 2018
*/
#include <stdio.h>
/**
 * \def TF(e)
 * \brief Print "True" or "False" of arg (e) using the ternary operator 
 */
#define TF(e) ((e) == 0 ? "False" : "True")

/**
 * \fn int main(int argc, char *argv[])
 * \param argc - number of command-line arguments (ignored)
 * \param argv - string representations of arguments (ignored)
 */
int main(int argc, char *argv[])
{
	int a = 1, b = 2;	
	printf("a = %d -- b = %d\n", a, b );
	printf("a & b = %s -- a && b = %s\n", TF(a & b), TF(a && b) );
	return 0;
}
