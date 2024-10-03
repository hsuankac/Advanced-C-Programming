#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void convertCase(FILE* fptr, const char *path);

int main(int argc, char * argv[])
{
    FILE *fpt = NULL;
    char path[100];

    printf("Enter path of source file: ");
    scanf("%s", path);

    fpt = fopen(path, "r");

    if(fpt == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read priviledge");
        exit(EXIT_FAILURE);
    }

    convertCase(fpt, path);
    return 0;
}

void convertCase(FILE* fptr, const char *path)
{
    FILE *dest = NULL;
    char ch = '\0';

    // Temporary file to store result
    dest = fopen("temp.txt", "w");

    if(dest == NULL)
    {
        printf("Unable to create temporary file.");
        fclose(fptr);
        exit(EXIT_FAILURE);
    }
    while((ch = fgetc(fptr)) != EOF)
    {
        // If current character is uppercase then toggle it to lowercase and vice versa

        if(isupper(ch))
            ch = tolower(ch);
        else if(islower(ch))
            ch = toupper(ch);
        
        fputc(ch, dest);
    }
    fclose(fptr);
    fclose(dest);

    remove(path);

    rename("temp.txt", path);

}