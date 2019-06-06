//
// This program computes the multiplication of two large numbers (integers) entered as command line arguments.
// Each number can have any number of digits (up to the maximum length of a CLI argument).
//

#include <stdio.h>
#include <stdlib.h>

#include "multiply.h"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Wrong parameters.\n");
		printf("Usage: multiply <first_factor> <second_factor>\n");
		
		return -1;
	}
	
	char* product = multiply(argv[1], argv[2]);
	
	if (product == NULL)
	{
		printf("Error.\n");
		
		return -1;
	}
	else
	{
		printf("%s\n", product);
		
		free(product);
		product = NULL;
	}
		
	return 0;
}