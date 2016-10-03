#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void KMPSearch(char *, char *, int *);
void KMPTable(char *, size_t, int *);

int main()
{
	char str[] = "abcxabcdabcdabcyabcdabcy";
	char subString[] = "abcdabcy";
	int strCount = 0;
	KMPSearch(str, subString, &strCount);
	printf("The pattern %s was found %d times\n", subString, strCount);
	return 0;
}

void KMPSearch(char *text, char *pattern, int *strCount)
{
	size_t textLength = strlen(text);
	size_t patternLength = strlen(pattern);

	if(patternLength > textLength || patternLength == 0)
    {
        return ;
    }

	int *table = malloc(sizeof(int) * patternLength);
	size_t i = 0;
	size_t j = 0;

	KMPTable(pattern, patternLength, table);

	while (i < textLength)
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j != 0)
			{
				j = table[j - 1]; // Fall back to the location in the table that has a prefix and start your search from there.
			}
			else
			{
				i++;
			}
		}

		if(j == patternLength)
		{
			(*strCount)++;
			j = 0;
		}
	}

	free(table);
}

void KMPTable(char *pattern, size_t patternLength, int *table)
{
	size_t j = 0;
	size_t i = 1;

	table[0] = 0; /* The first character is always zero because there is no other letter to compare it to.*/

	while(i < patternLength)
	{
	    /*
            This means that we have found a suffix who is also a prefix. With this information in our table, we can figure out
            how far we have to move backwards if we encounter a character that does not match.
        */
		if(pattern[i] == pattern[j])
		{
			table[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if (j != 0)
			{
				j = table[j - 1];
			}
			else
			{
			    /*
                    this means we have not encountered a suffix who also has a prefix. For example, abab has a suffix, ab and
                    a substring that is also a prefix, ab.

                */
				table[i] = 0;
				i++;
			}
		}
	}
}
