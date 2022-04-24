#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256


int outFullFile(FILE *stream)
{
	char *line = (char *)calloc(BUFFER_SIZE, sizeof(char));

	while (fgets(line, BUFFER_SIZE, stream) != NULL)
	{
		printf("%s", line);
	}
	free(line);

	return 0;
}


int main(int argc, char *argv[])
{
	char *filename = argv[1];
	FILE *stream;

	stream = fopen(filename, "r");

	if (stream == NULL)
	{
		perror(filename);
		exit(0);
	}
	else
	{
		outFullFile(stream);
	}
	fclose(stream);

	return 0;		
}
