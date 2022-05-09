#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

void listDir(DIR *dir, int listAll)
{
    struct dirent *dirFile = (struct dirent *)malloc(sizeof(struct dirent));

    while ((dirFile = readdir(dir)) != NULL)
    {
        if (!listAll && dirFile->d_name[0] == '.')
        {
            continue;
        }
        printf("%s\t", dirFile->d_name);
    }
    printf("\n");

    free(dirFile);
}

int main(int argc, char *argv[])
{
    int flag = getopt(argc, argv, "a");
    char *dirname = ((argc == 1 || argv[1][0] == '-') ? "." : argv[1]);

    DIR *dir = opendir(dirname);

    if (dir == NULL)
    {
        perror(dirname);
        exit(EXIT_FAILURE);
    }
    else
    {
        switch (flag)
        {
        case 'a':
            listDir(dir, 1);
            break;

        case '?':
            exit(EXIT_FAILURE);

        default:
            listDir(dir, 0);
            break;
        }
    }
    return EXIT_SUCCESS;
}
