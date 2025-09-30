#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

GLchar *readTextFile( const char *name ) {
    FILE *fp;
    GLchar *content = NULL;
    int count=0;

    if (name == NULL) return NULL; // verify that we were actually given a name
    fp = fopen( name, "rt" );      // attempt to open the file 
    if (fp == NULL ) return NULL;
    fseek (fp, 0, SEEK_END);       
    count = ftell (fp);            // determine the length of the file 
    rewind(fp);                    // same as fseek(fp, 0, SEEK_SET);
    /* allocate a buffer and read the file into it */
    if (count > 0) {
        content = (GLchar *) malloc (sizeof(char) * (count+1));
        if (content != NULL) {
            count = fread (content, sizeof(char), count, fp);
            content[count] = '\0';
        }
    }
    fclose (fp);
    return content;
}
