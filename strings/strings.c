#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of
    characters in the string.

    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
	int offset;
	int str_len;

	str_len = 0;
	offset = 0;

	while(s[offset] != '\0'){
		str_len++;
		offset++;
	}

	return str_len;
}

char *reverse_string(char *rv, char *s)
{
	int str_len;
	int rv_idx;

	rv_idx = 0;
	str_len = string_length(s);

	rv[str_len] = '\0';

	while(1) {
    str_len--;
		rv[rv_idx] = s[str_len];
    rv_idx++;

		if(str_len == 0)
			break;
	}

	return rv;
}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
