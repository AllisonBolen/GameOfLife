#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"



/* * * * * * * * * * * * 
 *  * read file
 *   * params: 
 *    *   filename - name of file to read from
 *     *   buffer - id arrray to read contents into
 *      * return: 
 *       *   the size of the file read in, warning: includes the '\n' line bytes 
 *        * * * * * * * * * * * * */
int read_file( char* filename, char **buffer ){
  FILE* in = fopen(filename, "r");

  if (in == NULL){
    printf ("file could not be opened!\n");
    return -1;
  }
  else{
    int sz;
    fseek(in,0L, SEEK_END);
    sz=ftell(in);
    *buffer = malloc(sz * sizeof(char));
    rewind(in);
    fread(*buffer,sz,1,in);
    return sz;
   }
  return 0; 
 }

/* * * * * * * * * * * *
 *  * write file
 *   * params:
 *    *   filename - name of file to read from
 *     *   buffer - id arrray to read contents into
 *      *   size -  the size to loop to for the file to be read completely
 *       * return:
 *        *   an int but why?
 *         * * * * * * * * * * * * * */
int write_file( char* filename, char *buffer, int size){
  FILE* out = fopen(filename, "w");
  fwrite(buffer, sizeof(char), size, out);
  fclose(out);
  return 0;
}


