#include <stdlib.h>
#include <stdio.h>

FILE *openFile(const char *file){
    FILE *inFile;
    if((inFile = fopen(file, "r")) == NULL){
        fprintf(stderr, "Can not open %s for reading.\n", file);
        exit(EXIT_FAILURE);
    }
    return inFile;
}