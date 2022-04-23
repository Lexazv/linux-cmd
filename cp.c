#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
	char *sourceFile = argv[1];
	char *targetFile  = argv[2];

	FILE *sourceStream, *targetStream;

	sourceStream = fopen(sourceFile, "r");
	targetStream = fopen(targetFile, "w");

	if (sourceStream == NULL || targetStream == NULL)
	{
		perror("Error occured");
		exit(EXIT_FAILURE);
	}
	else
	{
		char ch;

		while ((ch = fgetc(sourceStream)) != EOF)
		{
			fputc(ch, targetStream);
		}
	}
	fclose(sourceStream);
	fclose(targetStream);

	return 0;		
}
