#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly.

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
	int offset;
	offset = 0;

	while(y[offset] != '\0')
	{
		x[offset] = y[offset];
		offset++;
	}

	x[offset] = '\0';

}

/*
    Searches the input string `str` for the first instance of the
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c)
{
	int offset;
	offset = 0;

	while(str[offset] != 0){
		if(str[offset] == c) {
			return &str[offset];
		}
	}

	return 0;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`.

    Do not use the `strstr` function from the standard library.

    "Hello, world" "world"
            ^       ^
*/
char *find_string(char *haystack, char *needle)
{
	int offset;
	char *ret_addr;
	int needle_offset;

	offset = 0;
	needle_offset = 0;

	while(haystack[offset] != '\0'){

		if(haystack[offset] == needle[needle_offset]){
			ret_addr = &haystack[offset];

			while(haystack[offset] == needle[needle_offset]) {
				if(needle[offset] == '\0') {
					return ret_addr;
				}

				needle_offset++;
				offset++;
			}

			ret_addr = NULL;
		}

		offset++;
	}

	return 0;
}

/* char *find_string(char *haystack, char *needle) */
/* { */
/* 	char *ret_addr; */

/* 	int offset; */
/* 	int needle_offset; */
/* 	int nlen; */

/* 	offset = 0; */
/* 	needle_offset = 0; */
/* 	nlen = strlen(needle); */

/* 	while(haystack[offset] != '\0'){ */

/* 		if(haystack[offset] == needle[needle_offset]){ */
/* 			ret_addr = &haystack[offset]; */

/* 			while(haystack[offset] == needle[needle_offset] && haystack[offset] != '\0') { */
/* 				needle_offset++; */
/* 				offset++; */
/* 			} */

/* 			if(needle_offset == nlen ) { */
/* 				return ret_addr; */
/* 			} */

/* 			ret_addr = NULL; */
/* 		} */

/* 		offset++; */
/* 	} */

/* 	return 0; */
/* } */


#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
