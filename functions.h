#ifndef H_FUNCTIONS
#define H_FUNCTIONS

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);
int makeBoard(char **array, int r, int c);
#endif
