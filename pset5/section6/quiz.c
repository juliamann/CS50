#include <stdio.h>
#include <cs50.h>


char toupper(char c)
{
	char d = c;
	if (d > 64 && d < 91)
		return d;
	else
		return d - 32;
}

int stringlen(string s)
{
	int length = 0;

	if (s == NULL)
		return 0;

	else
	{
		for (int count = s[0]; count != s['NULL']; count++)
			length++;
	}

	return length;
}

int main(void)
{
	//printf("Give me a word: \n");
	string word = "hello";
	printf("Your word is %s\n", word);

	//stringlen(word);
	printf("The word is %d characters long.\n", stringlen(word));
	return 0;
}