#include "multiply.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define BLANK_CHAR 8

static inline int64_t min(const int64_t a, const int64_t b)
{
	return a > b ? b : a;
}

static inline int64_t max(const int64_t a, const int64_t b)
{
	return a > b ? a : b;
}

char* multiply(const char* const first_factor, const char* const second_factor)
{
	const size_t first_factor_len = strlen(first_factor);
	const size_t second_factor_len = strlen(second_factor);
	
	size_t alloc_first_factor_len = first_factor_len;
	size_t alloc_second_factor_len = second_factor_len;
	
	if ((first_factor[0] == '0' && first_factor_len == 1)
		|| (second_factor[0] == '0' && second_factor_len == 1))
	{
		char* const product = malloc(sizeof *product * 3);
		
		if (product == NULL)
		{
			printf("Memory allocation failed.\n");
			
			return NULL;
		}
		else
		{
			product[0] = BLANK_CHAR;
			product[1] = '0';
			product[2] = '\0';
			
			return product;
		}
		
	}
	
	if (first_factor[0] == '-')
	{
		--alloc_first_factor_len;
	}
	
	if (second_factor[0] == '-')
	{
		--alloc_second_factor_len;
	}
	
	char* const product = malloc(sizeof *product * (alloc_first_factor_len + alloc_second_factor_len + 2));
	
	if (product == NULL)
	{
		printf("Memory allocation failed.\n");
		
		return NULL;
	}
	else
	{
		if ((first_factor[0] == '-' || second_factor[0] == '-')
			&& (first_factor[0] != '-' || second_factor[0] != '-'))
		{
			product[0] = '-';
		} else
		{
			product[0] = BLANK_CHAR;
		}
		
		product[alloc_first_factor_len + alloc_second_factor_len + 1] = '\0';
		
		uint64_t carry = 0;
	
		for (uint64_t product_index = 0;
			 product_index <= alloc_first_factor_len + alloc_second_factor_len - 2;
			 ++product_index)
		{
			for (uint64_t second_factor_index = max(0, product_index - alloc_first_factor_len + 1);
				 second_factor_index <= min(product_index, alloc_second_factor_len - 1);
				 ++second_factor_index)
			{
				uint64_t first_factor_index = product_index - second_factor_index;
				carry = carry
						+ ((first_factor[first_factor_len - first_factor_index - 1] - '0')
						   * (second_factor[second_factor_len - second_factor_index - 1] - '0'));
			}
			
			product[alloc_first_factor_len + alloc_second_factor_len - product_index] = carry % 10 + '0';
			carry = carry / 10;
		}
		
		const uint8_t last_digit = carry % 10;
		
		if (last_digit)
		{
			product[1] = last_digit + '0';
		}
		else if (product[0] == '-')
		{
			product[0] = BLANK_CHAR;
			product[1] = '-';
		}
		else
		{
			product[1] = BLANK_CHAR;
		}
		
		return product;
	}
	
}

#undef BLANK_CHAR