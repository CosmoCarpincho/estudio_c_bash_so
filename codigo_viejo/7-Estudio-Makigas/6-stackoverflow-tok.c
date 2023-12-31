/* https://stackoverflow.com/questions/12911299/read-csv-file-in-c */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

const char* getfield(char* line, int num)
{
	const char* tok;
	for (tok = strtok(line, ";");
			tok && *tok;
			tok = strtok(NULL, ";\n"))
	{
		if (!--num)
			return tok;
	}
	return NULL;
}

int main()
{
	char line[1024];
    while (fgets(line, 1024, stdin))
	{
		char* tmp = strdup(line);
		printf("Field 3 would be %s\n", getfield(tmp, 3));
		// NOTE strtok clobbers tmp
		free(tmp);
	}
}
